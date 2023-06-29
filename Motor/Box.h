#pragma once
#include "Agent.h"

class Box: public Agent
{
public:
	Box();
	~Box();
	void init(glm::vec2 position);
	void update(const vector<string>& levelData, vector<Human*>& humans,
		vector<Zombie*>& zombies);
};

