#include "file/AVInFormation.h"
#include "exception/SnowPlayerNativeException.h"

namespace SnowPlayer{
    AVInFormation::AVInFormation() {
        input_AVFormat_context_ = avformat_alloc_context();
        if(input_AVFormat_context_ == nullptr){
            throw SnowPlayerNullPointerException("avformat alloc context is nullptr !");
        }
    }

    AVInFormation::~AVInFormation() {
        avformat_close_input(&input_AVFormat_context_);
    }

}
