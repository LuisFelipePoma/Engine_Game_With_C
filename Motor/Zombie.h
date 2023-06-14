#pragma once
#include "Agent.h"
class Zombie : public Agent
{
protected:
	glm::vec2 direction;
public:
	Zombie();
	~Zombie();
	void init(float speed, glm::vec2 position);
	void update(const vector<string>& levelData, vector<Human*>& humans,
		vector<Zombie*>& zombies);
};

