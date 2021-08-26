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
#ifndef _OneWayRpcTest_H_
#define _OneWayRpcTest_H_
#include <string>
#include "OneWayRpcTest.h"
#include "servant/Application.h"

/**
 *
 *
 */
extern bool g_OneWayRpcTestSuccess;

class OneWayRpcTestImp : public TarsTest::OneWayRpcTest {
 public:
  /**
   *
   */
  virtual ~OneWayRpcTestImp() {}

  /**
   *
   */
  virtual void initialize();

  /**
   *
   */
  virtual void destroy();

  /**
   *
   */
  virtual tars::Int32 test(tars::TarsCurrentPtr current) {
    // cerr << "std::log:test g_OneWayRpcTestSuccess" << std::endl;
    g_OneWayRpcTestSuccess = true;

    return 2;
  };
};
/////////////////////////////////////////////////////
#endif
