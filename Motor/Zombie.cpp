#include "Zombie.h"
#include <random>
#include <ctime>
#include <glm/gtx/rotate_vector.hpp>

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

void Zombie::init(float speed, glm::vec2 position)
{
	this->path = "Textures/circle.png";
	this->speed = speed;
	this->position = position;
	color.set(0, 255, 0, 255);
	static std::mt19937 randomEngine(time(nullptr));
	static std::uniform_real_distribution<float> randDir(-1.0, 1.0f);
	direction = glm::vec2(randDir(randomEngine), randDir(randomEngine));
	if (direction.length() == 0)
	{
		direction = glm::vec2(1.0f, 1.0f);
	}
	direction = glm::vec2(direction);
}

void Zombie::update(const vector<string>& levelData, vector<Human*>& humans,
	vector<Zombie*>& zombies) {
	static std::mt19937 randomEngine(time(nullptr));
	static std::uniform_real_distribution<float> randRotate(-40.0, 40.0f);
	position += direction * speed;
	if (collideWithLevel(levelData))
	{
		direction = glm::rotate(direction, randRotate(randomEngine));
	}

}
