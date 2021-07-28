//
// Created by Administrator on 2021/7/28.
//

#ifndef SNOWPLAYER_AVINFORMATION_H
#define SNOWPLAYER_AVINFORMATION_H
extern "C" {
#include <libavformat/avformat.h>c
}
namespace SnowPlayer {

    class AVInFormation {
    public:
        AVInFormation();

        ~AVInFormation();

        /**
         * Custom interrupt callbacks for the I/O layer.
         *
         * demuxing: set by the user before avformat_open_input().
         * muxing: set by the user before avformat_write_header()
         * (mainly useful for AVFMT_NOFILE formats). The callback
         * should also be passed to avio_open2() if it's used to
         * open the file.
         * @param interruptCB
         * @param opaque
         */
        void setAVIOInterruptCB(int(*interruptCB)(void *), void *opaque) {
            if (input_AVFormat_context_) {
                input_AVFormat_context_->interrupt_callback.callback = interruptCB;
                input_AVFormat_context_->interrupt_callback.opaque = opaque;
            }
        }

    private:
        AVFormatContext *input_AVFormat_context_;
    };
}
#endif //SNOWPLAYER_AVINFORMATION_H
