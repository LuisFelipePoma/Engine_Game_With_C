#pragma once
#include <GL/glew.h>
#include "GLTexture.h"
#include "ResourceManager.h"
#include "Vertex.h"
#include <string>

using namespace std;
class Sprite
{
private:
	float x;
	float y;
	int width;
	int height;
	string texturePath;
	GLuint vboID;
	GLTexture texture;
public:
	Sprite(float x, float y, int width, int height, string texturePath);
	~Sprite();
	void init();
	void draw();
};

