#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "ReadShader.h"
using namespace std;
static void error_callback(int error, const char* description)
{
fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
string shadeFrag = "test.frag";
string vertFrag = "test.vert";

GLFWwindow* window;

ReadShader readshader;
readshader.readTheFile(shadeFrag);
///readshader.readTheFile(vertFrag);

glfwSetErrorCallback(error_callback);

/* Initialize the library */
if (!glfwInit())
return -1;

/* Create a windowed mode window and its OpenGL context */
window = glfwCreateWindow(640, 480, "GLEW TESTING FOOL", NULL, NULL);
if (!window)
{
glfwTerminate();
return -1;
}

/* Make the window's context current */
glfwMakeContextCurrent(window);
GLenum err = glewInit();
if (GLEW_OK != err)
{
/* Problem: glewInit failed, something is seriously wrong. */
cout << glewGetErrorString(err);
}
cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION);

/* Loop until the user closes the window */
while (!glfwWindowShouldClose(window))
{
float ratio;
int width, height;

glfwGetFramebufferSize(window, &width, &height);
ratio = width / (float) height;
glViewport(0, 0, width, height);
static const GLfloat color[] = {1.0f, 0.0f, 0.0f, 1.0f};
//glClearColor(1.0f, 0.0f,0.0f,1.0f);
glClearBufferfv(GL_COLOR, 0 ,color);
//glClear(GL_COLOR_BUFFER_BIT);
glEnd();

/* Swap front and back buffers */
glfwSwapBuffers(window);

/* Poll for and process events */
glfwPollEvents();
}
glfwDestroyWindow(window);
glfwTerminate();
exit(EXIT_SUCCESS);
return 0;
}
