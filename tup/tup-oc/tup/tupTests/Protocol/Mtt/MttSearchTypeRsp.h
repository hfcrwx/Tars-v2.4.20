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

#import "MttIcon.h"
#import "MttSearchTypeInfo.h"
#import "TarsObjectV2.h"

@interface MttSearchTypeRsp : TarsObjectV2

@property(nonatomic, assign, JV2_PROP_GS_V2(resultCode, setResultCode:))
    TarsInt8 JV2_PROP_NM(o, 0, resultCode);
@property(nonatomic, retain,
          JV2_PROP_GS_V2(vSearchTypeInfo, setVSearchTypeInfo:))
    NSArray* JV2_PROP_EX(o, 1, vSearchTypeInfo, VOMTTSearchTypeInfo);
@property(nonatomic, retain, JV2_PROP_GS_V2(imageRes, setImageRes:))
    NSArray* JV2_PROP_EX(o, 2, imageRes, VOMTTIcon);
@property(nonatomic, assign,
          JV2_PROP_GS_V2(iSearchTypeTime, setISearchTypeTime:))
    TarsInt32 JV2_PROP_NM(o, 3, iSearchTypeTime);

@end
