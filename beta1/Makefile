LIBS = -lXxf86vm -lX11 -lglapi -lglut -lXi -lpthread -lXrandr -lstdc++ -lm -lGLU -lGL -lrt -lGLEW
CFLAGS= -Wall -ggdb -g3 -DDEBUG
beta1.o : beta1.cpp
	gcc -o $@ $< $(LIBS)
.PHONY: clean

clean:
	rm -f *.o 
