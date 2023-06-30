#include "Water.h"
#include "ResourceManager.h"


Water::Water()
{
}

Water::~Water(){}

void Water::init(glm::vec2 position)
{
	this->path = "Textures/water.png";
	this->speed = 0;
	this->position = position;
	color.set(255, 255, 255, 255);
}

void Water::update(const vector<string>& levelData, vector<Human*>& humans, vector<Zombie*>& zombies)
{
}
