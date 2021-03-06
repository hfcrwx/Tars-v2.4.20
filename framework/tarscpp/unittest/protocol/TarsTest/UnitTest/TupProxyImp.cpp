/**
 * Tencent is pleased to support the open source community by making Tars
 * available.
 *
 * Copyright (C) 2016THL A29 Limited, a Tencent company. All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use this
 * file except in compliance with the License. You may obtain a copy of the
 * License at
 *
 * https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */

#include "TupProxyImp.h"
#include "servant/Application.h"
#include "tup/Tars.h"
#include "util/tc_config.h"
#include "util/tc_hash_fun.h"
#include "util/tc_http.h"
#include "util/tc_parsepara.h"
// #include "util/tc_atomic.h"
#include "util/tc_base64.h"
//#include "TarsServantName.h"

//////////////////////////////////////////////////////
using namespace std;

//////////////////////////////////////////////////////
std::atomic<int> g_requestId;

//////////////////////////////////////////////////////
TupProxyImp::TupProxyImp() {
  _iNum = 0;
  _pPrx = Application::getCommunicator()->stringToProxy<AServantPrx>(
      "TarsTest.UnitTest.AServantObj@tcp -h 127.0.0.1 -p 10004 -t 60000");
  _prot_tup.responseFunc = ProxyProtocol::tupResponse;

  _pPrx->tars_set_protocol(_prot_tup);
}

TupProxyImp::~TupProxyImp() {}

//////////////////////////////////////////////////////

void TupProxyImp::initialize() {}

void TupProxyImp::destroy() {}

//////////////////////////////////////////////////////

int TupProxyImp::doRequest(TarsCurrentPtr current, vector<char> &response) {
  try {
    const vector<char> &request = current->getRequestBuffer();

    // TC_HttpRequest httpRequest;
    httpRequest.reset();
    bool _isHttpProt = true;

    try {
      // TLOGDEBUG("-------->httpRequest.decode."<<endl);
      if (!httpRequest.decode(&request[0], request.size())) {
        TLOGERROR("http request decode fail." << endl);
      }
    } catch (TC_HttpRequest_Exception &e) {
      _isHttpProt = false;
    }

    if (!_isHttpProt) {
      // TLOGDEBUG("-------->not http."<<endl);
      return doRequest(current, &request[0], request.size());
    }

    string buffer;
    if (httpRequest.isGET())  // get??????
    {
      // TLOGDEBUG("-------->get."<<endl);
      return 0;
    } else  // post??????
    {
      //??????Content-Length??????????????????????????????
      buffer = httpRequest.getContent();
      int contentLength =
          TC_Common::strto<int>(httpRequest.getHeader("Content-Length"), "0");
      // TLOGDEBUG("http request contentLength:" << contentLength << "|buffer
      // length:" << buffer.size() << endl);
      if (contentLength > 0) {
        buffer = buffer.substr(0, contentLength);
      }
    }

    return doRequest(current, buffer.c_str(), buffer.length());
  } catch (exception &ex) {
    current->close();
  } catch (...) {
    current->close();
  }

  return 0;
}

int TupProxyImp::doRequest(const tars::TarsCurrentPtr &current,
                           const char *buffer, size_t length) {
  int ret = 0;

  //??????????????????tup??????
  map<int32_t, RequestPacket *> mTupRequest;
  ret = parseTupRequest(buffer, length, mTupRequest);
  if (ret != 0) {
    LOG->error() << "[TupProxyImp::doRequest] parsetupRequest error." << endl;
    return 0;
  }

  //????????????tup???
  if (mTupRequest.size() == 0) {
    LOG->error() << "[TupProxyImp::doRequest] tup packet empty error." << endl;
    return 0;
  }

  // TLOGDEBUG("-------->TupProxyImp::doRequest."<<endl);
  current->setResponse(false);

  TupCallbackPtr cb = new TupCallback("TupCallback", this, current);

  map<int32_t, RequestPacket *>::const_iterator it = mTupRequest.begin();

  while (it != mTupRequest.end()) {
    // TLOGDEBUG("-------->tupCallback."<<endl);
    //????????????????????????

    tupAsyncCall(it->second, _pPrx, cb);

    ++it;
  }

  return 0;
}

int TupProxyImp::parseTupRequest(const char *buffer, size_t length,
                                 map<int32_t, RequestPacket *> &mTupRequest) {
  mTupRequest.clear();

  size_t pos = 0;

  while (pos < length) {
    //????????????
    if (pos + sizeof(uint32_t) > length) {
      LOG->error() << "[TupProxyImp::parsetupRequest] tup error: " << pos
                   << "+4 > " << length << endl;
      return -1;
    }

    // uint32_t l=0;

    // memcpy(&l, buffer + pos, sizeof(uint32_t));
    uint32_t l = *(static_cast<uint32_t *>((void *)(buffer + pos)));

    l = ntohl(l);

    //????????????
    if ((pos + l) > length) {
      LOG->error() << "[TupProxyImp::parsetupRequest] tup error: " << pos + l
                   << " > " << length << endl;
      return -2;
    }

    if (l <= 4) {
      LOG->error() << "[TupProxyImp::parsetupRequest] tup error: l:" << l
                   << " <= 4 , pos:" << pos << ", length:" << length << endl;
      return -3;
    }

    tars::TarsInputStream<BufferReader> is;
    // innerJceInputStream is;

    is.setBuffer(buffer + pos + 4, l - 4);

    RequestPacket *tup = new RequestPacket();

    tup->readFrom(is);

    //???????????????requestid?????????,??????
    if (mTupRequest.find(tup->iRequestId) != mTupRequest.end()) {
      LOG->error() << "[TupProxyImp::parsetupRequest] requestid '"
                   << tup->iRequestId << "' confict error." << endl;
      return -4;
    }
    pos += l;

    mTupRequest[tup->iRequestId] = tup;
    // TLOGDEBUG("tup.iRequestId:"<<tup.iRequestId<<endl);
  }

  return 0;
}

void TupProxyImp::tupAsyncCall(RequestPacket *tup, const AServantPrx &proxy,
                               const TupCallbackPtr &cb) {
  //????????????requestid, ????????????????????????
  int requestId = ++g_requestId;

  try {
    //??????????????????requestid??????, ??????????????????tup
    int iOldRequestId = tup->iRequestId;
    string sOldServantName = tup->sServantName;

    RequestPacket *newtup = tup;

    // newtup.iVersion = 2;

    //????????????tup requestid
    newtup->iRequestId = requestId;

    //??????TAF?????????ServantName
    newtup->sServantName =
        string(proxy->tars_name().substr(0, proxy->tars_name().find("@")));

    //???????????????????????????
    // newtup.context = "";

    // TLOGDEBUG("-------->RequestPacket: ServantName|" << newtup.sServantName
    // << "|ServantFunc:" << newtup.sFuncName <<endl);

    //????????????
    tars::TarsOutputStream<BufferWriter> buffer;
    // innerJceOutputStream buffer;

    newtup->writeTo(buffer);

    unsigned int bufferlength = buffer.getLength() + 4;
    bufferlength = htonl(bufferlength);

    string s;
    s.reserve(buffer.getLength() + 4);
    s.append((char *)&bufferlength, 4);
    s.append(buffer.getBuffer(), buffer.getLength());

    newtup->iRequestId = iOldRequestId;

    newtup->sServantName = sOldServantName;

    //?????????????????????tup??????
    cb->addtup(requestId, newtup);

    //??????????????????(???requestId hash?????????)
    // TLOGDEBUG("-------->rpc_call_async."<<endl);

    proxy->rpc_call_async(requestId, newtup->sFuncName, s.c_str(), s.length(),
                          cb);

    _iNum++;
    if (_iNum == 100000) {
      LOG->error() << "time:" << std::this_thread::get_id() << "|"
                   << TC_TimeProvider::getInstance()->getNowMs() - _iTime
                   << endl;
      _iTime = TC_TimeProvider::getInstance()->getNowMs();
      _iNum = 0;
    }

  } catch (exception &ex) {
    cb->deltup(requestId);
    LOG->error() << "tupAsyncCall error:" << ex.what() << endl;
  }
}

int TupProxyImp::doResponse(ReqMessagePtr resp) {
  // TLOGDEBUG("-------->TupProxyImp::doResponse."<<endl);
  //(1)?????????????????????server????????????objname???????????????server???resp
  //(2)???????????????server?????????callback???????????????type????????????
  //...
  if (resp->callback->getType() == "TupCallback") {
    TupCallback *cb = dynamic_cast<TupCallback *>(resp->callback.get());

    vector<char> &buff = resp->response->sBuffer;

    if (!buff.empty()) {
      if (resp->response->iVersion == TARSVERSION)  // 1???jce??????
      {
        cb->doResponse_jce(buff);
        // LOG->debug()<<"TupProxyImp::doResponse jce"<<endl;
      } else  // if ( resp->response.iVersion == tupVERSION ||
              // resp->response.iVersion == tupVERSION2  )  //2???3???tup??????
      {
        cb->doResponse_tup(buff);
        // LOG->debug()<<"TupProxyImp::doResponse tup"<<endl;
      }
    }
  }

  return 0;
}
