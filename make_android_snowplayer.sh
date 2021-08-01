#!/bin/bash
set -x
root_dir=$(pwd)
#你的NDK路径
NDK=/Users/wangxueke/android/sdk/ndk/22.1.7171670
#编译使用的toolchain
HOST_TAG=darwin-x86_64
#HOST_TAG 的值根据系统修改
#macOS  darwin-x86_64
#Linux   linux-x86_64
#32-bit Windows  windows
#64-bit Windows  windows-x86_64
TOOLCHAIN=$NDK/toolchains/llvm/prebuilt/$HOST_TAG
API=30

CPU=arm64-v8a

cd build

CMAKE $root_dir/src -DANDROID_NDK=$NDK \
        -DCMAKE_TOOLCHAIN_FILE=$NDK/build/cmake/android.toolchain.cmake \
        -DANDROID_ABI="arm64-v8a" \
        -DANDROID_ARM_NEON=ON \
        -DANDROID_TOOLCHAIN=clang \
        -DANDROID_STL=c++_static \
        -DANDROID_PLATFORM=android-19

cd $root_dir