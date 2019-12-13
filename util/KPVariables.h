//
// Created by karaler on 2019-09-16.
// Author: karaler
// Description: 基础变量定义
// Others: 
// Copyright (c) 2019 ${ORGANIZATION_NAME}. All rights reserved.
//

#ifndef KPLAYER_KPVARIABLES_H
#define KPLAYER_KPVARIABLES_H

#include <string>
#include <map>

enum KPFilterType {
    KP_FILTER_TYPE_NONE,
    KP_FILTER_TYPE_VIDEO,
    KP_FILTER_TYPE_AUDIO,
};
const std::string KP_FILTER_TYPE_NONE_STRING  = "NONE";
const std::string KP_FILTER_TYPE_VIDEO_STRING = "VIDEO";
const std::string KP_FILTER_TYPE_AUDIO_STRING = "AUDIO";

/**
 * 输出文件类型
 * file 为输出为普通文件
 * rtmp 为为推流
 */
enum KPOutputFileType {
    KP_OUTPUT_FILE_TYPE_FILE,
    KP_OUTPUT_FILE_TYPE_RTMP,
};

const std::string KP_OUTPUT_FILE_FORMAT_MP4 = "mp4";
const std::string KP_OUTPUT_FILE_FORMAT_FLV = "flv";
const std::string KP_EMPTY_STRING           = "";

/**
 * 插件参数对象
 */
typedef std::map<std::string, std::string>  PluginParams;
typedef std::map<std::string, PluginParams> PluginParamsMap;

/**
 * 解码器状态枚举
 */
enum KPDecodeStatus {
    KP_DECODE_STATUS_NONE,
    KP_DECODE_STATUS_PLAYING,
    KP_DECODE_STATUS_STOP,
    KP_DECODE_STATUS_PAUSE,
};

const std::string KP_DECODE_STATUS_NONE_STRING                = "NONE";
const std::string KP_DECODE_STATUS_PLAYING_STRING             = "PLAYING";
const std::string KP_DECODE_STATUS_STOP_STRING                = "STOP";
const std::string KP_DECODE_STATUS_PAUSE_STRING               = "PAUSE";


enum KP_SINGLE_OUTPUT_STATUS {
    KP_SINGLE_OUTPUT_STATUS_NONE,
    KP_SINGLE_OUTPUT_STATUS_CONNECTED,
    KP_SINGLE_OUTPUT_STATUS_DISCONNECTED,
    KP_SINGLE_OUTPUT_STATUS_RECONNECTING,
};
const std::string KP_SINGLE_OUTPUT_STATUS_NONE_STRING         = "NONE";
const std::string KP_SINGLE_OUTPUT_STATUS_CONNECTED_STRING    = "CONNECTED";
const std::string KP_SINGLE_OUTPUT_STATUS_DISCONNECTED_STRING = "DISCONNECTED";
const std::string KP_SINGLE_OUTPUT_STATUS_RECONNECTING_STRING = "RECONNECTING";

#endif //KPLAYER_KPVARIABLES_H
