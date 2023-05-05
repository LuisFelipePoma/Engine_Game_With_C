#pragma once
#include "Sprite.h"
#include <vector>

class Sprites
{
private:
	vector<Sprite*> sprites;
public:
	Sprites();
	~Sprites();
	void insertSprites(float x, float y, int width, int height, string texturePath);
	void initSprites();
	void drawSprites();
};

