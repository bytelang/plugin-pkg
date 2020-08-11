//
// Created by karaler on 2019-10-30.
// Author: karaler
// Description: 提供帮助方法。FileInfo类
// Others: 
// Copyright (c) 2019 ${ORGANIZATION_NAME}. All rights reserved.
//

#ifndef KPLAYER_KPHELPER_H
#define KPLAYER_KPHELPER_H

#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <fstream>

#include "util/KPDefer.h"

#include "config.h"

namespace KPlayer {
    /**
     * 文件信息帮助类
     */
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
        /**
         * 获取文件完整路径
         * @return
         */
        std::string GetFilePath();

        /**
         * 获取文件路径
         */
         std::string GetBaseFilePath();

        /**
         * 获取不包含目录的文件路径
         * @return
         */
        std::string GetFileName();

        /**
         * 获取不包含目录且不包含扩展的文件名
         * @return
         */
        std::string GetBaseFileName();

        /**
         * 获取文件扩展名
         * @return
         */
        std::string GetFileExtension();

        /**
         * 判断文件是否存在
         * @return
         */
        bool Exists();
        int Data(std::vector<uint8_t> &data);
        int SetData(const std::vector<uint8_t> &data);
    };

    /**
     * 字符串帮助类
     */
    class String {
    public:
        static std::vector<std::string> Split(const std::string &s, char delimiter);
    };

    /**
     * 内存释放帮助方法
     */
    template<typename T>
    void KPDelete(T *&p, bool is_array = false) {
        if (p == nullptr)
            return;

        if (is_array) {
            delete[] p;
        } else {
            delete p;
        }

        p = nullptr;
    }
}


#endif //KPLAYER_KPHELPER_H
