/**
 * From the OpenGL Programming wikibook: http://en.wikibooks.org/wiki/OpenGL_Programming
 * This file is in the public domain.
 * Contributors: Sylvain Beucler
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
/* Use glew.h instead of gl.h to get all the GL prototypes declared */
#include <GL/glew.h>
/* Using the GLUT library for the base windowing setup */
#include <GL/glut.h>
#include <ReadShader.h>

using namespace std;

GLuint program;
GLint attribute_coord2d, attribute_v_color;
GLuint vbo_triangle, vbo_triangle_colors;

int init_resources()
{
    ReadShader readshader;

    GLint link_ok = GL_FALSE;

    GLuint vs = readshader.readTheFile("triangle.vert",1);
    GLuint fs = readshader.readTheFile("triangle.frag",0);

    program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glDeleteShader(vs);
    glDeleteShader(fs);
    glGetProgramiv(program, GL_LINK_STATUS, &link_ok);
    if (!link_ok) {
        cerr << "glLinkProgram Error:" << endl;
        return 0;
    }

    const char* attribute_name = "coord2d";
    attribute_coord2d = glGetAttribLocation(program, attribute_name);
    if (attribute_coord2d == -1) {
        cerr << "Could not bind attribute: " << attribute_name << endl;
        return 0;
    }



    return 0;
}

void onDisplay()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(program);
    //attribute stuff
    glEnableVertexAttribArray(attribute_coord2d);
    GLfloat triangle_vertices[] = {
	    0.0, 0.8,
	    -0.8, -0.8,
	    0.8, -0.8,
    };
    /* Describe our vertices array to OpenGL (it can't guess its format automatically) */
    glVertexAttribPointer(
        attribute_coord2d, // attribute
        2,                 // number of elements per vertex, here (x,y)
        GL_FLOAT,          // the type of each element
        GL_FALSE,          // take our values as-is
        0,//sizeof(struct attributes),                 // no extra data between each position
	triangle_vertices
    );



    /* Push each element in buffer_vertices to the vertex shader */
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(attribute_coord2d);
    glutSwapBuffers();
}

void free_resources()
{
    glDeleteProgram(program);
    //glDeleteBuffers(1, &vbo_triangle);
}


int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_ALPHA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Custom Triangle");

    GLenum glew_status = glewInit();
    if (glew_status != GLEW_OK) {
        cout << "Error: " << glewGetErrorString(glew_status) << endl;
        return 1;
    }

    if (!init_resources()) {
        glutDisplayFunc(onDisplay);
        glutMainLoop();
    }

    free_resources();
    return 0;
}


