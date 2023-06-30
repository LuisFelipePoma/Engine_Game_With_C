#include "Player.h"
#include <SDL/SDL.h>

Player::Player()
{
}

Player::~Player()
{
}

void Player::init(int vidas,float speed, glm::vec2 position, InputManager* inputManager)
{
	this->path = "Textures/player2.png";
	this->speed = speed;
	this->position = position;
	this->inputManager = inputManager;
	color.set(255, 255, 255, 255);
	this->lives = vidas;
	this->alive = true;
}

void Player::update(const vector<string>& levelData, vector<Human*>& humans,
	vector<Zombie*>& zombies) {
	if (inputManager -> isKeyPressed(SDLK_w))
	{
		position.y += speed;
	}
	if (inputManager->isKeyPressed(SDLK_s))
	{
		position.y -= speed;
	}
	if (inputManager->isKeyPressed(SDLK_a))
	{
		position.x -= speed;
	}
	if (inputManager->isKeyPressed(SDLK_d))
	{
		position.x += speed;
	}
	collideWithLevel(levelData);
}