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

#ifndef __QUERY_ITEM_H_
#define __QUERY_ITEM_H_

#include <map>
#include <string>
#include "servant/Application.h"

using namespace std;
using namespace tars;

/////////////////////////////////////////////////////////////////////
class QueryItem {
 public:
  string sUid;
  map<string, string> mQuery;
  tars::TarsCurrentPtr current;

  QueryItem() : sUid(""), current(NULL) {}
};

#endif
