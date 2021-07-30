cmake_minimum_required(VERSION 3.6.0)
#NDK-file-path
set(ANDROID_NDK "/mnt/d/learn/android-ndk-r22b")
set(CMAKE_TOOLCHAIN_FILE ${ANDROID_NDK}/build/cmake/android.toolchain.cmake)
set(CMAKE_MAKE_PROGRAM /usr/bin/ninja)
set(CMAKE_GENERATOR "Ninja")
#Android-api
set(ANDROID_NATIVE_API_LEVEL 30)
#Android system abi
set(ANDROID_ABI arm64-v8a)
#variables
set(ANDROID_TOOLCHAIN clang)
#use c++_static
set(ANDROID_STL c++_static)



set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../out/${CMAKE_SYSTEM_NAME}/${ANDROID_API})

set(CMAKE_CACHEFILE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../build/${CMAKE_SYSTEM_NAME}/${ANDROID_ABII})