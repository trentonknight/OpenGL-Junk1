LIBS = -lXxf86vm -lX11 -lglfw3 -lglut -lXi -lpthread -lXrandr -lstdc++ -lm -lGLEW -lGLU -lGL -lrt
CFLAGS= -Wall -ggdb -g3
beta2.o : beta2.cpp vgl.h LoadShaders.h 
	gcc -o $@ $< $(LIBS)
