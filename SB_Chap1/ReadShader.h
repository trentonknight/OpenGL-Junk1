#include <iostream>
#include <fstream>
#include <istream>
#include <cstdlib>
#include <string>
#include <GL/glew.h>


using namespace std;

class ReadShader{
public:
int readTheFile(string name);
int importTheFileSource(GLchar *source);
};



int ReadShader::readTheFile(string name)
{
	///variables for character array reading from shader text file
	GLchar shaderContainer[255] = {0};
	int index;
	///variables for handling shader compilation

        ///stream text from shader file
	ifstream in(name.c_str());

	if(!in){
		cout << "Cannot open shader file! " << endl;
		return 1;
	}
	while(in){
	in >> shaderContainer[index];
	cout << shaderContainer[index] << endl;
	index++;
	}
	in .close();
	///stream closed now use character array
	importTheFileSource(shaderContainer);


	return 0;
}
int ReadShader::importTheFileSource(GLchar *source)
{
	GLuint shader;
	const GLchar *newSource = source;
	shader = glCreateShader(GL_VERTEX_SHADER);
  	glShaderSource(shader, 1, &newSource, NULL);
        glCompileShader(shader);

	return 0;
}
