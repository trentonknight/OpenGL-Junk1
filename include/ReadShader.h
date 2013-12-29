#include <fstream>
#include <iostream>

/*This header file compiles shaders based on a int value given by the user. Look at the importTheFileSource function to get a idea of numerical values matched to shader types. An error will also be thrown if a unrecongnized value is submitted.*/
/*********************************************************************
 * Example Makefile (does not have to match)
*********************************************************************
* CC=g++
*LDLIBS=-lglut -lGLEW -lGL -lglapi
*all: triangle
*clean:
*        rm -f *.o triangle
*.PHONY: all clean
***************************************************************** * */
using namespace std;

class ReadShader {
public:
    GLuint readTheFile(string name, int shaderType);
private:
    GLuint importTheFileSource(string source, int shaderType);
    GLuint getShaderType(int shaderType);
    void announceTheShaderType(int shaderType);
};


GLuint ReadShader::readTheFile(string name, int shaderType)
{
    GLuint shader = 0;
    ///variables for handling shader compilation
    string filetext;
    ///stream text from shader file
    ifstream in(name.c_str());

    if(!in) {
        cerr << "Cannot open shader file! " << endl;
        return 1;
    }
    while(in.good()) {
        string line;
        getline(in, line);
        filetext.append(line + "\n");
    }
    in .close();
    shader = importTheFileSource(filetext,shaderType);

    return shader;
}
GLuint ReadShader::importTheFileSource(string source, int shaderType)
{
    GLuint shader = 0;
    GLuint program = 0;
    GLint compile_ok = 0;
    GLenum err = glewInit();
    const GLchar *newSource = source.c_str();
    shader = getShaderType(shaderType);
    glShaderSource(shader, 1, &newSource, NULL);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_ok);
    if (!compile_ok) {
        announceTheShaderType(shaderType);
        return 0;
    }

    return shader;
}

GLuint ReadShader::getShaderType(int shaderType)
{
    GLuint shader = 0;


    switch(shaderType)
    {
    case 0:
        shader = glCreateShader(GL_FRAGMENT_SHADER);
        break;
    case 1:
        shader = glCreateShader(GL_VERTEX_SHADER);
        break;
    case 2:
        shader = glCreateShader(GL_COMPUTE_SHADER);
        break;
    case 3:
        shader = glCreateShader(GL_TESS_CONTROL_SHADER);
        break;
    case 4:
        shader = glCreateShader(GL_TESS_EVALUATION_SHADER);
        break;
    case 5:
        shader = glCreateShader(GL_GEOMETRY_SHADER);
    default:
        return 1;
    }

    return shader;
}
void ReadShader::announceTheShaderType(int shaderType)
{

    switch(shaderType)
    {
    case 0:
        cerr << "glCreateShader(GL_FRAGMENT_SHADER) FAILED" << endl;
        break;
    case 1:
        cerr << "glCreateShader(GL_VERTEX_SHADER) FAILED" << endl;
        break;
    case 2:
        cerr << "glCreateShader(GL_COMPUTE_SHADER) FAILED" << endl;
        break;
    case 3:
        cerr << "glCreateShader(GL_TESS_CONTROL_SHADER)" << endl;
        break;
    case 4:
        cerr << "glCreateShader(GL_TESS_EVALUATION_SHADER)" << endl;
        break;
    case 5:
        cerr << "glCreateShader(GL_GEOMETRY_SHADER)" << endl;
    default:
        cout << "Shader type unknown to glCreateShader()" << endl;
        cout << "You offered the value " << shaderType << " to ReadShader::readTheFile" << endl;
        cout << "Try matching your shader type to the below accepted values: " << endl;
    }
    cout << "\nGL_FRAGMENT_SHADER = 0" << endl;
    cout << "GL_VERTEX_SHADER = 1" << endl;
    cout << "GL_COMPUTE_SHADER = 2" << endl;
    cout << "GL_TESS_CONTROL_SHADER = 3" << endl;
    cout << "GL_TESS_EVALUATION_SHADER = 4" << endl;
    cout << "GL_GEOMETRY_SHADER = 5\n" << endl;
    cout << "Make sure you have the correct shaderType when" << endl;
    cout << "Using the ReadShader header file. For example:" << endl;
    cout << "readshader.readTheFile(shaderFile, shaderType)" << endl;
    cout << "readshader.readTheFile(myshader.vert, 1)" << endl;
    cout << "readshader.readTheFile(myshader.frag, 0)" << endl;
    cout << "If the shader file matches the type submitted then try a" << endl;
    cout << "GLSL compiler to discover the issue. For example: " << endl;
    cout << "glsl_compile myshader.vert" << endl;

}


