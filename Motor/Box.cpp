#include "Box.h"
#include "ResourceManager.h"
Box::Box()
{
}

Box::~Box()
{
}

void Box::init(glm::vec2 position)
{
	this->path = "Textures/caja2.png";
	this->speed = 0;
	this->position = position;
	color.set(255, 255, 255, 255);
}

void Box::update(const vector<string>& levelData, vector<Human*>& humans, vector<Zombie*>& zombies)
{
}
