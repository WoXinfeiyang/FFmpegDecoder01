#ifndef LOG_H
#define LOG_H

#include <android/log.h>

#define LogI(tag,...) __android_log_print(ANDROID_LOG_INFO,tag,__VA_ARGS__)
#define LogD(tag,...) __android_log_print(ANDROID_LOG_DEBUG,tag,__VA_ARGS__);
#define LogW(tag,...) __android_log_print(ANDROID_LOG_WARN,tag,__VA_ARGS__)
#define LogE(tag,...) __android_log_print(ANDROID_LOG_ERROR,tag,__VA_ARGS__);

#endif //LOG_H
