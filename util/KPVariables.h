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

/**
 * 列表播放模式
 */
enum KPPlayMode {
    KP_PLAY_MODE_LIST,
    KP_PLAY_MODE_QUEUE,
    KP_PLAY_MODE_RANDOM
};
const std::string KP_PLAY_MODE_LIST_STR       = "list";
const std::string KP_PLAY_MODE_QUEUE_STR      = "queue";
const std::string KP_PLAY_MODE_RANDOM_STR     = "random";

/**
 * 输入资源类型
 * solo 为但资源输入（缺省值）
 * remix 为混合资源输入
 */
enum KPInputFileType {
    KP_INPUT_FILE_TYPE_SOLO,
    KP_INPUT_FILE_TYPE_REMIX
};

const std::string KP_OUTPUT_FILE_FORMAT_MP4 = "mp4";
const std::string KP_OUTPUT_FILE_FORMAT_FLV = "flv";
const std::string KP_EMPTY_STRING           = "";

/**
 * 插件参数对象
 */
typedef std::map<std::string, std::string> PluginParams;
//typedef std::map<std::string, PluginParams> PluginParamsMap;
struct PluginParamsObject {
    std::string  name;
    std::string  unique;
    PluginParams params;
};

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

/**
 * 缓存对象状态
 */
enum KPCacheMode {
    KP_CACHE_MODE_NONE,
    KP_CACHE_MODE_WRITE,
    KP_CACHE_MODE_READ,
};

#endif //KPLAYER_KPVARIABLES_H
