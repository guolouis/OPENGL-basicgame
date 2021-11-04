#pragma once

#include "libs.h"

std::string get_file_contents(const char* filename);

class Shader
{
public:
	GLuint ID;
	Shader(const char* vertexFile, const char* fragmentFile);
	void Activate();
	void Delete();
private:
	void compileErrors(unsigned int shader, const char* type);
};
