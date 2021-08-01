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
    class SnowPlayerNullPointerException : SnowPlayerNativeException{
    public:
        virtual ~SnowPlayerNullPointerException() throw() {}
        virtual const char *what() const throw() { return message.c_str(); }
        explicit SnowPlayerNullPointerException(const char *msg) : SnowPlayerNativeException(msg) {}
    };
    class SnowPlayerIOException : SnowPlayerNativeException{
    public:
        explicit SnowPlayerIOException(const char *msg) : SnowPlayerNativeException(msg) {}
        virtual ~SnowPlayerIOException() throw() {}
        virtual const char *what() const throw() { return message.c_str(); }
    };
    class SnowPlayerRuntimeException : SnowPlayerNativeException{
    public:
        explicit SnowPlayerRuntimeException(const char *msg) : SnowPlayerNativeException(msg) {}
        virtual ~SnowPlayerRuntimeException() throw() {}
        virtual const char *what() const throw() { return message.c_str(); }
    };
}


#endif //SNOWPLAYER_SNOWPLAYERNATIVEEXCEPTION_H
