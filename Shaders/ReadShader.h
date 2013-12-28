#include <iostream>
#include <fstream>
#include <istream>
#include <cstdlib>
#include <string>
#include <GL/glew.h>

/*This header file compiles shaders based on a int value given by the user. Look at the importTheFileSource function to get a idea of numerical values matched to shader types. An error will also be thrown if a unrecongnized value is submitted.*/


using namespace std;

class ReadShader{
public:
GLuint readTheFile(string name, int shaderType);
private:
GLuint importTheFileSource(string source, int shaderType);
};


GLuint ReadShader::readTheFile(string name, int shaderType)
{
	GLuint shader = 0;
	///variables for handling shader compilation
	string filetext;
        ///stream text from shader file
	ifstream in(name.c_str());

	if(!in){
		cout << "Cannot open shader file! " << endl;
		return 1;
	}
	while(in.good()){
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
	GLenum err = glewInit();
	const GLchar *newSource = source.c_str();
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
	return shader;
}
