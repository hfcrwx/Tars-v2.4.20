﻿/**
 * Tencent is pleased to support the open source community by making Tars available.
 *
 * Copyright (C) 2016THL A29 Limited, a Tencent company. All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use this file except 
 * in compliance with the License. You may obtain a copy of the License at
 *
 * https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software distributed 
 * under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR 
 * CONDITIONS OF ANY KIND, either express or implied. See the License for the 
 * specific language governing permissions and limitations under the License.
 */

"use strict";

var assert    = require("assert");
var TarsStream = require("@tars/stream");
var TarsError  = require("@tars/rpc").error;

var tars = tars || {};
module.exports.tars = tars;

tars.ConfigProxy = function () {
    this._name   = undefined;
    this._worker = undefined;
};

tars.ConfigProxy.prototype.setTimeout = function (iTimeout) {
    this._worker.timeout = iTimeout;
};

tars.ConfigProxy.prototype.getTimeout = function () {
    return this._worker.timeout;
};


tars.ConfigInfo = function() {
    this.appname = "";
    this.servername = "";
    this.filename = "";
    this.bAppOnly = false;
    this.host = "";
    this.setdivision = "";
    this._classname = "tars.ConfigInfo";
};
tars.ConfigInfo._classname = "tars.ConfigInfo";
tars.ConfigInfo._write = function (os, tag, value) { os.writeStruct(tag, value); };
tars.ConfigInfo._read  = function (is, tag, def) { return is.readStruct(tag, true, def); };
tars.ConfigInfo._readFrom = function (is) {
    var tmp = new tars.ConfigInfo();
    tmp.appname = is.readString(0, true, "");
    tmp.servername = is.readString(1, true, "");
    tmp.filename = is.readString(2, true, "");
    tmp.bAppOnly = is.readBoolean(3, true, false);
    tmp.host = is.readString(4, false, "");
    tmp.setdivision = is.readString(5, false, "");
    return tmp;
};
tars.ConfigInfo.prototype._writeTo = function (os) {
    os.writeString(0, this.appname);
    os.writeString(1, this.servername);
    os.writeString(2, this.filename);
    os.writeBoolean(3, this.bAppOnly);
    os.writeString(4, this.host);
    os.writeString(5, this.setdivision);
};
tars.ConfigInfo.prototype._equal = function () {
    assert.fail("this structure not define key operation");
};
tars.ConfigInfo.prototype._genKey = function () {
    if (!this._proto_struct_name_) {
        this._proto_struct_name_ = "STRUCT" + Math.random();
    }
    return this._proto_struct_name_;
};
tars.ConfigInfo.prototype.toObject = function() { 
    return {
        "appname" : this.appname,
        "servername" : this.servername,
        "filename" : this.filename,
        "bAppOnly" : this.bAppOnly,
        "host" : this.host,
        "setdivision" : this.setdivision
    };
};
tars.ConfigInfo.prototype.readFromObject = function(json) { 
    json.hasOwnProperty("appname") && (this.appname = json.appname);
    json.hasOwnProperty("servername") && (this.servername = json.servername);
    json.hasOwnProperty("filename") && (this.filename = json.filename);
    json.hasOwnProperty("bAppOnly") && (this.bAppOnly = json.bAppOnly);
    json.hasOwnProperty("host") && (this.host = json.host);
    json.hasOwnProperty("setdivision") && (this.setdivision = json.setdivision);
};
tars.ConfigInfo.prototype.toBinBuffer = function () {
    var os = new TarsStream.TarsOutputStream();
    this._writeTo(os);
    return os.getBinBuffer();
};
tars.ConfigInfo.new = function () {
    return new tars.ConfigInfo();
};
tars.ConfigInfo.create = function (is) {
    return tars.ConfigInfo._readFrom(is);
};

tars.GetConfigListInfo = function() {
    this.appname = "";
    this.servername = "";
    this.bAppOnly = false;
    this.host = "";
    this.setdivision = "";
    this.containername = "";
    this._classname = "tars.GetConfigListInfo";
};
tars.GetConfigListInfo._classname = "tars.GetConfigListInfo";
tars.GetConfigListInfo._write = function (os, tag, value) { os.writeStruct(tag, value); };
tars.GetConfigListInfo._read  = function (is, tag, def) { return is.readStruct(tag, true, def); };
tars.GetConfigListInfo._readFrom = function (is) {
    var tmp = new tars.GetConfigListInfo();
    tmp.appname = is.readString(0, true, "");
    tmp.servername = is.readString(1, false, "");
    tmp.bAppOnly = is.readBoolean(2, false, false);
    tmp.host = is.readString(3, false, "");
    tmp.setdivision = is.readString(4, false, "");
    tmp.containername = is.readString(5, false, "");
    return tmp;
};
tars.GetConfigListInfo.prototype._writeTo = function (os) {
    os.writeString(0, this.appname);
    os.writeString(1, this.servername);
    os.writeBoolean(2, this.bAppOnly);
    os.writeString(3, this.host);
    os.writeString(4, this.setdivision);
    os.writeString(5, this.containername);
};
tars.GetConfigListInfo.prototype._equal = function () {
    assert.fail("this structure not define key operation");
};
tars.GetConfigListInfo.prototype._genKey = function () {
    if (!this._proto_struct_name_) {
        this._proto_struct_name_ = "STRUCT" + Math.random();
    }
    return this._proto_struct_name_;
};
tars.GetConfigListInfo.prototype.toObject = function() { 
    return {
        "appname" : this.appname,
        "servername" : this.servername,
        "bAppOnly" : this.bAppOnly,
        "host" : this.host,
        "setdivision" : this.setdivision,
        "containername" : this.containername
    };
};
tars.GetConfigListInfo.prototype.readFromObject = function(json) { 
    json.hasOwnProperty("appname") && (this.appname = json.appname);
    json.hasOwnProperty("servername") && (this.servername = json.servername);
    json.hasOwnProperty("bAppOnly") && (this.bAppOnly = json.bAppOnly);
    json.hasOwnProperty("host") && (this.host = json.host);
    json.hasOwnProperty("setdivision") && (this.setdivision = json.setdivision);
    json.hasOwnProperty("containername") && (this.containername = json.containername);
};
tars.GetConfigListInfo.prototype.toBinBuffer = function () {
    var os = new TarsStream.TarsOutputStream();
    this._writeTo(os);
    return os.getBinBuffer();
};
tars.GetConfigListInfo.new = function () {
    return new tars.GetConfigListInfo();
};
tars.GetConfigListInfo.create = function (is) {
    return tars.GetConfigListInfo._readFrom(is);
};


var __tars_Config$ListAllConfigByInfo$EN = function (configInfo) {
    var os = new TarsStream.TarsOutputStream();
    os.writeStruct(1, configInfo);
    return os.getBinBuffer();
};

var __tars_Config$ListAllConfigByInfo$DE = function (data) {
    try {
        var is = new TarsStream.TarsInputStream(data.response.sBuffer);
        return {
            "request" : data.request,
            "response" : {
                "costtime" : data.request.costtime,
                "return" : is.readInt32(0, true, 0),
                "arguments" : {
                    "vf" : is.readList(2, true, TarsStream.List(TarsStream.String))
                }
            }
        };
    } catch (e) {
        throw {
            "request" : data.request,
            "response" : {
                "costtime" : data.request.costtime,
                "error" : {
                    "code" : TarsError.CLIENT.DECODE_ERROR,
                    "message" : e.message
                }
            }
        };
    }
};

var __tars_Config$ListAllConfigByInfo$ER = function (data) {
    throw {
        "request" : data.request,
        "response" : {
            "costtime" : data.request.costtime,
            "error" : data.error
        }
    }
};

tars.ConfigProxy.prototype.ListAllConfigByInfo = function (configInfo) {
    return this._worker.tars_invoke("ListAllConfigByInfo", __tars_Config$ListAllConfigByInfo$EN(configInfo), arguments[arguments.length - 1]).then(__tars_Config$ListAllConfigByInfo$DE, __tars_Config$ListAllConfigByInfo$ER);
};

var __tars_Config$ListConfig$EN = function (app, server) {
    var os = new TarsStream.TarsOutputStream();
    os.writeString(1, app);
    os.writeString(2, server);
    return os.getBinBuffer();
};

var __tars_Config$ListConfig$DE = function (data) {
    try {
        var is = new TarsStream.TarsInputStream(data.response.sBuffer);
        return {
            "request" : data.request,
            "response" : {
                "costtime" : data.request.costtime,
                "return" : is.readInt32(0, true, 0),
                "arguments" : {
                    "vf" : is.readList(3, true, TarsStream.List(TarsStream.String))
                }
            }
        };
    } catch (e) {
        throw {
            "request" : data.request,
            "response" : {
                "costtime" : data.request.costtime,
                "error" : {
                    "code" : TarsError.CLIENT.DECODE_ERROR,
                    "message" : e.message
                }
            }
        };
    }
};

var __tars_Config$ListConfig$ER = function (data) {
    throw {
        "request" : data.request,
        "response" : {
            "costtime" : data.request.costtime,
            "error" : data.error
        }
    }
};

tars.ConfigProxy.prototype.ListConfig = function (app, server) {
    return this._worker.tars_invoke("ListConfig", __tars_Config$ListConfig$EN(app, server), arguments[arguments.length - 1]).then(__tars_Config$ListConfig$DE, __tars_Config$ListConfig$ER);
};

var __tars_Config$ListConfigByInfo$EN = function (configInfo) {
    var os = new TarsStream.TarsOutputStream();
    os.writeStruct(1, configInfo);
    return os.getBinBuffer();
};

var __tars_Config$ListConfigByInfo$DE = function (data) {
    try {
        var is = new TarsStream.TarsInputStream(data.response.sBuffer);
        return {
            "request" : data.request,
            "response" : {
                "costtime" : data.request.costtime,
                "return" : is.readInt32(0, true, 0),
                "arguments" : {
                    "vf" : is.readList(2, true, TarsStream.List(TarsStream.String))
                }
            }
        };
    } catch (e) {
        throw {
            "request" : data.request,
            "response" : {
                "costtime" : data.request.costtime,
                "error" : {
                    "code" : TarsError.CLIENT.DECODE_ERROR,
                    "message" : e.message
                }
            }
        };
    }
};

var __tars_Config$ListConfigByInfo$ER = function (data) {
    throw {
        "request" : data.request,
        "response" : {
            "costtime" : data.request.costtime,
            "error" : data.error
        }
    }
};

tars.ConfigProxy.prototype.ListConfigByInfo = function (configInfo) {
    return this._worker.tars_invoke("ListConfigByInfo", __tars_Config$ListConfigByInfo$EN(configInfo), arguments[arguments.length - 1]).then(__tars_Config$ListConfigByInfo$DE, __tars_Config$ListConfigByInfo$ER);
};

var __tars_Config$checkConfig$EN = function (appServerName, filename, host) {
    var os = new TarsStream.TarsOutputStream();
    os.writeString(1, appServerName);
    os.writeString(2, filename);
    os.writeString(3, host);
    return os.getBinBuffer();
};

var __tars_Config$checkConfig$DE = function (data) {
    try {
        var is = new TarsStream.TarsInputStream(data.response.sBuffer);
        return {
            "request" : data.request,
            "response" : {
                "costtime" : data.request.costtime,
                "return" : is.readInt32(0, true, 0),
                "arguments" : {
                    "result" : is.readString(4, true, "")
                }
            }
        };
    } catch (e) {
        throw {
            "request" : data.request,
            "response" : {
                "costtime" : data.request.costtime,
                "error" : {
                    "code" : TarsError.CLIENT.DECODE_ERROR,
                    "message" : e.message
                }
            }
        };
    }
};

var __tars_Config$checkConfig$ER = function (data) {
    throw {
        "request" : data.request,
        "response" : {
            "costtime" : data.request.costtime,
            "error" : data.error
        }
    }
};

tars.ConfigProxy.prototype.checkConfig = function (appServerName, filename, host) {
    return this._worker.tars_invoke("checkConfig", __tars_Config$checkConfig$EN(appServerName, filename, host), arguments[arguments.length - 1]).then(__tars_Config$checkConfig$DE, __tars_Config$checkConfig$ER);
};

var __tars_Config$checkConfigByInfo$EN = function (configInfo) {
    var os = new TarsStream.TarsOutputStream();
    os.writeStruct(1, configInfo);
    return os.getBinBuffer();
};

var __tars_Config$checkConfigByInfo$DE = function (data) {
    try {
        var is = new TarsStream.TarsInputStream(data.response.sBuffer);
        return {
            "request" : data.request,
            "response" : {
                "costtime" : data.request.costtime,
                "return" : is.readInt32(0, true, 0),
                "arguments" : {
                    "result" : is.readString(2, true, "")
                }
            }
        };
    } catch (e) {
        throw {
            "request" : data.request,
            "response" : {
                "costtime" : data.request.costtime,
                "error" : {
                    "code" : TarsError.CLIENT.DECODE_ERROR,
                    "message" : e.message
                }
            }
        };
    }
};

var __tars_Config$checkConfigByInfo$ER = function (data) {
    throw {
        "request" : data.request,
        "response" : {
            "costtime" : data.request.costtime,
            "error" : data.error
        }
    }
};

tars.ConfigProxy.prototype.checkConfigByInfo = function (configInfo) {
    return this._worker.tars_invoke("checkConfigByInfo", __tars_Config$checkConfigByInfo$EN(configInfo), arguments[arguments.length - 1]).then(__tars_Config$checkConfigByInfo$DE, __tars_Config$checkConfigByInfo$ER);
};

var __tars_Config$loadConfig$EN = function (app, server, filename) {
    var os = new TarsStream.TarsOutputStream();
    os.writeString(1, app);
    os.writeString(2, server);
    os.writeString(3, filename);
    return os.getBinBuffer();
};

var __tars_Config$loadConfig$DE = function (data) {
    try {
        var is = new TarsStream.TarsInputStream(data.response.sBuffer);
        return {
            "request" : data.request,
            "response" : {
                "costtime" : data.request.costtime,
                "return" : is.readInt32(0, true, 0),
                "arguments" : {
                    "config" : is.readString(4, true, "")
                }
            }
        };
    } catch (e) {
        throw {
            "request" : data.request,
            "response" : {
                "costtime" : data.request.costtime,
                "error" : {
                    "code" : TarsError.CLIENT.DECODE_ERROR,
                    "message" : e.message
                }
            }
        };
    }
};

var __tars_Config$loadConfig$ER = function (data) {
    throw {
        "request" : data.request,
        "response" : {
            "costtime" : data.request.costtime,
            "error" : data.error
        }
    }
};

tars.ConfigProxy.prototype.loadConfig = function (app, server, filename) {
    return this._worker.tars_invoke("loadConfig", __tars_Config$loadConfig$EN(app, server, filename), arguments[arguments.length - 1]).then(__tars_Config$loadConfig$DE, __tars_Config$loadConfig$ER);
};

var __tars_Config$loadConfigByHost$EN = function (appServerName, filename, host) {
    var os = new TarsStream.TarsOutputStream();
    os.writeString(1, appServerName);
    os.writeString(2, filename);
    os.writeString(3, host);
    return os.getBinBuffer();
};

var __tars_Config$loadConfigByHost$DE = function (data) {
    try {
        var is = new TarsStream.TarsInputStream(data.response.sBuffer);
        return {
            "request" : data.request,
            "response" : {
                "costtime" : data.request.costtime,
                "return" : is.readInt32(0, true, 0),
                "arguments" : {
                    "config" : is.readString(4, true, "")
                }
            }
        };
    } catch (e) {
        throw {
            "request" : data.request,
            "response" : {
                "costtime" : data.request.costtime,
                "error" : {
                    "code" : TarsError.CLIENT.DECODE_ERROR,
                    "message" : e.message
                }
            }
        };
    }
};

var __tars_Config$loadConfigByHost$ER = function (data) {
    throw {
        "request" : data.request,
        "response" : {
            "costtime" : data.request.costtime,
            "error" : data.error
        }
    }
};

tars.ConfigProxy.prototype.loadConfigByHost = function (appServerName, filename, host) {
    return this._worker.tars_invoke("loadConfigByHost", __tars_Config$loadConfigByHost$EN(appServerName, filename, host), arguments[arguments.length - 1]).then(__tars_Config$loadConfigByHost$DE, __tars_Config$loadConfigByHost$ER);
};

var __tars_Config$loadConfigByInfo$EN = function (configInfo) {
    var os = new TarsStream.TarsOutputStream();
    os.writeStruct(1, configInfo);
    return os.getBinBuffer();
};

var __tars_Config$loadConfigByInfo$DE = function (data) {
    try {
        var is = new TarsStream.TarsInputStream(data.response.sBuffer);
        return {
            "request" : data.request,
            "response" : {
                "costtime" : data.request.costtime,
                "return" : is.readInt32(0, true, 0),
                "arguments" : {
                    "config" : is.readString(2, true, "")
                }
            }
        };
    } catch (e) {
        throw {
            "request" : data.request,
            "response" : {
                "costtime" : data.request.costtime,
                "error" : {
                    "code" : TarsError.CLIENT.DECODE_ERROR,
                    "message" : e.message
                }
            }
        };
    }
};

var __tars_Config$loadConfigByInfo$ER = function (data) {
    throw {
        "request" : data.request,
        "response" : {
            "costtime" : data.request.costtime,
            "error" : data.error
        }
    }
};

tars.ConfigProxy.prototype.loadConfigByInfo = function (configInfo) {
    return this._worker.tars_invoke("loadConfigByInfo", __tars_Config$loadConfigByInfo$EN(configInfo), arguments[arguments.length - 1]).then(__tars_Config$loadConfigByInfo$DE, __tars_Config$loadConfigByInfo$ER);
};



