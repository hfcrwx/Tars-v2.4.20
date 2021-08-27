#ifndef _HelloServer_H_
#define _HelloServer_H_

#include <iostream>
#include "servant/Application.h"

using namespace tars;

/**
 * HelloServer继承框架的Application类
 **/
class HelloServer : public Application {
 public:
  /**
   *
   **/
  virtual ~HelloServer(){};

  /**
   * 服务的初始化接口
   **/
  virtual void initialize();

  /**
   * 服务退出时的清理接口
   **/
  virtual void destroyApp();
};

extern HelloServer g_app;

////////////////////////////////////////////
#endif
