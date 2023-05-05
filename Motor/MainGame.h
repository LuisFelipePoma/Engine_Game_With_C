#pragma once
#include <SDL/SDL.h>
#include <GL/eglew.h>
//Librerias necesarias para la rutina
#include <chrono>
#include <thread>
#include <random>
//----------------------------------
#include "Sprites.h"
#include "HLSLProgram.h"
#include "Window.h"

enum class GameState {
	PLAY, EXIT
};

class MainGame
{
private:
	//Variables para la rutina
	int intervalo;
	chrono::steady_clock::time_point inicio;
	mt19937 gen;

	//Variables para generar la posicion aleatoria
	random_device rd;
	uniform_real_distribution<float> dist;

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
	void rutinaSprites(); // Se crea esta funcion adicional para la rutina
	void run();
	void draw();
	void update();
};