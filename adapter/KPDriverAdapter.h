//
// Created by karaler on 2019/12/21.
// Author: karaler
// Description: 
// Others: 
// Copyright (c) 2019 Bytelang . All rights reserved.
//

#ifndef KPLAYER_KPDRIVERADAPTER_H
#define KPLAYER_KPDRIVERADAPTER_H

#include <string>
#include <cmath>

#include "util/KPVariables.h"
#include "adapter/KPPluginAdapter.h"
#include "connect/signle/widgets/KPSingleOutput.h"
#include "util/KPLoadPlugin.h"
#include "util/KPInput.h"

class KPDriverAdapter {
public:
    KPDriverAdapter() = default;
    virtual ~KPDriverAdapter() = default;
    virtual std::vector<KPInput> GetPlayList() = 0;
    virtual KPInput GetCurrentPlayMedia() = 0;
    virtual bool GetCurrentPlayMediaCacheHit() = 0;
    virtual double_t GetCurrentPlayMediaSeekTime() = 0;
    virtual double_t GetCurrentPlayMediaDuration() = 0;
    virtual int SkipCurrentPlayMedia() = 0;
    virtual int PauseCurrentPlayMedia() = 0;
    virtual int ContinueCurrentPlayMedia() = 0;
    virtual KPDecodeStatus GetCurrentPlayerStatus() = 0;
    virtual std::vector<std::shared_ptr<KPSingleOutput>> GetOutputList() = 0;
    virtual int RemoveOutput(const std::string &) = 0;
    virtual int AddOutput(const std::string &) = 0;
    virtual double_t GetRunTime() = 0;
    virtual std::vector<std::shared_ptr<KPPluginAdapter>> GetPluginList() = 0;
    virtual int InsertPlugin(PluginParamsObject) = 0;
    virtual int RemovePlugin(const std::string &unique_name) = 0;
    virtual int SendPlugin(const std::string &unique_name, AVDictionary *) = 0;
    virtual bool GetPlayerAutoConnectionOption() = 0;
    virtual bool GetPlayerCacheUseOption() = 0;
    virtual std::string GetPlayerCachePathOption() = 0;
    virtual int InsertPlayMedia(KPInput input) = 0;
    virtual int InsertPlayMedia(KPInput input, int64_t pos) = 0;
    virtual int RemovePlayMedia(std::string unique) = 0;
    virtual int GetNextPlayMediaIndex() = 0;
    virtual int GetLoopPlayMediaCount() = 0;
};

#endif //KPLAYER_KPDRIVERADAPTER_H
