//
// Created by karaler on 2019-10-29.
// Author: karaler
// Description:
// Others: 
// Copyright (c) 2019 ${ORGANIZATION_NAME}. All rights reserved.
//

#ifndef KPLAYER_KPPLUGINADAPTER_H
#define KPLAYER_KPPLUGINADAPTER_H

#include <string>
#include <cstdlib>
#include <sstream>
#include <memory>
#include <future>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

extern "C" {
#include <libavformat/avformat.h>
#include <libavfilter/avfilter.h>
#include <libavutil/opt.h>
#include <libavfilter/buffersrc.h>
#include <libavfilter/buffersink.h>
};

#include "exception/KPFilterException.h"
#include "util/KPVariables.h"
#include "util/KPEvent.hpp"

#include "config.h"

class KPPluginAdapter {
private:
    AVFilterContext         *filter_context     = nullptr;
    std::string             identify_name;
    std::future<void>       task_future;
    std::condition_variable task_condition;
    std::mutex              task_mutex;
    bool                    killed              = false;

protected:
    std::string                     filter_desc;
    const AVFilter                  *filter     = nullptr;
    std::shared_ptr<spdlog::logger> logger;
    std::string                     filter_name;
    KPFilterType                    filter_type = KP_FILTER_TYPE_NONE;

protected:
    /**
     * 转码后进行的插件执行任务
     */
    virtual void Task() = 0;

    /**
     * 获取avfilter的上下文句柄
     */
    void *GetFilterPriv();

public:
    explicit KPPluginAdapter(std::string identify_name, std::string filter_name, KPFilterType filter_type);
    virtual ~KPPluginAdapter();
    AVFilterContext *GetFilterContext();
    const AVFilter *GetFilter();
    std::string GetFilterName();
    KPFilterType GetFilterType();
    std::string GetIdentifyName();
    std::string GetSignFilterName();
    const std::string &GetFilterDesc();
    void SetFilterContext(AVFilterContext *filter_ctx);
    virtual std::shared_ptr<KPPluginAdapter> GetSiblingFilter();

    /**
     * 调度插件task执行
     */
    void NotifyTask();

    /**
     * 插件销毁时刻停止当前插件task任务回调函数
     * 用于插件的reload事件或插件销毁
     *
     * example: 在显示当前系统事件插件场景中，在reload或remove操作后将会执行该函数
     *          函数需要处理当前Task任务的结束，以便异步任务的结束
     *
     */
    virtual void KillTask() = 0;

    /**
     * 插件数据初始化
     * 用于插件的reload事件或数据初始化
     *
     * example: 在显示当前系统时间插件场景中，在reload之后对插件变量的重置操作
     *          例如在KillTask将定时器停止flag，在此函数中对定时器开启flag进行重置
     */
    virtual void InitTask() = 0;
};


#endif //KPLAYER_KPPLUGINADAPTER_H
