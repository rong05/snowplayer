//
// Created by Administrator on 2021/7/29.
//

#ifndef SNOWPLAYER_LOG_H
#define SNOWPLAYER_LOG_H

#include <android/log.h>
#include <string.h>

//#define DEBUG // 可以通过 CmakeLists.txt 等方式来定义在这个宏，实现动态打开和关闭LOG

// Windows 和 Linux 这两个宏是在 CMakeLists.txt 通过 ADD_DEFINITIONS 定义的
#ifdef Windows
#define __FILENAME__ (strrchr(__FILE__, '\\') + 1) // Windows下文件目录层级是'\\'
#elif Linux
#define __FILENAME__ (strrchr(__FILE__, '/') + 1) // Linux下文件目录层级是'/'
#else
#define __FILENAME__ (strrchr(__FILE__, '/') + 1) // 默认使用这种方式
#endif

#define V 6
#define D 5
#define I 4
#define W 3
#define E 2

#define LogLevel D

#ifdef Windows
//define something for Windows (32-bit and 64-bit, this part is common)
#define LOGV(format, ...) ;
#define LOGD(format, ...) ;
#define LOGI(format, ...) ;
#define LOGW(format, ...) ;
#define LOGE(format, ...) ;
#ifdef _WIN64
//define something for Windows (64-bit only)
#else
//define something for Windows (32-bit only)
#endif
#elif __APPLE__
#include "TargetConditionals.h"
#if TARGET_IPHONE_SIMULATOR
// iOS Simulator
#elif TARGET_OS_IPHONE
// iOS device
#elif TARGET_OS_MAC
// Other kinds of Mac OS
#else
#error "Unknown Apple platform"
#endif
#define LOGV(format, ...) ;
#define LOGD(format, ...) ;
#define LOGI(format, ...) ;
#define LOGW(format, ...) ;
#define LOGE(format, ...) ;
#elif ANDROID
// android
#define LOG_TAG "snow_player"
#define LOGV(format, ...)                                                                        \
        if (LogLevel >= V)                                                                       \
        {                                                                                        \
                __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG,                                \
                                    "[%s][%d]: " format, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
        };
#define LOGD(format, ...)                                                                        \
        if (LogLevel >= D)                                                                       \
        {                                                                                        \
                __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG,                                  \
                                    "[%s][%d]: " format, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
        };
#define LOGI(format, ...)                                                                        \
        if (LogLevel >= I)                                                                       \
        {                                                                                        \
                __android_log_print(ANDROID_LOG_INFO, LOG_TAG,                                   \
                                    "[%s][%d]: " format, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
        };
#define LOGW(format, ...)                                                                        \
        if (LogLevel >= W)                                                                       \
        {                                                                                        \
                __android_log_print(ANDROID_LOG_WARN, LOG_TAG,                                   \
                                    "[%s][%d]: " format, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
        };
#define LOGE(format, ...)                                                                        \
        if (LogLevel >= E)                                                                       \
        {                                                                                        \
                __android_log_print(ANDROID_LOG_ERROR, LOG_TAG,                                  \
                                    "[%s][%d]: " format, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
        };
#elif Linux
// linux
#define LOG_CLRSTR_NONE "\033[m"
#define LOG_CLRSTR_RED "\033[0;32;31m"
#define LOG_CLRSTR_GREEN "\033[0;32;32m"
#define LOG_CLRSTR_BLUE "\033[0;32;34m"
#define LOG_CLRSTR_DARY_GRAY "\033[1;30m"
#define LOG_CLRSTR_CYAN "\033[0;36m"
#define LOG_CLRSTR_PURPLE "\033[0;35m"
#define LOG_CLRSTR_BROWN "\033[0;33m"
#define LOG_CLRSTR_YELLOW "\033[1;33m"
#define LOG_CLRSTR_WHITE "\033[1;37m"
#define LOGV(format, ...)                      \
        if (LogLevel >= V)                     \
        {                                      \
                printf(LOG_CLRSTR_NONE);       \
                printf(format, ##__VA_ARGS__); \
                printf(LOG_CLRSTR_NONE);       \
        };

#define LOGD(format, ...)                      \
        if (LogLevel >= D)                     \
        {                                      \
                printf(LOG_CLRSTR_GREEN);      \
                printf(format, ##__VA_ARGS__); \
                printf(LOG_CLRSTR_NONE);       \
        };
#define LOGI(format, ...)                      \
        if (LogLevel >= I)                     \
        {                                      \
                printf(LOG_CLRSTR_PURPLE);     \
                printf(format, ##__VA_ARGS__); \
                printf(LOG_CLRSTR_NONE);       \
        };
#define LOGW(format, ...)                      \
        if (LogLevel >= W)                     \
        {                                      \
                printf(LOG_CLRSTR_WHITE);      \
                printf(format, ##__VA_ARGS__); \
                printf(LOG_CLRSTR_NONE);       \
        };
#define LOGE(format, ...)                      \
        if (LogLevel >= E)                     \
        {                                      \
                printf(LOG_CLRSTR_RED);        \
                printf(format, ##__VA_ARGS__); \
                printf(LOG_CLRSTR_NONE);       \
        };
#else
#error "Unknown compiler"
#define LOGV(format, ...) ;
#define LOGD(format, ...) ;
#define LOGI(format, ...) ;
#define LOGW(format, ...) ;
#define LOGE(format, ...) ;
#endif

#endif //SNOWPLAYER_LOG_H
