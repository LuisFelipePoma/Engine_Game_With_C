#include "Zombie.h"
#include <random>
#include <ctime>
#include <glm/gtx/rotate_vector.hpp>

Zombie::Zombie(){
	evolution = 0;
	this->lives = 1;
}

Zombie::~Zombie()
{
}

void Zombie::init(float speed, glm::vec2 position)
{
	this->path = "Textures/zombie2.png";
	this->speed = speed;
	this->position = position;
	//color.set(150, 240, 150, 200);
	color.set(255, 255, 255, 255);
	static std::mt19937 randomEngine(time(nullptr));
	static std::uniform_real_distribution<float> randDir(-1.0, 1.0f);
	direction = glm::vec2(randDir(randomEngine), randDir(randomEngine));
	if (direction.length() == 0)
	{
		direction = glm::vec2(1.0f, 1.0f);
	}
	direction = glm::vec2(direction);
}

Human* Zombie::getNearestHuman(vector<Human*>& humans)
{
	Human* closeHuman = nullptr;
	float smallestDistance = 88888888888.0f;
	for (size_t i = 0; i < humans.size(); i++)
	{
		glm::vec2 dist = humans[i]->getPosition() - position;
		float distance = glm::length(dist);
		if (distance < smallestDistance)
		{
			smallestDistance = distance;
			closeHuman = humans[i];
		}
	}
	return closeHuman;
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
	Human* closestHuman = getNearestHuman(humans);

	if (closestHuman != nullptr)
	{

		glm::vec2 direction = glm::normalize(closestHuman->getPosition()-position);
		
		position += direction * speed;
	}
}

void Zombie::Evolution()
{
	this->path = "Textures/EvolutionZ.png";
	this->speed = 2.5f;
	this->lives = 3;
}
