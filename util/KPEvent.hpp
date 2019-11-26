//
// Created by karaler on 2019-10-29.
// Author: karaler
// Description:
// Others: 
// Copyright (c) 2019 ${ORGANIZATION_NAME}. All rights reserved.
//

#ifndef KPLAYER_KPEVENT_HPP
#define KPLAYER_KPEVENT_HPP

#include <condition_variable>
#include <vector>
#include <map>
#include <thread>
#include <atomic>

template<typename T>
class KPEvent {
protected:
    std::map <uint64_t, std::function<void(T)>> listeners;
    std::atomic<int>                            m_atomic_eid;
    T                                           variable;
public:
    KPEvent();
    void Publish(T);
    uint64_t Subscribe(std::function<void(T)>);
    void Unsubscribe(int);
    T GetLastVariable();
};

template<typename T>
void KPEvent<T>::Publish(T params) {
    // 记录上次params
    variable = params;
    // 开辟子线程处理事件调用
    for (auto &item : listeners) {
        std::thread([&] {
            item.second(params);
        }).detach();
    }
}

template<typename T>
uint64_t KPEvent<T>::Subscribe(std::function<void(T)> fn) {
    m_atomic_eid++;
    listeners.insert({m_atomic_eid, fn});
    return m_atomic_eid;
}

template<typename T>
KPEvent<T>::KPEvent() {
    m_atomic_eid = 0;
}

template<typename T>
void KPEvent<T>::Unsubscribe(int eid) {
    auto it = listeners.find(eid);
    // 未找到对应的id
    if (it == listeners.end())
        return;

    listeners.erase(it);
}

template<typename T>
T KPEvent<T>::GetLastVariable() {
    return variable;
}


#endif //KPLAYER_KPEVENT_HPP
