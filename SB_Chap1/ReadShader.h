#include <iostream>
#include <fstream>
#include <istream>
#include <cstdlib>
#include <string>
#include <GL/glew.h>



using namespace std;

class ReadShader{
public:
GLuint readTheFile(string name, int shaderType, int finalShader);
private:
GLuint importTheFileSource(GLchar *source, int shaderType, int finalShader);
};



GLuint ReadShader::readTheFile(string name, int shaderType, int finalShader)
{
	///variables for character array reading from shader text file
	GLchar shaderContainer[300] = {0};
	GLuint program = 0;
	///variables for handling shader compilation

        ///stream text from shader file
	ifstream in(name.c_str());

	if(!in){
		cout << "Cannot open shader file! " << endl;
		return 1;
	}
	while(in){
	in >> shaderContainer;
	cout << shaderContainer << endl;
	}
	in .close();
	///stream closed now use character array
	program = importTheFileSource(shaderContainer,shaderType,finalShader);
        
	return program;
}
GLuint ReadShader::importTheFileSource(GLchar *source, int shaderType, int finalShader)
{
	GLuint shader;
	GLuint program = 0;
	GLenum err = glewInit();
	const GLchar *newSource = source;
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
	cout << "Shader type unknown to glCreateShader()" << endl;
	cout << "You offered the value " << shaderType << " to ReadShader::readTheFile" << endl;
	cout << "Try matching your shader type to the below accepted values: " << endl;
	cout << "GL_FRAGMENT_SHADER = 0" << endl;
	cout << "GL_VERTEX_SHADER = 1" << endl;
	cout << "GL_COMPUTE_SHADER = 2" << endl;
	cout << "GL_TESS_CONTROL_SHADER = 3" << endl;
	cout << "GL_TESS_EVALUATION_SHADER = 4" << endl;
	cout << "GL_GEOMETRY_SHADER = 5" << endl;
	}
  	glShaderSource(shader, 1, &newSource, NULL);
        glCompileShader(shader);
	program = glCreateProgram();
	cout << "finalShader: " << finalShader << endl;
	glAttachShader(program,shader);
	if(finalShader == 1){
        glLinkProgram(program);
	glDeleteShader(shader);
	}
	return program;
}
