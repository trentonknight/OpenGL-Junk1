#ifdef GL_ES_VERSION_2_0
#version 100
#else
#version 120
#endif
varying vec3 f_color;
void main(void) {
    gl_FragColor = vec4(f_color.x, f_color.y, f_color.z, 1.0);
}


