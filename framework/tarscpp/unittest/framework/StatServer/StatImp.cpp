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

#include "StatImp.h"
#include "StatServer.h"

///////////////////////////////////////////////////////////

thread_local shared_ptr<StatImpThreadData> StatImpThreadData::_data;
size_t StatImpThreadData::_iNo = 0;

///////////////////////////////////////////////////////////
StatImpThreadData::StatImpThreadData() : _iThreadIndex(0) {}

StatImpThreadData *StatImpThreadData::getData() {
  if (_data) {
    return _data.get();
  }

  _data = std::make_shared<StatImpThreadData>();
  _data->_iThreadIndex = _iNo;
  ++_iNo;

  return _data.get();
}

//////////////////////////////////////////////////////////
void StatImp::initialize() {
  StatImpThreadData *td = StatImpThreadData::getData();

  if (td) {
    _threadIndex = td->_iThreadIndex;
  } else {
    _threadIndex = 0;
    TLOGERROR("StatImp::initialize StatImpThreadData::getData error." << endl);
  }
}

///////////////////////////////////////////////////////////
//
int StatImp::reportMicMsg(
    const map<tars::StatMicMsgHead, tars::StatMicMsgBody> &statmsg,
    bool bFromClient, tars::TarsCurrentPtr current) {
  TLOGINFO("report---------------------------------access size:"
           << statmsg.size() << "|bFromClient:" << bFromClient << endl);

  for (map<StatMicMsgHead, StatMicMsgBody>::const_iterator it = statmsg.begin();
       it != statmsg.end(); it++) {
    StatMicMsgHead head = it->first;
    const StatMicMsgBody &body = it->second;

    if (bFromClient) {
      head.masterIp = current->getIp();  //???????????????????????????ip,?????????proxy??????

      head.slaveName = getSlaveName(head.slaveName);
    } else {
      head.slaveIp = current->getIp();  //?????????proxy??????
    }

    string sMasterName = head.masterName;
    string::size_type pos = sMasterName.find("@");
    if (pos != string::npos) {
      head.masterName = sMasterName.substr(0, pos);
      head.tarsVersion = sMasterName.substr(pos + 1);
    }

    map<string, string>::iterator it_vip;
    it_vip = g_app.getVirtualMasterIp().find(getSlaveName(head.slaveName));
    if (it_vip != g_app.getVirtualMasterIp().end()) {
      head.masterIp =
          it_vip->second;  //??? slaveName??????????????????????????????ip????????????????????????
    }

    //????????????info??????????????????????????????????????????
    ostringstream os;
    if (LOG->isNeedLog(TarsRollLogger::INFO_LOG)) {
      os.str("");
      head.displaySimple(os);
      body.displaySimple(os);
    }

    //??????????????????0????????????
    if (body.count == 0 && body.execCount == 0 && body.timeoutCount == 0) {
      TLOGINFO(os.str() << "|zero" << endl);
      continue;
    }

    int iAddHash = addHashMap(head, body);

    TLOGINFO(os.str() << "|" << iAddHash << endl);
  }

  return 0;
}

int StatImp::reportSampleMsg(const vector<StatSampleMsg> &msg,
                             tars::TarsCurrentPtr current) {
  TLOGINFO("sample---------------------------------access size:" << msg.size()
                                                                 << endl);

  for (unsigned i = 0; i < msg.size(); i++) {
    StatSampleMsg sample = msg[i];
    sample.masterIp = current->getIp();

    ostringstream os;
    sample.displaySimple(os);
    FDLOG() << os.str() << endl;
  }

  return 0;
}

///////////////////////////////////////////////////////////
//
int StatImp::addHashMap(const StatMicMsgHead &head,
                        const StatMicMsgBody &body) {
  size_t iIndex = _threadIndex;

  // dump???????????????
  int iBufferIndex = g_app.getSelectBufferIndex();

  map<int, vector<int64_t> > &mBuffer = g_app.getBuffer();
  map<int, vector<int64_t> >::iterator iter = mBuffer.find(iBufferIndex);
  iter->second[iIndex] = TNOW;

  dump2file();

  iBufferIndex = g_app.getSelectBufferIndex();

  string sKey = head.slaveName;
  sKey += head.masterName;
  sKey += head.interfaceName;
  sKey += head.masterIp;
  sKey += head.slaveIp;

  int iHashKey = _hashf(sKey) % g_app.getBuffNum();

  StatHashMap *pHashMap = g_app.getHashMapBuff(iBufferIndex, iHashKey);

  //////////////////////////////////////////////////////////////////////////////////////

  float rate = (pHashMap->getMapHead()._iUsedChunk) * 1.0 /
               pHashMap->allBlockChunkCount();

  if (rate > 0.9) {
    TLOGERROR("StatImp::addHashMap hashmap will full|_iMemSize:"
              << pHashMap->getMapHead()._iMemSize << endl);
    FDLOG("HashMap") << "StatImp::addHashMap hashmap will full|_iMemSize:"
                     << pHashMap->getMapHead()._iMemSize << endl;
    return -1;
  }

  int iRet = pHashMap->add(head, body);
  if (iRet != 0) {
    TLOGDEBUG("StatImp::addHashMap set g_hashmap recourd erro|" << iRet
                                                                << endl);
    return iRet;
  }
  return iRet;
}

///////////////////////////////////////////////////////////
string StatImp::getSlaveName(const string &sSlaveName) { return sSlaveName; }

void StatImp::dump2file() {
  static string g_sDate;
  static string g_sFlag;
  static time_t g_tLastDumpTime = 0;

  time_t tTimeNow = TC_TimeProvider::getInstance()->getNow();
  time_t tTimeInterv = g_app.getInserInterv() * 60;  // second

  if (g_tLastDumpTime == 0) {
    g_app.getTimeInfo(g_tLastDumpTime, g_sDate, g_sFlag);
  }

  if (tTimeNow - g_tLastDumpTime > tTimeInterv) {
    static TC_ThreadLock g_mutex;
    TC_ThreadLock::Lock lock(g_mutex);
    if (tTimeNow - g_tLastDumpTime > tTimeInterv) {
      g_app.getTimeInfo(g_tLastDumpTime, g_sDate, g_sFlag);

      int iSelectBuffer = g_app.getSelectBufferIndex();
      iSelectBuffer = !iSelectBuffer;

      g_app.setSelectBufferIndex(iSelectBuffer);

      TLOGDEBUG("StatImp::dump2file select buffer:"
                << iSelectBuffer << "|TimeInterv:" << tTimeInterv
                << "|now:" << tTimeNow << "|last:" << g_tLastDumpTime << endl);
      FDLOG("CountStat") << "stat ip:" << ServerConfig::LocalIp
                         << "|StatImp::dump2file select buffer:"
                         << iSelectBuffer << "|TimeInterv:" << tTimeInterv
                         << "|now:" << tTimeNow << "|last:" << g_tLastDumpTime
                         << endl;
    }
  }
}
