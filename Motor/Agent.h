#pragma once
#include <glm/glm.hpp>
#include "SpriteBatch.h"
#include "GLTexture.h"
#include <string>
#include "Level.h"

class Zombie;
class Human;

const float AGENT_WIDTH = 64.f;
const float AGENT_RADIUS = AGENT_WIDTH / 2.0f;

class Agent
{
protected:
	string path;
	glm::vec2 position;
	bool alive;
	int lives;
	float speed;
	Color color;
	void checkTilePosition(const vector<string>& levelData,
		vector<glm::vec2>& collideTilePosition, float x, float y);
	void collideWithTile(glm::vec2 tilePos);
public:
	Agent();
	float getSpeed()const { return speed; }
	void setSpeed(float speed) { this->speed = speed; }
	int getVidas() const {
		return lives;
	}
	void setVidas(int lives) {
		this->lives = lives;
	}
	bool getAlive() const {
		return alive;
	}
	Color getColor() const {
		return color;
	}
	void setColor(Color color) {
		this->color = color;
	}
	void setAlive(bool alive) {
		this->alive = alive;
	}
	virtual ~Agent();
	glm::vec2 getPosition() {
		return position;
	}
	void setPosition(glm::vec2 position) {
		this->position = position;
	}
	bool isDead();

	virtual void update(const vector<string>& levelData, vector<Human*>& humans,
						vector<Zombie*>& zombies) = 0;
	void draw(SpriteBatch& spriteBatch);
	bool collideWithLevel(const vector<string>& levelData);
	bool collideWithAgent(Agent* agent); 
	bool collideWithMaterial(Agent* agent);
};

