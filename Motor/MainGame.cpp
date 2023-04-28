#include "MainGame.h"


MainGame::MainGame() {
	window = nullptr;
	width = 800;
	height = 600;
	gameState = GameState::PLAY;
}

MainGame::~MainGame() {

}

void MainGame::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Hola", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_OPENGL);
	if (window == nullptr) {
		// Validar si falla para mostrar un mensaje
		fatalError("SDL not initialized");
	}
	SDL_GLContext gkContext = SDL_GL_CreateContext(window);
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		// Validar si falla para mostrar un mensaje
		fatalError("Glew not initialized");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
	glClearColor(1.0f, 0.3f, 0.2f, 0.3f); 

}

void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	sprite.draw();
	// si tengo elementos actualizo
	SDL_GL_SwapWindow(window);


}


void MainGame::processInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			cout << event.motion.x << " , " << event.motion.y << endl;
			
			break;
		}
	}
}

void MainGame::update()
{
	while (gameState != GameState::EXIT)
	{
		draw(); 
		processInput();
	}
}

void MainGame::run() {
	init();
	sprite.init(-1, -1, 1, 1);
	update();
}
