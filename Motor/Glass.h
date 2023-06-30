#pragma once
#include "Agent.h"

class Glass : public Agent
{
public:
	Glass();
	~Glass();
	void init(glm::vec2 position);
	void update(const vector<string>& levelData, vector<Human*>& humans,
		vector<Zombie*>& zombies);
};

