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

#ifndef __DESTROY_COMMAND_H_
#define __DESTROY_COMMAND_H_

#include "NodeRollLogger.h"
#include "ServerCommand.h"

/**
 * 销毁服务
 *
 */
extern RemoveLogManager *g_RemoveLogThread;

class CommandDestroy : public ServerCommand {
 public:
  CommandDestroy(const ServerObjectPtr &pServerObjectPtr, bool bByNode = false);
  ExeStatus canExecute(string &sResult);
  int execute(string &sResult);

 private:
  //    bool    _byNode;
  ServerDescriptor _desc;
  ServerObjectPtr _serverObjectPtr;
};

//////////////////////////////////////////////////////////////
//
inline CommandDestroy::CommandDestroy(const ServerObjectPtr &pServerObjectPtr,
                                      bool bByNode)
    : _serverObjectPtr(pServerObjectPtr) {
  _desc = _serverObjectPtr->getServerDescriptor();
}
#endif
