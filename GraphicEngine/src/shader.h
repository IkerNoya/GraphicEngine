#ifndef SHADER_H
#define SHADER_H
#include "export.h"
#include <iostream>
using namespace std;
class ENGINE_API Shader {
public:
	unsigned int id;
	Shader();
	~Shader();
	void CreateShader(const char* vertexPath, const char* fragmentPath);
	unsigned int getId();
	void use();
	unsigned int compileShader(unsigned int type, string& source);
};
#endif // !SHADER_H

