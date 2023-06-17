#pragma once
#include "Agent.h"
#include "Human.h"

class Zombie : public Agent
{
protected:
	glm::vec2 direction;
public:

	Zombie();
	~Zombie();
	void init(float speed, glm::vec2 position);
	Human* getNearestHuman(vector<Human*>& humans);
	void update(const vector<string>& levelData, vector<Human*>& humans,
		vector<Zombie*>& zombies);
};