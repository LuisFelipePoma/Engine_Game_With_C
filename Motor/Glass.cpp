#include "Glass.h"

Glass::Glass()
{
}

Glass::~Glass()
{
}

void Glass::init(glm::vec2 position)
{
	this->path = "Textures/glass.png";
	this->speed = 0;
	this->position = position;
	color.set(255, 255, 255, 255);
}

void Glass::update(const vector<string>& levelData, vector<Human*>& humans, vector<Zombie*>& zombies)
{

}
