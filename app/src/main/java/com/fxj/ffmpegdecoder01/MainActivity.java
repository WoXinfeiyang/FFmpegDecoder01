package com.fxj.ffmpegdecoder01;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.widget.Button;

public class MainActivity extends Activity implements SurfaceHolder.Callback{

    private final String TAG=MainActivity.class.getSimpleName();
    private SurfaceView surfaceView;
    private SurfaceHolder surfaceHolder;

    private final String URL="rtsp://184.72.239.149/vod/mp4://BigBuckBunny_175k.mov";

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
                NativePlayer.playVideo(URL,surfaceHolder.getSurface());
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
