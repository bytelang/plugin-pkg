//
// Created by karaler on 2019-10-30.
// Author: karaler
// Description:
// Others: 
// Copyright (c) 2019 ${ORGANIZATION_NAME}. All rights reserved.
//

#ifndef KPLAYER_KPHELPER_H
#define KPLAYER_KPHELPER_H

#include <string>
#include <utility>
#include <vector>
#include <sstream>

#include "config.h"

namespace KPlayer {
    class FileInfo {
    protected:
        std::string file_path;
        std::string file_name;
        std::string file_base_name;
        std::string file_extension;
    protected:
        void SearchFileName();
        void SearchFileExtension();
    public:
        explicit FileInfo(std::string);
        virtual ~FileInfo();
        std::string GetFilePath();
        std::string GetFileName();
        std::string GetBaseFileName();
        std::string GetFileExtension();
    };

    class String {
    public:
        static std::vector<std::string> Split(const std::string &s, char delimiter);
    };
}


#endif //KPLAYER_KPHELPER_H
