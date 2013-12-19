LIBS = -lXxf86vm -lX11 -lglfw3 -lXi -lpthread -lXrandr -lstdc++ -lm -lGLEW -lGLU -lGL -lrt
CFLAGS= -Wall -ggdb -g3
test.o : test.cpp ReadShader.h
	gcc -o $@ $< $(LIBS)
