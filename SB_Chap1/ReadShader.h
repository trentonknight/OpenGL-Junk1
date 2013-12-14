#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ReadShader{
public:
	void readTheFile(string name);
};


void ReadShader::readTheFile(string name)
{

string line;

ifstream shader(name.c_str());

if (shader.is_open())
{
	while(getline (shader,line))
	{
		cout << line << endl;
	}
	shader.close();
}
else cout << "Unable to read shader!";


}
