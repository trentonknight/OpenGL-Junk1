#include <iostream>
#include <fstream>
#include <istream>
#include <string>

using namespace std;

class ReadShader{
public:
	void readTheFile(string name);
private:
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

void ReadShader::readTheFile(string name)
{

string line;
int increment = 0;

ifstream shader(name.c_str());

}
