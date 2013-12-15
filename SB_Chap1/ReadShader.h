#include <iostream>
#include <fstream>
#include <istream>
#include <cstdlib>
#include <string>

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
	char shaderContainer[255];

	ifstream in(name.c_str());

	if(!in){
		cout << "Cannot open shader file! " << endl;
		return 1;
	}
	for(int a=0; a < 255; a++){
	in >> shaderContainer;
	cout << shaderContainer << endl;
	}
	in .close();
	return 0;
}
