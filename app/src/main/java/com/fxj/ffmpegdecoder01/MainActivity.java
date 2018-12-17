package com.fxj.ffmpegdecoder01;

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import java.io.File;

public class MainActivity extends Activity implements SurfaceHolder.Callback{

    private final String TAG=MainActivity.class.getSimpleName();
    private SurfaceView surfaceView;
    private SurfaceHolder surfaceHolder;

    private final String URL1="rtsp://184.72.239.149/vod/mp4://BigBuckBunny_175k.mov";

    private final String URL2=Environment.getExternalStorageDirectory()+ File.separator+"cuc_ieschool.mp4";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        surfaceView = findViewById(R.id.surface_view);
        surfaceHolder = surfaceView.getHolder();

        surfaceHolder.addCallback(this);
        Log.d(TAG,"URL2="+URL2);
    }


    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        Log.d(TAG,"**MainActivity.surfaceCreated**");
        new Thread(new Runnable() {
            @Override
            public void run() {
                NativePlayer.playVideo(URL1,surfaceHolder.getSurface());
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
