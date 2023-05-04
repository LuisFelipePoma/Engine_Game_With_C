#pragma once
#include <SDL2/SDL.h>
#include <GL/eglew.h>
#include "Sprite.h"
#include "Error.h"

#include <iostream>

using namespace std;

enum class GameState
{
	PLAY, EXIT
};
class MainGame
{
private :
	int width;
	int height;
	SDL_Window* window;
	Sprite sprite;
	void init();
	void processInput();
public:
	MainGame();
	~MainGame();
	GameState gameState;
	void run();
	void draw();
	void update();
};

