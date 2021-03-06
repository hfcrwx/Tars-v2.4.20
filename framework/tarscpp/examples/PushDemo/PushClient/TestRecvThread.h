#ifndef __TEST_RECV_THREAD_H
#define __TEST_RECV_THREAD_H

#include "servant/Application.h"

class TestPushCallBack : public ServantProxyCallback {
 public:
  virtual int onDispatch(ReqMessagePtr msg);
};

typedef tars::TC_AutoPtr<TestPushCallBack> TestPushCallBackPtr;

class RecvThread : public TC_Thread, public TC_ThreadLock {
 public:
  RecvThread(int second);

  virtual void run();

 private:
  int _second;
  bool _bTerminate;

  Communicator _comm;

  ServantPrx _prx;
};
#endif
