#include <stdio.h>
#include "utils/Log.h"

int main(int argc, char **argv)
{
#ifdef Windows
    LOGD("system is %s", "Windows");
#elif Linux
    LOGD("system is %s", "Linux");
#elif ANDROID
    LOGD("system is %s", "Android");
#else
    LOGD("system is Unknown compiler");
#endif
    return 0;
}