package com.fxj.ffmpegdecoder01;

public class NativePlayer {

    static {
        System.loadLibrary("fxjFFmpeg");
    }

    public native static int playVideo(String url,Object suface);
    public native static String getStringMsg();
}
