#pragma once
#include "Agent.h"

class Water: public Agent
{
public:
	Water();
	~Water();
	void init(glm::vec2 position);
	void update(const vector<string>& levelData, vector<Human*>& humans, vector<Zombie*>& zombies);
};

