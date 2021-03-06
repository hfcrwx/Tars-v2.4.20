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

@interface MttBrokerSimplifiedRequest : TarsObjectV2

@property(nonatomic, assign, JV2_PROP_GS_V2(requestType, setRequestType:))
    TarsInt8 JV2_PROP_NM(o, 0, requestType);
@property(nonatomic, retain, JV2_PROP_GS_V2(sGUID, setSGUID:))
    NSData* JV2_PROP_NM(o, 1, sGUID);
@property(nonatomic, retain, JV2_PROP_GS_V2(sQUA, setSQUA:))
    NSString* JV2_PROP_NM(o, 2, sQUA);
@property(nonatomic, retain, JV2_PROP_GS_V2(sLC, setSLC:))
    NSString* JV2_PROP_NM(o, 3, sLC);
@property(nonatomic, retain, JV2_PROP_GS_V2(sSession, setSSession:))
    NSString* JV2_PROP_NM(o, 4, sSession);
@property(nonatomic, assign, JV2_PROP_GS_V2(wTabId, setWTabId:))
    TarsInt16 JV2_PROP_NM(o, 5, wTabId);
@property(nonatomic, retain, JV2_PROP_GS_V2(sChannelId, setSChannelId:))
    NSString* JV2_PROP_NM(o, 6, sChannelId);
@property(nonatomic, assign, JV2_PROP_GS_V2(wScreenWidth, setWScreenWidth:))
    TarsInt16 JV2_PROP_NM(o, 10, wScreenWidth);
@property(nonatomic, assign, JV2_PROP_GS_V2(wScreenHeight, setWScreenHeight:))
    TarsInt16 JV2_PROP_NM(o, 11, wScreenHeight);
@property(nonatomic, assign, JV2_PROP_GS_V2(cFontSize, setCFontSize:))
    TarsInt8 JV2_PROP_NM(o, 12, cFontSize);
@property(nonatomic, assign, JV2_PROP_GS_V2(cRowSpacing, setCRowSpacing:))
    TarsInt8 JV2_PROP_NM(o, 13, cRowSpacing);
@property(nonatomic, retain, JV2_PROP_GS_V2(vCharSetKey, setVCharSetKey:))
    NSData* JV2_PROP_NM(o, 14, vCharSetKey);
@property(nonatomic, assign,
          JV2_PROP_GS_V2(cSupportedImage, setCSupportedImage:))
    TarsInt8 JV2_PROP_NM(o, 15, cSupportedImage);
@property(nonatomic, assign, JV2_PROP_GS_V2(wVersion, setWVersion:))
    TarsInt16 JV2_PROP_NM(o, 20, wVersion);
@property(nonatomic, retain, JV2_PROP_GS_V2(sUrl, setSUrl:))
    NSString* JV2_PROP_NM(o, 21, sUrl);
@property(nonatomic, retain,
          JV2_PROP_GS_V2(sUserHttpHeader, setSUserHttpHeader:))
    NSString* JV2_PROP_NM(o, 22, sUserHttpHeader);
@property(nonatomic, retain,
          JV2_PROP_GS_V2(sPageEncodeName, setSPageEncodeName:))
    NSString* JV2_PROP_NM(o, 23, sPageEncodeName);
@property(nonatomic, assign, JV2_PROP_GS_V2(cZipType, setCZipType:))
    TarsInt8 JV2_PROP_NM(o, 24, cZipType);
@property(nonatomic, assign,
          JV2_PROP_GS_V2(cImgQualityType, setCImgQualityType:))
    TarsInt8 JV2_PROP_NM(o, 25, cImgQualityType);
@property(nonatomic, assign, JV2_PROP_GS_V2(wPageSizeKB, setWPageSizeKB:))
    TarsInt16 JV2_PROP_NM(o, 26, wPageSizeKB);
@property(nonatomic, retain, JV2_PROP_GS_V2(vImgCacheFNV, setVImgCacheFNV:))
    NSArray* JV2_PROP_EX(o, 27, vImgCacheFNV, VONSNumber);
@property(nonatomic, assign,
          JV2_PROP_GS_V2(cLzmaDictOffset, setCLzmaDictOffset:))
    TarsInt8 JV2_PROP_NM(o, 28, cLzmaDictOffset);
@property(nonatomic, assign, JV2_PROP_GS_V2(iEntry, setIEntry:))
    TarsInt32 JV2_PROP_NM(o, 29, iEntry);
@property(nonatomic, assign, JV2_PROP_GS_V2(iEntryType, setIEntryType:))
    TarsInt32 JV2_PROP_NM(o, 30, iEntryType);
@property(nonatomic, assign,
          JV2_PROP_GS_V2(cSecuritySwitch, setCSecuritySwitch:))
    TarsInt8 JV2_PROP_NM(o, 31, cSecuritySwitch);
@property(nonatomic, retain, JV2_PROP_GS_V2(vPostData, setVPostData:))
    NSData* JV2_PROP_NM(o, 40, vPostData);
@property(nonatomic, assign, JV2_PROP_GS_V2(cJSEvent, setCJSEvent:))
    TarsInt8 JV2_PROP_NM(o, 41, cJSEvent);
@property(nonatomic, assign, JV2_PROP_GS_V2(iJSNode, setIJSNode:))
    TarsInt32 JV2_PROP_NM(o, 42, iJSNode);
@property(nonatomic, retain, JV2_PROP_GS_V2(viKey, setViKey:))
    NSArray* JV2_PROP_EX(o, 43, viKey, VONSNumber);
@property(nonatomic, retain, JV2_PROP_GS_V2(vvbValue, setVvbValue:))
    NSArray* JV2_PROP_EX(o, 44, vvbValue, VONSData);
@property(nonatomic, retain, JV2_PROP_GS_V2(sUpBoundary, setSUpBoundary:))
    NSString* JV2_PROP_NM(o, 50, sUpBoundary);
@property(nonatomic, retain, JV2_PROP_GS_V2(sUpContentType, setSUpContentType:))
    NSString* JV2_PROP_NM(o, 51, sUpContentType);
@property(nonatomic, retain, JV2_PROP_GS_V2(sUpFileName, setSUpFileName:))
    NSString* JV2_PROP_NM(o, 52, sUpFileName);
@property(nonatomic, retain, JV2_PROP_GS_V2(sUpName, setSUpName:))
    NSString* JV2_PROP_NM(o, 53, sUpName);
@property(nonatomic, assign, JV2_PROP_GS_V2(cUpZipType, setCUpZipType:))
    TarsInt8 JV2_PROP_NM(o, 54, cUpZipType);
@property(nonatomic, assign, JV2_PROP_GS_V2(iUpFileSize, setIUpFileSize:))
    TarsInt32 JV2_PROP_NM(o, 55, iUpFileSize);
@property(nonatomic, assign, JV2_PROP_GS_V2(iUpPackNo, setIUpPackNo:))
    TarsInt32 JV2_PROP_NM(o, 56, iUpPackNo);
@property(nonatomic, assign, JV2_PROP_GS_V2(iUpDataSize, setIUpDataSize:))
    TarsInt32 JV2_PROP_NM(o, 57, iUpDataSize);
@property(nonatomic, assign,
          JV2_PROP_GS_V2(cUpNeedResponse, setCUpNeedResponse:))
    TarsInt8 JV2_PROP_NM(o, 58, cUpNeedResponse);
@property(nonatomic, assign, JV2_PROP_GS_V2(cStoreAbility, setCStoreAbility:))
    TarsInt8 JV2_PROP_NM(o, 59, cStoreAbility);
@property(nonatomic, assign, JV2_PROP_GS_V2(iLanguageType, setILanguageType:))
    TarsInt32 JV2_PROP_NM(o, 60, iLanguageType);
@property(nonatomic, assign, JV2_PROP_GS_V2(cContentType, setCContentType:))
    TarsInt8 JV2_PROP_NM(o, 61, cContentType);
@property(nonatomic, assign, JV2_PROP_GS_V2(cReqEncrypted, setCReqEncrypted:))
    TarsInt8 JV2_PROP_NM(o, 62, cReqEncrypted);

@end
