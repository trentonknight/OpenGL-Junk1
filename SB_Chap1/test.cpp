#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <ReadShader.h>
using namespace std;
GLuint returnProgram(void);

//global variables
GLuint vbo_triangle;

GLuint returnProgram(void)
{
    string shadeFrag = "test.frag";
    string shadeVert = "test.vert";
    GLuint mainProgram = 0;
    GLint link_ok = 0;

    ReadShader readshader;
    GLuint frag = readshader.readTheFile(shadeFrag,0);
    GLuint vert = readshader.readTheFile(shadeVert,1);

    mainProgram = glCreateProgram();
    glAttachShader(mainProgram, frag);
    glAttachShader(mainProgram, vert);
    glLinkProgram(mainProgram);
    glDeleteShader(vert);
    glDeleteShader(frag);
    glGetProgramiv(mainProgram, GL_LINK_STATUS, &link_ok);
    if (!link_ok) {
        cerr << "glLinkProgram Error:" << endl;
        return 0;
    }

    return mainProgram;
}

int main()
{
        returnProgram();
	return 0;
}
