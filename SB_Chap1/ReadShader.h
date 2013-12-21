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
unsigned long getFileSize(ifstream& file);
};


unsigned long getFileSize(ifstream& file)
{
if(!file.good()) return 0;
unsigned long pos=file.tellg();
file.seekg(0,ios::end);
unsigned long len = file.tellg();
file.seekg(ios::beg);

return len;
}

int ReadShader::readTheFile(string name)
{
	GLchar shaderContainer[255] = {0};
	int index;

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
	return 0;
}
