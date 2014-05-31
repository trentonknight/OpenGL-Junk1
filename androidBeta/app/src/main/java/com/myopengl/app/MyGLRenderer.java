package com.myopengl.app;

import android.opengl.GLES20;
import android.opengl.GLSurfaceView;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by trentonknight on 5/30/14.
 */
public class MyGLRenderer implements GLSurfaceView.Renderer{
    private Triangle mTriangle;
    private Square   mSquare;

    public void onSurfaceCreated(GL10 unused, EGLConfig config){
        GLES20.glClearColor(0.0f,0.0f,0.0f,1.0f);
    }

    public void onDrawFrame(GL10 unused){
        GLES20.glClear(GLES20.GL_COLOR_BUFFER_BIT);
    }
    public void onSurfaceChanged(GL10 unused, int width, int height){
        GLES20.glViewport(0,0,width,height);
        // initialize a triangle
        mTriangle = new Triangle();
        // initialize a square
        mSquare = new Square();
    }

public static int loadShader(int type, String shaderCode){
 int shader = GLES20.glCreateShader(type);
 GLES20.glShaderSource(shader, shaderCode);
 GLES20.glCompileShader(shader);
    return shader;
}
}
