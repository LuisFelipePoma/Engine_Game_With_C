#include "Sprites.h"

Sprites::Sprites()
{
}

Sprites::~Sprites()
{

}

void Sprites::insertSprites(float x, float y, int width, int height, string texturePath)
{
	sprites.push_back(new Sprite(x, y, width, height, texturePath));
}
void Sprites::drawSprites()
{
	int size = sprites.size();
	for (auto elem : sprites) {
		elem->draw();
	}
}
