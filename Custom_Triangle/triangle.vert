#ifdef GL_ES_VERSION_2_0
#version 100
#else
#version 120
#endif
attribute vec2 coord2d;
void main(void) {
    gl_Position = vec4(coord2d, 0.0, 1.0);
}


