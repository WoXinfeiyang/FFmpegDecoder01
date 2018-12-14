LOCAL_PATH := $(call my-dir)

## 将libavcodec-57.so声明为一个独立模块,这个共享库将被拷贝到 $PROJECT/obj/local 和 $PROJECT/libs/<abi>
include $(CLEAR_VARS)
LOCAL_MODULE := avcodec
LOCAL_SRC_FILES := prebuilt/libavcodec-57.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := avformat
LOCAL_SRC_FILES := prebuilt/libavformat-57.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := avutil
LOCAL_SRC_FILES := prebuilt/libavutil-55.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := swresample
LOCAL_SRC_FILES := prebuilt/libswresample-2.so
include $(PREBUILT_SHARED_LIBRARY)


## libswscale是一个主要用于处理图片像素数据的类库
include $(CLEAR_VARS)
LOCAL_MODULE := swscale
LOCAL_SRC_FILES := prebuilt/libswscale-4.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := fxjFFmpeg
LOCAL_LDLIBS += -llog -lz -landroid
LOCAL_SRC_FILES :=fxj_ffmpeg.c
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include
LOCAL_SHARED_LIBRARIES:= avcodec avformat avutil swresample swscale ## 引用其它模块
include $(BUILD_SHARED_LIBRARY)