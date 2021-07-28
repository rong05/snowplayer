//
// Created by 王雪可 on 2021/7/28.
//
#ifndef SNOWPLAYER_SNOWPLAYERNATIVEEXCEPTION_H
#define SNOWPLAYER_SNOWPLAYERNATIVEEXCEPTION_H
#include <exception>
#include <string>
#include <iostream>

namespace SnowPlayer {
    class SnowPlayerNativeException : public std::exception {
    public:
        explicit SnowPlayerNativeException(const char *msg) : message(msg) {}
        virtual ~SnowPlayerNativeException() throw() {}
        virtual const char *what() const throw() { return message.c_str(); }
    protected:
        const std::string message;
    };
}


#endif //SNOWPLAYER_SNOWPLAYERNATIVEEXCEPTION_H
