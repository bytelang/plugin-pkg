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

class KPPluginAdapter {
private:
    AVFilterContext         *filter_context = nullptr;
    std::string             identify_name;
    std::future<int>        task_future;
    std::condition_variable task_condition;
    std::mutex              task_mutex;

protected:
    KPFilterType                    filter_type = KP_FILTER_TYPE_NONE;
    std::string                     filter_name;
    std::string                     filter_desc;
    const AVFilter                  *filter     = nullptr;
    std::shared_ptr<spdlog::logger> logger;

protected:
    virtual int Task() = 0;
    void *GetFilterPriv();

public:
    explicit KPPluginAdapter(std::string identify_name);
    virtual ~KPPluginAdapter();
    AVFilterContext *GetFilterContext();
    const AVFilter *GetFilter();
    std::string GetIdentifyName();
    const KPFilterType &GetFilterType();
    std::string GetFilterName();
    const std::string &GetFilterDesc();
    void SetFilterContext(AVFilterContext *filter_ctx);
    void NotifyTask();
    virtual int KillTask() = 0;
};


#endif //KPLAYER_KPPLUGINADAPTER_H
