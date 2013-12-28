#include <iostream>
using namespace std;
#include <GL/glew.h>
#include "vgl.h"

enum VAO_IDs {Triangles, NumVAOs};
enum Buffer_IDs {ArrayBuffer, NumBuffers};
enum Attrib_IDs {vPosition = 0};

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];
GLuint vertex_shader;
GLuint fragment_shader;
GLuint program;


const GLuint NumVertices = 6;
GLuint compile_shaders(void) {
    static const GLchar * vertex_shader_source[] =
    {
        "#version 300 core \n"
        "                   \n"
        "void main(void)   \n"
        "{                 \n"
        "  gl_Position = vec4(0.0, 0.0, 0.5, 1.0); \n"
        "}                 \n"
    };
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

void init(void)
{

    rendering_program = compile_shaders();
    glGenVertexArrays(NumVAOs, VAOs);
    glBindVertexArray(VAOs[Triangles]);

    GLfloat vertices[NumVertices][2] = {
        {-0.90, -0.90}, //Triangle 1
        { 0.85, -0.90},
        {-0.90, -0.85},
        { 0.90, -0.85},//Triangle 2
        { 0.90,  0.90},
        {-0.85,  0.90}
    };

    glGenBuffers(NumBuffers, Buffers);
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
                 vertices, GL_STATIC_DRAW);



    glUseProgram(compile_shaders);
    glVertexAttribPointer(vPosition, 2, GL_FLOAT,
                          GL_FALSE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(vPosition);
private:
    GLuint rendering_program;
    GLuint vertex_array_object;
}
//display
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBindVertexArray(VAOs[Triangles]);
    glDrawArrays(GL_TRIANGLES, 0, NumVertices);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(512,512);
    glutInitContextVersion(4,3);
    glutInitContextProfile(GLUT_CORE_PROFILE);
    glutCreateWindow(argv[0]);

    if(glewInit()) {
        cerr << "Unable to initialize GLEW...exiting" << endl;
        exit(EXIT_FAILURE);
    }
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}




