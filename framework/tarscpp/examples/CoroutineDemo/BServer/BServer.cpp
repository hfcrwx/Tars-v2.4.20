﻿/**
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

#include "BServer.h"
#include "BServantImp.h"

using namespace std;

BServer g_app;

/////////////////////////////////////////////////////////////////
void BServer::initialize() {
  // initialize application here:
  //...
  addServant<BServantImp>(ServerConfig::Application + "." +
                          ServerConfig::ServerName + ".BServantObj");
}
/////////////////////////////////////////////////////////////////
void BServer::destroyApp() {
  // destroy application here:
  //...
}

int main(int argc, char* argv[]) {
  try {
    g_app.main(argc, argv);
    g_app.waitForShutdown();
  } catch (std::exception& e) {
    cerr << "std::exception:" << e.what() << std::endl;
  } catch (...) {
    cerr << "unknown exception." << std::endl;
  }
  return -1;
}
/////////////////////////////////////////////////////////////////
