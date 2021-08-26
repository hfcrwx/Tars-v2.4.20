#include "TarsServantName.h"
#include "TarsTest/TestcaseServer/RPCTest.h"
#include "gtest/gtest.h"
#include "servant/AdminF.h"
#include "servant/Application.h"

#include <iostream>
#include "util/tc_singleton.h"
#include "util/tc_timeprovider.h"

using namespace std;
using namespace tars;
using namespace TarsTest;

class B : public TC_Singleton<B, CreateStatic, PhoneixLifetime> {
 public:
  B() { cout << "B" << endl; }
  ~B() { cout << "~B" << endl; }

  void test() { cout << "test B" << endl; }
};

class A : public TC_Singleton<A, CreateStatic, PhoneixLifetime> {
 public:
  A() { cout << "A" << endl; }
  ~A() {
    cout << "~A" << endl;
    B::getInstance()->test();
  }

  void test() { cout << "test A" << endl; }
};

TEST(TarsUtilTestcase, UT_TC_Singleton) {
  //        A::getInstance()->test();
  //        B::getInstance()->test();

  cout << TC_TimeProvider::getInstance()->getNow() << endl;
  TC_Common::sleep(1);
}
