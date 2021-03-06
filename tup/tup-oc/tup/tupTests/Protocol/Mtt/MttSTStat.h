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

#import "MttETPV.h"
#import "MttFKINFO.h"
#import "MttPerformanceInfo.h"
#import "MttSTPV.h"
#import "MttSTTime.h"
#import "MttSTTotal.h"
#import "MttThirdUse.h"
#import "MttUserBase.h"
#import "TarsObjectV2.h"

@interface MttSTStat : TarsObjectV2

@property(nonatomic, retain, JV2_PROP_GS_V2(stUB, setStUB:))
    MttUserBase* JV2_PROP_NM(r, 0, stUB);
@property(nonatomic, retain, JV2_PROP_GS_V2(stTime, setStTime:))
    MttSTTime* JV2_PROP_NM(r, 1, stTime);
@property(nonatomic, retain, JV2_PROP_GS_V2(stTotal, setStTotal:))
    NSArray* JV2_PROP_EX(r, 2, stTotal, VOMTTSTTotal);
@property(nonatomic, retain, JV2_PROP_GS_V2(stOuterPv, setStOuterPv:))
    NSArray* JV2_PROP_EX(r, 3, stOuterPv, VOMTTSTPV);
@property(nonatomic, retain, JV2_PROP_GS_V2(stInnerPv, setStInnerPv:))
    NSArray* JV2_PROP_EX(r, 4, stInnerPv, VOMTTSTPV);
@property(nonatomic, assign, JV2_PROP_GS_V2(iUseTime, setIUseTime:))
    TarsInt32 JV2_PROP_NM(r, 5, iUseTime);
@property(nonatomic, retain, JV2_PROP_GS_V2(vEntryPv, setVEntryPv:))
    NSArray* JV2_PROP_EX(o, 6, vEntryPv, VOMTTETPV);
@property(nonatomic, retain, JV2_PROP_GS_V2(vFastKey, setVFastKey:))
    NSArray* JV2_PROP_EX(o, 7, vFastKey, VOMTTFKINFO);
@property(nonatomic, retain, JV2_PROP_GS_V2(sProtocol, setSProtocol:))
    NSString* JV2_PROP_NM(o, 8, sProtocol);
@property(nonatomic, retain, JV2_PROP_GS_V2(vThirdUse, setVThirdUse:))
    NSArray* JV2_PROP_EX(o, 9, vThirdUse, VOMTTThirdUse);
@property(nonatomic, retain,
          JV2_PROP_GS_V2(vPerformanceInfo, setVPerformanceInfo:))
    NSArray* JV2_PROP_EX(o, 10, vPerformanceInfo, VOMTTPerformanceInfo);
@property(nonatomic, retain, JV2_PROP_GS_V2(vUseTime, setVUseTime:))
    NSArray* JV2_PROP_EX(o, 11, vUseTime, VONSNumber);

@end
