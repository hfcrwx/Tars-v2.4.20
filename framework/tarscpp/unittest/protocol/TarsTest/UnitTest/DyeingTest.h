// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 2.4.13.
// **********************************************************************

#ifndef __DYEINGTEST_H_
#define __DYEINGTEST_H_

#include <map>
#include <string>
#include <vector>
#include "tup/Tars.h"
#include "tup/TarsJson.h"
using namespace std;
#include "servant/Servant.h"
#include "servant/ServantProxy.h"

namespace TarsTest {

/* callback of async proxy for client */
class DyeingTestPrxCallback : public tars::ServantProxyCallback {
 public:
  virtual ~DyeingTestPrxCallback() {}
  virtual void callback_test(tars::Int32 ret) {
    throw std::runtime_error("callback_test() override incorrect.");
  }
  virtual void callback_test_exception(tars::Int32 ret) {
    throw std::runtime_error("callback_test_exception() override incorrect.");
  }

  virtual void callback_testDyeing(tars::Int32 ret, const std::string &strOut) {
    throw std::runtime_error("callback_testDyeing() override incorrect.");
  }
  virtual void callback_testDyeing_exception(tars::Int32 ret) {
    throw std::runtime_error(
        "callback_testDyeing_exception() override incorrect.");
  }

 public:
  virtual const map<std::string, std::string> &getResponseContext() const {
    CallbackThreadData *pCbtd = CallbackThreadData::getData();
    assert(pCbtd != NULL);

    if (!pCbtd->getContextValid()) {
      throw TC_Exception("cann't get response context");
    }
    return pCbtd->getResponseContext();
  }

 public:
  virtual int onDispatch(tars::ReqMessagePtr msg) {
    static ::std::string __DyeingTest_all[] = {"test", "testDyeing"};
    pair<string *, string *> r = equal_range(
        __DyeingTest_all, __DyeingTest_all + 2, string(msg->request.sFuncName));
    if (r.first == r.second) return tars::TARSSERVERNOFUNCERR;
    switch (r.first - __DyeingTest_all) {
      case 0: {
        if (msg->response->iRet != tars::TARSSERVERSUCCESS) {
          callback_test_exception(msg->response->iRet);

          return msg->response->iRet;
        }
        tars::TarsInputStream<tars::BufferReader> _is;

        _is.setBuffer(msg->response->sBuffer);
        tars::Int32 _ret;
        _is.read(_ret, 0, true);

        CallbackThreadData *pCbtd = CallbackThreadData::getData();
        assert(pCbtd != NULL);

        pCbtd->setResponseContext(msg->response->context);

        callback_test(_ret);

        pCbtd->delResponseContext();

        return tars::TARSSERVERSUCCESS;
      }
      case 1: {
        if (msg->response->iRet != tars::TARSSERVERSUCCESS) {
          callback_testDyeing_exception(msg->response->iRet);

          return msg->response->iRet;
        }
        tars::TarsInputStream<tars::BufferReader> _is;

        _is.setBuffer(msg->response->sBuffer);
        tars::Int32 _ret;
        _is.read(_ret, 0, true);

        std::string strOut;
        _is.read(strOut, 2, true);
        CallbackThreadData *pCbtd = CallbackThreadData::getData();
        assert(pCbtd != NULL);

        pCbtd->setResponseContext(msg->response->context);

        callback_testDyeing(_ret, strOut);

        pCbtd->delResponseContext();

        return tars::TARSSERVERSUCCESS;
      }
    }
    return tars::TARSSERVERNOFUNCERR;
  }
};
typedef tars::TC_AutoPtr<DyeingTestPrxCallback> DyeingTestPrxCallbackPtr;

/* callback of coroutine async proxy for client */
class DyeingTestCoroPrxCallback : public DyeingTestPrxCallback {
 public:
  virtual ~DyeingTestCoroPrxCallback() {}

 public:
  virtual const map<std::string, std::string> &getResponseContext() const {
    return _mRspContext;
  }

  virtual void setResponseContext(
      const map<std::string, std::string> &mContext) {
    _mRspContext = mContext;
  }

 public:
  int onDispatch(tars::ReqMessagePtr msg) {
    static ::std::string __DyeingTest_all[] = {"test", "testDyeing"};

    pair<string *, string *> r = equal_range(
        __DyeingTest_all, __DyeingTest_all + 2, string(msg->request.sFuncName));
    if (r.first == r.second) return tars::TARSSERVERNOFUNCERR;
    switch (r.first - __DyeingTest_all) {
      case 0: {
        if (msg->response->iRet != tars::TARSSERVERSUCCESS) {
          callback_test_exception(msg->response->iRet);

          return msg->response->iRet;
        }
        tars::TarsInputStream<tars::BufferReader> _is;

        _is.setBuffer(msg->response->sBuffer);
        try {
          tars::Int32 _ret;
          _is.read(_ret, 0, true);

          setResponseContext(msg->response->context);

          callback_test(_ret);

        } catch (std::exception &ex) {
          callback_test_exception(tars::TARSCLIENTDECODEERR);

          return tars::TARSCLIENTDECODEERR;
        } catch (...) {
          callback_test_exception(tars::TARSCLIENTDECODEERR);

          return tars::TARSCLIENTDECODEERR;
        }

        return tars::TARSSERVERSUCCESS;
      }
      case 1: {
        if (msg->response->iRet != tars::TARSSERVERSUCCESS) {
          callback_testDyeing_exception(msg->response->iRet);

          return msg->response->iRet;
        }
        tars::TarsInputStream<tars::BufferReader> _is;

        _is.setBuffer(msg->response->sBuffer);
        try {
          tars::Int32 _ret;
          _is.read(_ret, 0, true);

          std::string strOut;
          _is.read(strOut, 2, true);
          setResponseContext(msg->response->context);

          callback_testDyeing(_ret, strOut);

        } catch (std::exception &ex) {
          callback_testDyeing_exception(tars::TARSCLIENTDECODEERR);

          return tars::TARSCLIENTDECODEERR;
        } catch (...) {
          callback_testDyeing_exception(tars::TARSCLIENTDECODEERR);

          return tars::TARSCLIENTDECODEERR;
        }

        return tars::TARSSERVERSUCCESS;
      }
    }
    return tars::TARSSERVERNOFUNCERR;
  }

 protected:
  map<std::string, std::string> _mRspContext;
};
typedef tars::TC_AutoPtr<DyeingTestCoroPrxCallback>
    DyeingTestCoroPrxCallbackPtr;

/* proxy for client */
class DyeingTestProxy : public tars::ServantProxy {
 public:
  typedef map<string, string> TARS_CONTEXT;
  tars::Int32 test(const map<string, string> &context = TARS_CONTEXT(),
                   map<string, string> *pResponseContext = NULL) {
    tars::TarsOutputStream<tars::BufferWriterVector> _os;
    std::map<string, string> _mStatus;
    shared_ptr<tars::ResponsePacket> rep =
        tars_invoke(tars::TARSNORMAL, "test", _os, context, _mStatus);
    if (pResponseContext) {
      pResponseContext->swap(rep->context);
    }

    tars::TarsInputStream<tars::BufferReader> _is;
    _is.setBuffer(rep->sBuffer);
    tars::Int32 _ret;
    _is.read(_ret, 0, true);
    return _ret;
  }

  void async_test(DyeingTestPrxCallbackPtr callback,
                  const map<string, string> &context = TARS_CONTEXT()) {
    tars::TarsOutputStream<tars::BufferWriterVector> _os;
    std::map<string, string> _mStatus;
    tars_invoke_async(tars::TARSNORMAL, "test", _os, context, _mStatus,
                      callback);
  }

  void coro_test(DyeingTestCoroPrxCallbackPtr callback,
                 const map<string, string> &context = TARS_CONTEXT()) {
    tars::TarsOutputStream<tars::BufferWriterVector> _os;
    std::map<string, string> _mStatus;
    tars_invoke_async(tars::TARSNORMAL, "test", _os, context, _mStatus,
                      callback, true);
  }

  tars::Int32 testDyeing(const std::string &strIn, std::string &strOut,
                         const map<string, string> &context = TARS_CONTEXT(),
                         map<string, string> *pResponseContext = NULL) {
    tars::TarsOutputStream<tars::BufferWriterVector> _os;
    _os.write(strIn, 1);
    _os.write(strOut, 2);
    std::map<string, string> _mStatus;
    _mStatus.insert(std::make_pair(ServantProxy::STATUS_GRID_KEY, strIn));
    shared_ptr<tars::ResponsePacket> rep =
        tars_invoke(tars::TARSNORMAL, "testDyeing", _os, context, _mStatus);
    if (pResponseContext) {
      pResponseContext->swap(rep->context);
    }

    tars::TarsInputStream<tars::BufferReader> _is;
    _is.setBuffer(rep->sBuffer);
    tars::Int32 _ret;
    _is.read(_ret, 0, true);
    _is.read(strOut, 2, true);
    return _ret;
  }

  void async_testDyeing(DyeingTestPrxCallbackPtr callback,
                        const std::string &strIn,
                        const map<string, string> &context = TARS_CONTEXT()) {
    tars::TarsOutputStream<tars::BufferWriterVector> _os;
    _os.write(strIn, 1);
    std::map<string, string> _mStatus;
    _mStatus.insert(std::make_pair(ServantProxy::STATUS_GRID_KEY, strIn));
    tars_invoke_async(tars::TARSNORMAL, "testDyeing", _os, context, _mStatus,
                      callback);
  }

  void coro_testDyeing(DyeingTestCoroPrxCallbackPtr callback,
                       const std::string &strIn,
                       const map<string, string> &context = TARS_CONTEXT()) {
    tars::TarsOutputStream<tars::BufferWriterVector> _os;
    _os.write(strIn, 1);
    std::map<string, string> _mStatus;
    _mStatus.insert(std::make_pair(ServantProxy::STATUS_GRID_KEY, strIn));
    tars_invoke_async(tars::TARSNORMAL, "testDyeing", _os, context, _mStatus,
                      callback, true);
  }

  DyeingTestProxy *tars_hash(int64_t key) {
    return (DyeingTestProxy *)ServantProxy::tars_hash(key);
  }

  DyeingTestProxy *tars_consistent_hash(int64_t key) {
    return (DyeingTestProxy *)ServantProxy::tars_consistent_hash(key);
  }

  DyeingTestProxy *tars_set_timeout(int msecond) {
    return (DyeingTestProxy *)ServantProxy::tars_set_timeout(msecond);
  }

  static const char *tars_prxname() { return "DyeingTestProxy"; }
};
typedef tars::TC_AutoPtr<DyeingTestProxy> DyeingTestPrx;

/* servant for server */
class DyeingTest : public tars::Servant {
 public:
  virtual ~DyeingTest() {}
  virtual tars::Int32 test(tars::TarsCurrentPtr current) = 0;
  static void async_response_test(tars::TarsCurrentPtr current,
                                  tars::Int32 _ret) {
    if (current->getRequestVersion() == TUPVERSION) {
      UniAttribute<tars::BufferWriterVector, tars::BufferReader> tarsAttr;
      tarsAttr.setVersion(current->getRequestVersion());
      tarsAttr.put("", _ret);
      tarsAttr.put("tars_ret", _ret);

      vector<char> sTupResponseBuffer;
      tarsAttr.encode(sTupResponseBuffer);
      current->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
    } else if (current->getRequestVersion() == JSONVERSION) {
      tars::JsonValueObjPtr _p = new tars::JsonValueObj();
      _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
      vector<char> sJsonResponseBuffer;
      tars::TC_Json::writeValue(_p, sJsonResponseBuffer);
      current->sendResponse(tars::TARSSERVERSUCCESS, sJsonResponseBuffer);
    } else {
      tars::TarsOutputStream<tars::BufferWriterVector> _os;
      _os.write(_ret, 0);

      current->sendResponse(tars::TARSSERVERSUCCESS, _os.getByteBuffer());
    }
  }

  virtual tars::Int32 testDyeing(const std::string &strIn, std::string &strOut,
                                 tars::TarsCurrentPtr current) = 0;
  static void async_response_testDyeing(tars::TarsCurrentPtr current,
                                        tars::Int32 _ret,
                                        const std::string &strOut) {
    if (current->getRequestVersion() == TUPVERSION) {
      UniAttribute<tars::BufferWriterVector, tars::BufferReader> tarsAttr;
      tarsAttr.setVersion(current->getRequestVersion());
      tarsAttr.put("", _ret);
      tarsAttr.put("tars_ret", _ret);
      tarsAttr.put("strOut", strOut);

      vector<char> sTupResponseBuffer;
      tarsAttr.encode(sTupResponseBuffer);
      current->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
    } else if (current->getRequestVersion() == JSONVERSION) {
      tars::JsonValueObjPtr _p = new tars::JsonValueObj();
      _p->value["strOut"] = tars::JsonOutput::writeJson(strOut);
      _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
      vector<char> sJsonResponseBuffer;
      tars::TC_Json::writeValue(_p, sJsonResponseBuffer);
      current->sendResponse(tars::TARSSERVERSUCCESS, sJsonResponseBuffer);
    } else {
      tars::TarsOutputStream<tars::BufferWriterVector> _os;
      _os.write(_ret, 0);

      _os.write(strOut, 2);

      current->sendResponse(tars::TARSSERVERSUCCESS, _os.getByteBuffer());
    }
  }

 public:
  int onDispatch(tars::TarsCurrentPtr _current,
                 vector<char> &_sResponseBuffer) {
    static ::std::string __TarsTest__DyeingTest_all[] = {"test", "testDyeing"};

    pair<string *, string *> r =
        equal_range(__TarsTest__DyeingTest_all, __TarsTest__DyeingTest_all + 2,
                    _current->getFuncName());
    if (r.first == r.second) return tars::TARSSERVERNOFUNCERR;
    switch (r.first - __TarsTest__DyeingTest_all) {
      case 0: {
        tars::TarsInputStream<tars::BufferReader> _is;
        _is.setBuffer(_current->getRequestBuffer());
        if (_current->getRequestVersion() == TUPVERSION) {
          UniAttribute<tars::BufferWriterVector, tars::BufferReader> tarsAttr;
          tarsAttr.setVersion(_current->getRequestVersion());
          tarsAttr.decode(_current->getRequestBuffer());
        } else if (_current->getRequestVersion() == JSONVERSION) {
          tars::JsonValueObjPtr _jsonPtr = tars::JsonValueObjPtr::dynamicCast(
              tars::TC_Json::getValue(_current->getRequestBuffer()));
        } else {
        }
        tars::Int32 _ret = test(_current);
        if (_current->isResponse()) {
          if (_current->getRequestVersion() == TUPVERSION) {
            UniAttribute<tars::BufferWriterVector, tars::BufferReader> tarsAttr;
            tarsAttr.setVersion(_current->getRequestVersion());
            tarsAttr.put("", _ret);
            tarsAttr.put("tars_ret", _ret);
            tarsAttr.encode(_sResponseBuffer);
          } else if (_current->getRequestVersion() == JSONVERSION) {
            tars::JsonValueObjPtr _p = new tars::JsonValueObj();
            _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
            tars::TC_Json::writeValue(_p, _sResponseBuffer);
          } else {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(_ret, 0);
            _os.swap(_sResponseBuffer);
          }
        }
        return tars::TARSSERVERSUCCESS;
      }
      case 1: {
        tars::TarsInputStream<tars::BufferReader> _is;
        _is.setBuffer(_current->getRequestBuffer());
        std::string strIn;
        std::string strOut;
        if (_current->getRequestVersion() == TUPVERSION) {
          UniAttribute<tars::BufferWriterVector, tars::BufferReader> tarsAttr;
          tarsAttr.setVersion(_current->getRequestVersion());
          tarsAttr.decode(_current->getRequestBuffer());
          tarsAttr.get("strIn", strIn);
          tarsAttr.getByDefault("strOut", strOut, strOut);
        } else if (_current->getRequestVersion() == JSONVERSION) {
          tars::JsonValueObjPtr _jsonPtr = tars::JsonValueObjPtr::dynamicCast(
              tars::TC_Json::getValue(_current->getRequestBuffer()));
          tars::JsonInput::readJson(strIn, _jsonPtr->value["strIn"], true);
          tars::JsonInput::readJson(strOut, _jsonPtr->value["strOut"], false);
        } else {
          _is.read(strIn, 1, true);
          _is.read(strOut, 2, false);
        }
        tars::Int32 _ret = testDyeing(strIn, strOut, _current);
        if (_current->isResponse()) {
          if (_current->getRequestVersion() == TUPVERSION) {
            UniAttribute<tars::BufferWriterVector, tars::BufferReader> tarsAttr;
            tarsAttr.setVersion(_current->getRequestVersion());
            tarsAttr.put("", _ret);
            tarsAttr.put("tars_ret", _ret);
            tarsAttr.put("strOut", strOut);
            tarsAttr.encode(_sResponseBuffer);
          } else if (_current->getRequestVersion() == JSONVERSION) {
            tars::JsonValueObjPtr _p = new tars::JsonValueObj();
            _p->value["strOut"] = tars::JsonOutput::writeJson(strOut);
            _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
            tars::TC_Json::writeValue(_p, _sResponseBuffer);
          } else {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(_ret, 0);
            _os.write(strOut, 2);
            _os.swap(_sResponseBuffer);
          }
        }
        return tars::TARSSERVERSUCCESS;
      }
    }
    return tars::TARSSERVERNOFUNCERR;
  }
};

}  // namespace TarsTest

#endif
