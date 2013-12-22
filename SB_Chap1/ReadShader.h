#include <iostream>
#include <fstream>
#include <istream>
#include <cstdlib>
#include <string>
#include <GL/glew.h>



using namespace std;

class ReadShader{
public:
GLuint readTheFile(string name);
private:
GLuint importTheFileSource(GLchar *source);
};



GLuint ReadShader::readTheFile(string name)
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
	program = importTheFileSource(shaderContainer);
        
	return program;
}
GLuint ReadShader::importTheFileSource(GLchar *source)
{
	GLuint shader;
	GLuint program = 0;
	GLenum err = glewInit();
	const GLchar *newSource = source;
	shader = glCreateShader(GL_FRAGMENT_SHADER);
  	glShaderSource(shader, 1, &newSource, NULL);
        glCompileShader(shader);
	program = glCreateProgram();
	glAttachShader(program,shader);
        glLinkProgram(program);
	glDeleteShader(shader);
	return program;
}
