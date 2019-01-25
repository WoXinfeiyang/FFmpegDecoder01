package com.fxj.ffmpegdecoder01;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

public class MainActivity extends Activity implements SurfaceHolder.Callback{

    private final String TAG=MainActivity.class.getSimpleName();
    private SurfaceView surfaceView;
    private SurfaceHolder surfaceHolder;
    /**CCTV1高清*/
    private final String URL1="http://ivi.bupt.edu.cn/hls/cctv1hd.m3u8";
    /**CCTV3高清*/
    private final String URL2="http://ivi.bupt.edu.cn/hls/cctv3hd.m3u8";
    /**CCTV5高清*/
    private final String URL3="http://ivi.bupt.edu.cn/hls/cctv5hd.m3u8";
    /**CCTV5+高清*/
    private final String URL4="http://ivi.bupt.edu.cn/hls/cctv5phd.m3u8";
    /**CCTV6高清*/
    private final String URL5 ="http://ivi.bupt.edu.cn/hls/cctv6hd.m3u8";

    /**TVB翡翠台*/
    private final String URL6="http://123.207.42.38/tvb.php?type=jade";
    /**凤凰卫视中文台*/
    private final String URL7="http://111.13.42.13/PLTV/88888888/224/3221225942/1.m3u8";
    /**香港电视*/
    private final String URL8="http://media.fantv.hk/m3u8/archive/channel2.m3u8";
    /**大熊兔（点播）*/
    private final String URL9="rtsp://184.72.239.149/vod/mp4://BigBuckBunny_175k.mov";
    /**苹果测试源*/
    private final String URL10="http://devimages.apple.com.edgekey.net/streaming/examples/bipbop_4x3/gear2/prog_index.m3u8";
    /**CCTV1高清rtsp源*/
    private final String URL11="rtsp://120.205.96.36:554/live/ch16022919053041099962.sdp?playtype=1&boid=001&backupagent=120.205.32.36:554&clienttype=1&time=20161205230814+08&life=172800&ifpricereqsnd=1&vcdnid=001&userid=&mediaid=ch16022919053041099962&ctype=2&TSTVTimeLife=60&contname=&authid=0&terminalflag=1&UserLiveType=0&stbid=&nodelevel=3";
    private final String URL12="http://ips.ifeng.com/video19.ifeng.com/video09/2019/01/09/4966943-102-007-1715.mp4";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        surfaceView = findViewById(R.id.surface_view);
        surfaceHolder = surfaceView.getHolder();

        surfaceHolder.addCallback(this);
    }


    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        Log.d(TAG,"**MainActivity.surfaceCreated**");
        new Thread(new Runnable() {
            @Override
            public void run() {
                NativePlayer.playVideo(URL5,surfaceHolder.getSurface());
            }
        }).start();
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        Log.d(TAG,"**MainActivity.surfaceChanged**");
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        Log.d(TAG,"**MainActivity.surfaceDestroyed**");
    }
}
