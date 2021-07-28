//
// Created by Administrator on 2021/7/28.
//

#ifndef SNOWPLAYER_AVINFORMATION_H
#define SNOWPLAYER_AVINFORMATION_H
extern "C" {
    #include <libavformat/avformat.h>
}

class AvInFormation {
public:
    AvInFormation();
    ~AvInFormation();
private:
    AVFormatContext* input_AVFormat_context_;
};


#endif //SNOWPLAYER_AVINFORMATION_H
