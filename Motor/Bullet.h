#pragma once
#include <glm/glm.hpp>
#include "SpriteBatch.h"
#include "Agent.h"

class Bullet : public Agent
{
private:
	glm::vec2 direction;
	int lifetime;

public:
	Bullet();
	~Bullet();
	void init(glm::vec2 position, glm::vec2 direction, float speed,int lifetime );
	void draw(SpriteBatch& spritebatch);
	bool isExist();
	void update(const vector<string>& levelData, vector<Human*>& humans,
		vector<Zombie*>& zombies);
	void setLifetime(int lifetime) {
		this->lifetime = lifetime;
	}
};

