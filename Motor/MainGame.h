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
#include "Zombie.h"
#include "SpriteBatch.h"
#include "Bullet.h"
#include "SpriteFont.h"
#include "Box.h"
#include "Glass.h"
#include "Water.h"

#define Speed_Player 8.0f
#define Speed_Zombie 1.0f
#define Spedd_Human 1.0f
//const float Speed_Player = 5.0f;

enum class GameState {
	PLAY, EXIT
};

class MainGame
{
private:
	time_t timeShoot;
	int width;
	int height;
	int currentLevel;
	double alphaReduce;
	double alphaReduceTotal;
	//float time;
	int contadorHumanos;
	int contadorZombies;
	int contadorBalas;
	int capacidadBalas;

	SpriteFont* spriteFont;
	SpriteBatch spriteBatch;
	SpriteBatch hudBatch;

	vector<Level*> levels;
	vector<Human*> humans;
	vector<Bullet*> bullets;
	vector<Zombie*> zombies;
	vector<Box*> cajas;
	vector<Glass*> vidrios;
	vector<Water*> zoneWaters;
	Player* player;

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
	void drawHud();
	void update();
	void reset();
	void showStatus();
};