#ifdef GL_ES_VERSION_2_0
##version 100
##else
##version 120
##endif
attribute vec2 newPosition;
void main(void) {
gl_Position = vec4(newPosition, 0.0, 1.0);
}


