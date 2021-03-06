# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.
#set(DIR ../../../../libs)

project("snowplayer")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
# 支持gnu++11
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
# Declares and names the project.
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-D__STDC_CONSTANT_MACROS")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR IS ${CMAKE_CURRENT_SOURCE_DIR}")
# 1. 定义so库和头文件所在目录，方面后面使用
set(ffmpeg_lib_dir ${CMAKE_CURRENT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})
#set(ffmpeg_head_dir ${CMAKE_CURRENT_SOURCE_DIR})

# 2. 添加头文件目录
include_directories(include)

# 3. 添加ffmpeg相关的so库
add_library(avutil
        SHARED
        IMPORTED)
set_target_properties(avutil
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libavutil.so)

add_library(swresample
        SHARED
        IMPORTED)
set_target_properties(swresample
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libswresample.so)

add_library(avcodec
        SHARED
        IMPORTED)
set_target_properties(avcodec
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libavcodec.so)

add_library(avfilter
        SHARED
        IMPORTED)
set_target_properties(avfilter
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libavfilter.so)

add_library(swscale
        SHARED
        IMPORTED)
set_target_properties(swscale
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libswscale.so)

add_library(avformat
        SHARED
        IMPORTED)
set_target_properties(avformat
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libavformat.so)

# 查找当前目录所有源文件 并将名称保存到 DIR_SRCS 变量
# 注意这样不能查找子目录，也不会自动往子目录找
#aux_source_directory(src DIR_SRCS)
# 或者也可以使用如果通配符的方式，引入所有.c文件，同样保存到 DIR_SRCS变量中
file(GLOB_RECURSE DIR_SRCS src/*.c)
#file(GLOB DIR_SRCS *.cpp)
file(GLOB_RECURSE SRC_LIST  src/*.cpp)
file(GLOB_RECURSE SRC_LIST_INLUDE  include/*.h)

#add_library( avdevice
#        SHARED
#        IMPORTED)
#set_target_properties( avdevice
#        PROPERTIES IMPORTED_LOCATION
#        ${ffmpeg_lib_dir}/libavdevice.so )
IF (${CMAKE_HOST_SYSTEM_NAME} MATCHES "Windows")
    ADD_DEFINITIONS(-DWindows)
ELSE (${CMAKE_HOST_SYSTEM_NAME} MATCHES "Linux")
    ADD_DEFINITIONS(-DLinux)
ENDIF ()

ADD_DEFINITIONS(-DDEBUG)

add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED
        ${DIR_SRCS}
        ${SRC_LIST}
        ${SRC_LIST_INLUDE}
        # Provides a relative path to your source file(s).
        )

#message(${SRC_LIST})
# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

#include_directories(
#        include
#)

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        native-lib

        android
        jnigraphics
        # 4. 连接 FFmpeg 相关的库
        avutil
        swresample
        avcodec
        avfilter
        swscale
        avformat
        #avdevice
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})