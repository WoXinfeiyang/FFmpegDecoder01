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
    /*将jstring对象转换成UTF-8格式的字符串,得到一个字符指针变量char**/
    const char *mUrl= (*env)->GetStringUTFChars(env,url,0);
    LogD(tag,"start playvideo... url=%s",mUrl);

    (*env)->ReleaseStringUTFChars(env,url,mUrl);/*释放指向UTF-8格式的cha *指针变量mUrl*/
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


