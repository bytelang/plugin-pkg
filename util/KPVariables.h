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

#endif //KPLAYER_KPVARIABLES_H
