LIBS = -lXxf86vm -lGLU -lX11 -lglfw3 -lGL -lXi -lpthread -lXrandr -lstdc++ -lm -lGLEW
test.o : test.cpp ReadShader.h
	gcc -o $@ $< $(LIBS)
