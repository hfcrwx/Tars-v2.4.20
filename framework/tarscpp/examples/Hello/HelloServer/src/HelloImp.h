#ifndef _HelloImp_H_
#define _HelloImp_H_

#include "Hello.h"
#include "servant/Application.h"

/**
 * HelloImp继承hello.h中定义的Hello对象
 *
 */
class HelloImp : public TestApp::Hello {
 public:
  /**
   *
   */
  virtual ~HelloImp() {}

  /**
   * 初始化，Hello的虚拟函数，HelloImp初始化时调用
   */
  virtual void initialize();

  /**
   * 析构，Hello的虚拟函数，服务析构HelloImp退出时调用
   */
  virtual void destroy();

  /**
   * 实现tars文件中定义的test接口
   */
  virtual int test(tars::TarsCurrentPtr current) { return 0; };

  virtual int testHello(const std::string &sReq, std::string &sRsp,
                        tars::TarsCurrentPtr current);
};
/////////////////////////////////////////////////////
#endif
