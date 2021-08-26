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

#import "TarsObjectV2.h"

@interface MttRequestFragment : TarsObjectV2

@property(nonatomic, assign, JV2_PROP_GS_V2(wVersion, setWVersion:))
    TarsInt16 JV2_PROP_NM(r, 0, wVersion);
@property(nonatomic, retain, JV2_PROP_GS_V2(sSessionID, setSSessionID:))
    NSString* JV2_PROP_NM(r, 1, sSessionID);
@property(nonatomic, assign, JV2_PROP_GS_V2(wTabID, setWTabID:))
    TarsInt16 JV2_PROP_NM(r, 2, wTabID);
@property(nonatomic, assign, JV2_PROP_GS_V2(iRequestID, setIRequestID:))
    TarsInt32 JV2_PROP_NM(r, 3, iRequestID);
@property(nonatomic, assign,
          JV2_PROP_GS_V2(iExpectSequenceID, setIExpectSequenceID:))
    TarsInt32 JV2_PROP_NM(r, 4, iExpectSequenceID);
@property(nonatomic, assign, JV2_PROP_GS_V2(iExpectOffset, setIExpectOffset:))
    TarsInt32 JV2_PROP_NM(r, 5, iExpectOffset);
@property(nonatomic, assign, JV2_PROP_GS_V2(iRspMaxSize, setIRspMaxSize:))
    TarsInt32 JV2_PROP_NM(r, 6, iRspMaxSize);

@end
