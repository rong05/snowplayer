//
// Created by Administrator on 2021/7/29.
//

#ifndef SNOWPLAYER_COMMON_H
#define SNOWPLAYER_COMMON_H


extern "C" {
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS
#endif
#ifndef INT64_C
#define INT64_C(c) (c##LL)
#define UINT64_C(c) (c##ULL)
#endif
#include <libavcodec/version.h>
#include <libavutil/rational.h>
}

#include "utils/Log.h"
#include "exception/SnowPlayerNativeException.h"
#endif //SNOWPLAYER_COMMON_H
