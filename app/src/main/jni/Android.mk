LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := fxjFFmpeg
LOCAL_LDLIBS += -llog -lz -landroid
LOCAL_SRC_FILES :=fxj_ffmpeg.c
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include

include $(BUILD_SHARED_LIBRARY)