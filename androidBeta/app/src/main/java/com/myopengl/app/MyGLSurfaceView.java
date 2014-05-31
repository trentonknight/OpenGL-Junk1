package com.myopengl.app;

import android.opengl.GLSurfaceView;
import android.content.Context;

/**
 * Created by trentonknight on 5/30/14.
 */
public class MyGLSurfaceView extends GLSurfaceView{
    public MyGLSurfaceView(Context context){
        super(context);
        setEGLContextClientVersion(2);
        setRenderer(new MyGLRenderer());
        setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);

    }
}
