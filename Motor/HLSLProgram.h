#pragma once
#include <GL/glew.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Error.h"

using namespace std;

class HLSLProgram
{
private:
	GLuint programID; // Interprete de los shaders
	GLuint fragmentShaderID;
	GLuint vertexShaderID;

	void compileShader(const string& shaderPath, GLuint id);
public:
	HLSLProgram();
	~HLSLProgram();
	int numAtribute;
	void addAtribute(const string attributeName);
	void use();
	void unuse();
	void compileShaders(const string& vertexShaderFilePath, const string& fragmentShaderFilePath);
	void linkShader();
	GLuint getUniformLocation(const string& name);
};

