#include <GL/glew.h>
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;
    GLuint vertex_shader;
    GLuint fragment_shader;
    GLuint program;
    GLuint vao = 0;
    GLuint vbo = 0;
    GLuint rendering_program;
    GLuint vertex_array_object;

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

GLuint compile_shaders(void) {

//vertex shader
    static const GLchar * vertex_shader_source[] =
    {
        "#version 300 core \n"
        "		    \n"
        "void main(void)   \n"
        "{                 \n"
        "  gl_Position = vec4(0.0, 0.0, 0.5, 1.0); \n"
        "}                 \n"
    };
//Source code for fragment shader
    static const GLchar * fragment_shader_source[]=
    {
        "#version 300 core \n"
        "                  \n"
        "out vec4 color;   \n"
        "                  \n"
        "{                 \n"
        "  color = vec4(0.0,0.8,1.0,1.0); \n"
        "}                 \n"
    };

//Create and compile vertex
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
    glCompileShader(vertex_shader);
//create an compile frag
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
    glCompileShader(fragment_shader);
//Create program, attach shaders to it, and link it
    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
//Delete the shaders as the program has them now
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return program;
}

void startup()
{

    rendering_program = compile_shaders();
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);
}
void shutdown()
{
    glDeleteVertexArrays(1, &vao);
    glDeleteProgram(rendering_program);
    glDeleteVertexArrays(1, &vao);
}
int render()
{

GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Beta1", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        //const GLfloat color[] = {(float)sin(5) * 0.5f + 0.5f,
	//			 (float)cos(9) * 0.5f + 0.5f,
	//			 0.0f, 1.0f};
	static const GLfloat red[] = {1.0f,0.0f,0.0f,1.0f};
        glClearBufferfv(GL_COLOR, 0, red);
       
        //glUseProgram(rendering_program);
	//glDrawArrays(GL_POINTS, 0, 1);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
int main(void)
{

render();
}


