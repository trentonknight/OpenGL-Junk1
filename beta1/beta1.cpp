#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
using namespace std;


GLuint vertex_shader;
GLuint fragment_shader;
GLuint program;
GLuint vao = 0;
GLuint vbo = 0;
GLuint rendering_program;
GLuint vertex_array_object;


GLuint compile_shaders(void) {

    GLint link_ok, vertex_ok, frag_ok = 0;

//vertex shader
    static const GLchar * vertex_shader_source[] =
    {
#ifdef GL_ES_VERSION_2_0
        "#version 100\n"  // OpenGL ES 2.0
#else
        "#version 120\n"  // OpenGL 2.1
#endif
        "		    \n"
        "void main(void)   \n"
        "{                 \n"
        "  gl_Position = vec4(0.0, 0.0, 0.5, 1.0); \n"
        "}                 \n"
    };
//Source code for fragment shader
    static const GLchar * fragment_shader_source[]=
    {
#ifdef GL_ES_VERSION_2_0
        "#version 100\n"  // OpenGL ES 2.0
#else
        "#version 120\n"  // OpenGL 2.1
#endif
        "void main(void) {\n"
        "gl_FragColor[0] = 0.0;\n"
        "gl_FragColor[1] = 0.0;\n"
        "gl_FragColor[2] = 1.0;\n"
        "}                 \n"
    };

//Create and compile vertex
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
    glCompileShader(vertex_shader);
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &vertex_ok);
    if(!vertex_ok) {
        cerr << "Error in vertex shader!" << endl;
        return EXIT_FAILURE;

    }
//create an compile frag
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
    glCompileShader(fragment_shader);
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &frag_ok);
    if(!frag_ok) {
        cerr << "Error in fragment shader!" << endl;
        return EXIT_FAILURE;
    }
//Create program, attach shaders to it, and link it
    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &link_ok);
    if(!link_ok) {
        cerr << "Program Link Error!" << endl;
        return EXIT_FAILURE;
    }

//Delete the shaders as the program has them now
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return program;
}

void startup(void)
{

    rendering_program = compile_shaders();
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);
}
void shutdown(void)
{
    glDeleteVertexArrays(1, &vao);
    glDeleteProgram(rendering_program);
    glDeleteVertexArrays(1, &vao);
}

void render() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(rendering_program);
    glDrawArrays(GL_POINTS, 0, 1);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Beta1");
    render();
    /*extension wrangler*/
    GLenum glew_status = glewInit();
    if(glew_status = glewInit())
    {
        cerr << "Error: " << glewGetErrorString(glew_status)<< endl;
        return EXIT_FAILURE;
    }
    GLuint shaderz = compile_shaders();
    return EXIT_SUCCESS;
}



















