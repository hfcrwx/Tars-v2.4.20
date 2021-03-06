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

#ifndef __DB_PROXY_H_
#define __DB_PROXY_H_

#include "MonitorQuery.h"
#include "QueryServer.h"
#include "servant/RemoteLogger.h"
#include "util/tc_common.h"
#include "util/tc_config.h"
#include "util/tc_file.h"
#include "util/tc_mysql.h"
#include "util/tc_option.h"
#include "util/tc_thread.h"

using namespace tars;

class DbProxy {
 public:
  DbProxy();

  ~DbProxy();

  void queryData(map<string, string>& mSqlPart,
                 MonitorQueryRsp& rsp);  //, bool bDbCountFlag);

  string getLastTime(const map<string, string>& mSqlPart);

 private:
  int createRespHead(const vector<pair<int, string>>& res,
                     const string& sLasttime,
                     MonitorQueryRsp& rsp);  //, bool bDbCountFlag);

  int createRespData(const string& sUid, const map<string, string>& mSqlPart,
                     const vector<map<string, vector<double>>>& vDataList,
                     MonitorQueryRsp& rsp);

  //    string makeResult(int iRet, const string& sRes);

 private:
  QueryParam _queryParam;
};

#endif
