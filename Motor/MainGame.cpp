#include "MainGame.h"
#include <iostream>
#include "Error.h"

using namespace std;

MainGame::MainGame() {
	width = 800;
	height = 600;
	gameState = GameState::PLAY;
	time = 0;
	sprites = new Sprites();

	// Variables e inicializaciones para generar posiciones aleatorias
	gen = mt19937(rd());
	dist = uniform_real_distribution<float>(-1.0f, 1.0f);

	// Variables e inicializaciones para la creacion del intervalo
	intervalo = 2500;
	inicio = chrono::steady_clock::now();
}

MainGame::~MainGame() {

}
void MainGame::processInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			//cout << event.motion.x << " , " << event.motion.y << endl;
			break;
		}
	}
}

void MainGame::initShaders()
{
	program.compileShaders("Shaders/colorShaderVert.txt", "Shaders/colorShaderFrag.txt");
	program.addAtribute("vertexPosition");
	program.addAtribute("vertexColor");
	program.addAtribute("vertexUV");
	program.linkShader();
}

void MainGame::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window.create("Hola", width, height, 0);
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("Glew not initialized");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	initShaders();
}

void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	program.use();
	glActiveTexture(GL_TEXTURE0);
	GLuint timeLocation = program.getUniformLocation("time");
	glUniform1f(timeLocation, time);
	time += 0.002;
	GLuint imageLocation = program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);
	sprites->drawSprites();
	program.unuse();
	window.swapWindow();
}

void MainGame::rutinaSprites()
{
	this_thread::sleep_until(inicio + chrono::milliseconds(intervalo)); // Detiene la funcion durante un tiempo
	sprites->insertSprites(dist(gen), dist(gen), 1, 1, "Textures/gato.png"); // Inicializa al sprite y lo agrega al vector
	sprites->initSprites();// Inicializa los Sprites
	inicio += chrono::milliseconds(intervalo); // Reinicia la rutina
}

void MainGame::run() {
	init();
	update();
}

void MainGame::update() {
	

	while (gameState != GameState::EXIT) {
		rutinaSprites();
		draw();
		processInput();
	}
}