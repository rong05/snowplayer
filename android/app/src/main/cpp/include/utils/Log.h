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

#ifdef DEBUG
#define LOG_TAG "snow_player"
#define LOGV(format, ...) \
        if(LogLevel>= V) {         \
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, \
        "[%s][%d]: " format, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
         };
#define LOGD(format, ...) \
        if(LogLevel>= D) {         \
          __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, \
        "[%s][%d]: " format, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
        };
#define LOGI(format, ...) \
        if(LogLevel>= I) {         \
            __android_log_print(ANDROID_LOG_INFO, LOG_TAG, \
            "[%s][%d]: " format, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
        };
#define LOGW(format, ...) \
        if(LogLevel>= W) {              \
            __android_log_print(ANDROID_LOG_WARN, LOG_TAG, \
            "[%s][%d]: " format, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
        };
#define LOGE(format, ...) \
        if(LogLevel>= E) {                  \
            __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, \
            "[%s][%d]: " format, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
        };
#else
#define LOGV(format, ...);
#define LOGD(format, ...);
#define LOGI(format, ...);
#define LOGW(format, ...);
#define LOGE(format, ...);
#endif // DEBUG


#endif //SNOWPLAYER_LOG_H
