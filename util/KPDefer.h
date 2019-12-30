//
// Created by karaler on 2019/12/7.
// Author: karaler
// Description: 
// Others: 
// Copyright (c) 2019 Bytelang . All rights reserved.
//

#ifndef KPLAYER_KPDEFER_H
#define KPLAYER_KPDEFER_H

#include <utility>
#include <functional>

class KPDefer {
protected:
    std::function<void()> defer_func;
public:
    explicit KPDefer(std::function<void()> func);
    ~KPDefer();
};

#define defer(name, fn) auto __defer_ ## name = KPDefer(fn)


#endif //KPLAYER_KPDEFER_H
