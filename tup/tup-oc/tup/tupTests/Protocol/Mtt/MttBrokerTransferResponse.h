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

// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 2.1.4.2 by WSRD Tencent.
// Generated from
// `/usr/local/resin_system.mqq.com/webapps/communication/tars/upload/renjunyi/MTT.tars'
// **********************************************************************

#import "MttBrokerPushResponse.h"
#import "MttBrokerSecurityResponse.h"
#import "TarsObjectV2.h"

@interface MttBrokerTransferResponse : TarsObjectV2

@property(nonatomic, retain, JV2_PROP_GS_V2(sSession, setSSession:))
    NSString* JV2_PROP_NM(r, 0, sSession);
@property(nonatomic, assign, JV2_PROP_GS_V2(wTabId, setWTabId:))
    TarsInt16 JV2_PROP_NM(r, 1, wTabId);
@property(nonatomic, retain,
          JV2_PROP_GS_V2(sPageEncodeName, setSPageEncodeName:))
    NSString* JV2_PROP_NM(r, 2, sPageEncodeName);
@property(nonatomic, assign, JV2_PROP_GS_V2(cDirectWap, setCDirectWap:))
    TarsInt8 JV2_PROP_NM(r, 3, cDirectWap);
@property(nonatomic, retain, JV2_PROP_GS_V2(sDirectWapUrl, setSDirectWapUrl:))
    NSString* JV2_PROP_NM(r, 4, sDirectWapUrl);
@property(nonatomic, assign,
          JV2_PROP_GS_V2(iContentTimeStamp, setIContentTimeStamp:))
    TarsInt32 JV2_PROP_NM(r, 5, iContentTimeStamp);
@property(nonatomic, retain, JV2_PROP_GS_V2(sFragKey, setSFragKey:))
    NSString* JV2_PROP_NM(r, 6, sFragKey);
@property(nonatomic, assign, JV2_PROP_GS_V2(iRspContentLen, setIRspContentLen:))
    TarsInt32 JV2_PROP_NM(r, 7, iRspContentLen);
@property(nonatomic, retain, JV2_PROP_GS_V2(sUserSession, setSUserSession:))
    NSString* JV2_PROP_NM(o, 8, sUserSession);
@property(nonatomic, retain, JV2_PROP_GS_V2(stPushResp, setStPushResp:))
    MttBrokerPushResponse* JV2_PROP_NM(o, 9, stPushResp);
@property(nonatomic, retain, JV2_PROP_GS_V2(stSecurityResp, setStSecurityResp:))
    MttBrokerSecurityResponse* JV2_PROP_NM(o, 10, stSecurityResp);
@property(nonatomic, assign, JV2_PROP_GS_V2(cShare, setCShare:))
    TarsInt8 JV2_PROP_NM(o, 11, cShare);

@end
