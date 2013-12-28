#ifdef GL_ES_VERSION_2_0
    #version 100
#else
    #version 120 
#endif
    void main(void) {        
      gl_FragColor[0] = 0.0; 
      gl_FragColor[1] = 0.0; 
      gl_FragColor[2] = 1.0; 
    }

