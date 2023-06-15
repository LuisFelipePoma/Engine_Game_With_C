#pragma once
#include <SDL/SDL.h>
#include <GL/eglew.h>
#include "Sprite.h"
#include "HLSLProgram.h"
#include "Window.h"
#include "Camera2D.h"
#include "InputManager.h"
#include "Level.h"
#include "Player.h"
#include "Human.h"	
#include "Zombi.h"
#include "SpriteBatch.h"
#include "Bullet.h"

enum class GameState {
	PLAY, EXIT
};

class MainGame
{
private:
	int width;
	int height;
	//float time;

	SpriteBatch spriteBatch;
	vector<Level*> levels;
	vector<Human*> humans;
	vector<Bullet*> bullets;
	vector<Zombie*> zombies;
	Player* player;
	int currentLevel;

	Window window;
	HLSLProgram program;
	Sprite sprite;
	Camera2D camera2D;
	InputManager inputManager;

	void init();
	void initLevel();
	void processInput();
	void initShaders();
	void handleInput();
	void updateElements();
	void createBullet();
public:
	MainGame();
	~MainGame();

	GameState gameState;

	void run();
	void draw();
	void update();
};