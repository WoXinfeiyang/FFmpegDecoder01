#include<jni.h>
#include<stdio.h>
#include <string.h>

#include"com_fxj_ffmpegdecoder01_NativePlayer.h"

#include"log.h"


/*
 * Class:     com_fxj_ffmpegdecoder01_NativePlayer
 * Method:    playVideo
 * Signature: (Ljava/lang/String;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_fxj_ffmpegdecoder01_NativePlayer_playVideo(JNIEnv *env, jclass obj, jstring url, jobject suface)
{
    const char *tag="playVideo";
    LogD(tag,"start playvideo... url");
    return 1;
}

/*
 * Class:     com_fxj_ffmpegdecoder01_NativePlayer
 * Method:    getStringMsg
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_fxj_ffmpegdecoder01_NativePlayer_getStringMsg(JNIEnv *env, jclass obj){
    LogD("NativePlayer","NativePlayer_getStringMsg");
    const char* msg="NativePlayer_getStringMsg";
    return (*env)->NewStringUTF(env,"NativePlayer_getStringMsg");
}


