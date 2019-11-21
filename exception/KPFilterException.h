//
// Created by karaler on 2019-09-02.
// Author: karaler
// Description:
// Others: 
// Copyright (c) 2019 ${ORGANIZATION_NAME}. All rights reserved.
//

#ifndef KPLAYER_KPFILTEREXCEPTION_H
#define KPLAYER_KPFILTEREXCEPTION_H

#include <string>

class KPFilterException : public std::exception {
protected:
    std::string error;
    int         error_code;
public:
    explicit KPFilterException(const std::string &);
    explicit KPFilterException(const std::string &, const int error_code);
    std::string GetError();
};


#endif //KPLAYER_KPFILTEREXCEPTION_H
