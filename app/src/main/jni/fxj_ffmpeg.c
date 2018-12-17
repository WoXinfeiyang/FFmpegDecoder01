#include<jni.h>
#include<stdio.h>
#include <string.h>
#include <libavformat/avformat.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <libavutil/imgutils.h>
#include "libswscale/swscale.h"
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
    const char *mUrl= (*env)->GetStringUTFChars(env,url,JNI_FALSE);
    LogD(tag,"start playvideo... url=%s",mUrl);

    /*注册所有组件*/
    av_register_all();

    /*创建一个指向AVFormateContext的指针变量*/
    AVFormatContext * pFormateContext= avformat_alloc_context();

    if(avformat_open_input(&pFormateContext,mUrl,NULL,NULL)!=0){
        LogE(tag,"Couldn't open file:%s\n",mUrl);
        return -1;
    }

    if(avformat_find_stream_info(pFormateContext,NULL)<0){
        LogE(tag,"Couldn't find stream info!");
        return -1;
    }

    int videoStreamIndex=-1;
    int i;
    for(i=0;i<pFormateContext->nb_streams;i++){
        if(pFormateContext->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO&&videoStreamIndex<0){
            videoStreamIndex=i;
        }
    }

    LogD(tag,"videoStreamIndex=%d\n",videoStreamIndex);
    if(videoStreamIndex<0){
        LogE(tag,"Not find video stream!");
        return -1;
    }

    /*创建一个指向AVCodecContext的指针变量*/
    AVCodecContext * pCodecContext=pFormateContext->streams[videoStreamIndex]->codec;
    if(pCodecContext==NULL){
        LogE(tag,"Not find AVCodecContext!");
        return -1;
    }

    /*查找解码器,创建一个指向AVCodec的指针变量*/
    AVCodec *pCodec=avcodec_find_decoder(pCodecContext->codec_id);
    if(pCodec==NULL){
        LogE(tag,"Not find vodeo codec!")
        return -1;
    }

    /*打开解码器*/
    if(avcodec_open2(pCodecContext,pCodec,NULL)<0){
        LogE(tag,"Cann't open codec!");
        return -1;
    }

    /*获取android.view.Surface对象对应的ANativeWindow对象*/
    ANativeWindow* pNativeWiondow=ANativeWindow_fromSurface(env,suface);

    int width=pCodecContext->width;
    int height=pCodecContext->height;
    LogD(tag,"video width=%d,height=%d\n",width,height);

    ANativeWindow_setBuffersGeometry(pNativeWiondow,width,height,WINDOW_FORMAT_RGBA_8888);

    /*打开解码器*/
    if(avcodec_open2(pCodecContext,pCodec,NULL)<0){
        LogE(tag,"Cann't open codec!");
        return -1;
    }

    /*创建一个指向AVFrame的指针对象,video Frame*/
    AVFrame* pFrame=av_frame_alloc();
    /*创建用于渲染的AVFrame指针对象*/
    AVFrame* pFrameRGB=av_frame_alloc();
    if(pFrame==NULL||pFrameRGB==NULL){
        LogE(tag,"Could not allocate video frame.");
        return -1;
    }

    /*存储一帧格式为RGBA的图像所需大小*/
    int numBytes=av_image_get_buffer_size(AV_PIX_FMT_RGBA,width,height,1);
    uint8_t *buffer=(uint8_t*)av_malloc(numBytes*(sizeof(uint8_t)));

    av_image_fill_arrays(pFrameRGB->data,pFrameRGB->linesize,buffer,AV_PIX_FMT_RGBA,width,height,1);

    struct SwsContext *swsContext= sws_getContext(pCodecContext->width,
                   pCodecContext->height,
                   pCodecContext->pix_fmt,
                   pCodecContext->width,
                   pCodecContext->height,
                   AV_PIX_FMT_RGBA,
                   SWS_BILINEAR,
                   NULL,
                   NULL,
                   NULL);


    avformat_free_context(pFormateContext);/*释放掉AVFormateContext变量*/
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


