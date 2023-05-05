#pragma once
#include <SDL/SDL.h>
#include <GL/eglew.h>
#include "Sprites.h"
#include "HLSLProgram.h"
#include "Window.h"

enum class GameState {
	PLAY, EXIT
};

class MainGame
{
private:
	int width;
	int height;
	float time;
	Window window;
	HLSLProgram program;
	Sprites* sprites;
	void init();
	void processInput();
	void initShaders();

public:
	MainGame();
	~MainGame();
	GameState gameState;

	void run();
	void draw();
	void update();
};