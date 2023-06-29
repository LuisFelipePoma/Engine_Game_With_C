#include "MainGame.h"
#include <iostream>
#include "Error.h"
#include <random>
#include <ctime>

using namespace std;

MainGame::MainGame() {
	width = 900;
	height = 800;
	gameState = GameState::PLAY;
	camera2D.init(width, height);
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
			//cout << "Posicion del mouse : " << event.motion.x << " - " << event.motion.y << endl;
			inputManager.setMouseCoords(event.motion.x, event.motion.y);
			glm::vec2 mouseCoords = camera2D.convertToScreenWorld(inputManager.getMouseCoords());
			//cout << "Nueva posicion del mouse : " << mouseCoords.x << " - " << mouseCoords.y << endl;

			break;
		case SDL_KEYUP:
			inputManager.releaseKey(event.key.keysym.sym);
			break;
		case SDL_KEYDOWN:
			inputManager.pressKey(event.key.keysym.sym);
			break;
		case SDL_MOUSEBUTTONDOWN:
			inputManager.pressKey(event.button.button);
			break;
		case SDL_MOUSEBUTTONUP:
			inputManager.releaseKey(event.button.button);
			break;
		}
		handleInput();
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

void MainGame::handleInput()
{
	const float SCALE_SPEED = 0.01f;
	if (inputManager.isKeyPressed(SDLK_q)) {
		camera2D.setScale(camera2D.getScale() + SCALE_SPEED);
	}
	if (inputManager.isKeyPressed(SDLK_e)) {
		camera2D.setScale(camera2D.getScale() - SCALE_SPEED);
	}
	if (inputManager.isKeyPressed(SDL_BUTTON_LEFT)) {
		createBullet();
		//cout << "CLICK IZQUIERDO"<<endl;
	}
	if (inputManager.isKeyPressed(SDL_BUTTON_RIGHT)) {
		//cout << "CLICK DERECHO" << endl;
	}
	if (inputManager.isKeyPressed(SDL_BUTTON_MIDDLE)) {
		//cout << "CLICK MEDIO" << endl;
	}
	if (inputManager.isKeyPressed(SDLK_r) && !player->getAlive())
	{
		reset();
		initLevel();
		glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
	}
	if (inputManager.isKeyPressed(SDLK_f))
	{
		system("cls");
		cout << "Contador de Humanos : " << contadorHumanos << endl;
		cout << "Contador de Zombies : " << contadorZombies << endl;
	}
}
void MainGame::createBullet()
{
	glm::vec2 mouseCoords = 
		camera2D.convertToScreenWorld(inputManager.getMouseCoords());
	glm::vec2 playerPosition = player->getPosition();
	glm::vec2 direction = mouseCoords - playerPosition;
	direction = glm::normalize(direction);
	Bullet* bullet = new Bullet();
	bullet->init(playerPosition, direction, 10.0f, 1000);
	bullets.push_back(bullet);
}

void MainGame::updateElements()
{
	if (!player->getAlive() || contadorHumanos == 0) {
		glClearColor(0.5f, 0.2f, 0.1f, 1.0f);
		currentLevel = 0;
		return;
	}
	if (contadorZombies == 0) {
		glClearColor(0.5f, 0.2f, 1.f, 0.2f);
		currentLevel++;
		return;
	}
	camera2D.update();
	camera2D.setPosition(player->getPosition());
	player->update(levels[currentLevel]->getLevelData(), humans,zombies);
	for (size_t i = 0; i < humans.size(); i++)
	{
		humans[i]->update(levels[currentLevel]->getLevelData(), humans, zombies);
	}
	for (size_t i = 0; i < zombies.size(); i++)
	{
		zombies[i]->update(levels[currentLevel]->getLevelData(), humans, zombies);
		if (zombies[i]->collideWithAgent(player)) {
			delete zombies[i];
			zombies[i] = zombies.back();
			zombies.pop_back();
			Color otroColor = player->getColor();
			otroColor.a -= alphaReduce;
			player->setColor(otroColor);
			if (!player->isDead()) {
				cout << "\nPara revivir presione R\n";
			}
			contadorZombies--;
			break;
		}
		for (size_t j = 0; j < humans.size(); j++)
		{
			if (zombies[i]->collideWithAgent(humans[j])) {
				zombies.push_back(new Zombie());
				zombies.back()->init(1.3f, humans[j]->getPosition());
				delete humans[j];
				humans[j] = humans.back();
				humans.pop_back();
				contadorHumanos--;
				contadorZombies++;
			}
		}
	}
	for (size_t i = 0; i < bullets.size();)
	{
		bullets[i]->update(levels[currentLevel]->getLevelData(), humans, zombies);
		if (bullets[i]->isExist()) {
			bullets[i] = bullets.back();
			bullets.pop_back();
		}
		else {
			for (size_t j = 0; j < zombies.size(); j++)
			{
				if (bullets[i]->collideWithAgent(zombies[j])) {
					delete zombies[j];
					zombies[j] = zombies.back();
					zombies.pop_back();
					bullets[i]->setLifetime(1);
					contadorZombies--;
				}
			}
			i++;
		}
	}
}



void MainGame::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window.create("Mundo 1", width, height, 0);
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("Glew not initialized");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
	currentLevel = 0;
	initLevel();
	initShaders();
}

void MainGame::initLevel()
{
	levels.push_back(new Level("Level/level1.txt"));

	//inicializar humanos, player y zombie
	player = new Player();
	player->init(5, 5.0f, levels[currentLevel]->getPlayerPosition(), &inputManager);
	alphaReduce = (255 / player->getVidas());
	spriteBatch.init();
	hudBatch.init();

	mt19937 randomEngine(time(nullptr));
	uniform_int_distribution<int> randomPoxX(
		1, levels[currentLevel]->getWidth() - 2
	);
	uniform_int_distribution<int> randomPoxY(
		1, levels[currentLevel]->getWidth() / 2
	);
	for (int i = 0; i < levels[currentLevel]->getNumHumans(); i++)
	{
		humans.push_back(new Human());
		glm::vec2 pos(randomPoxX(randomEngine) * TILE_WIDTH, 
			randomPoxY(randomEngine) * TILE_WIDTH/2);
		humans.back()->init(1.0f, pos);
	}
	//Creacion de Zombies
	vector<glm::vec2>zombiesData = levels[currentLevel]->getZombiesPosition();
	for (int i = 0; i < zombiesData.size(); i++)
	{
		zombies.push_back(new Zombie());
		glm::vec2 pos(zombiesData[i].x,
			zombiesData[i].y);
		zombies.back()->init(1.0f, pos);
	}
	spriteFont = new SpriteFont("Fonts/font.ttf",64);

	// INICIALIZACION DE CONTADORES
	contadorHumanos = humans.size();
	contadorZombies = zombies.size();
	cout << "Contador de Humanos : " << contadorHumanos << endl;
	cout << "Contador de Zombies : " << contadorZombies << endl;
}

void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	program.use();
	glActiveTexture(GL_TEXTURE0);
	
	glm::mat4 cameraMatrix = camera2D.getCameraMatrix();
	GLuint pCameraLocation = program.getUniformLocation("pCamera");
	glUniformMatrix4fv(pCameraLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	GLuint imageLocation = program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);

	spriteBatch.begin();
	
	levels[currentLevel]->draw();
	player->draw(spriteBatch);
	for (int i = 0; i < humans.size(); i++)
	{
		humans[i]->draw(spriteBatch);
	}
	for (int i = 0; i < zombies.size(); i++)
	{
		zombies[i]->draw(spriteBatch);
	}
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->draw(spriteBatch);
	}

	spriteBatch.end();
	spriteBatch.renderBatch();
	drawHud();
	glBindTexture(GL_TEXTURE_2D, 0);
	program.unuse();
	window.swapWindow();
}

void MainGame::drawHud()
{
	glm::mat4 cameraMatrix = camera2D.getCameraMatrix();
	GLuint pCameraLocation = program.getUniformLocation("pCamera");
	glUniformMatrix4fv(pCameraLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	char buffer[256];
	hudBatch.begin();

	sprintf_s(buffer, "HOLAAAAAAA");
	Color color;
	color.set(255,255,255,255);
	spriteFont->draw(hudBatch, buffer, glm::vec2(0, 0),
		glm::vec2(0.5),0.0f,color);

	hudBatch.end();
	hudBatch.renderBatch();
}

void MainGame::run() {
	init();
	update();
}

void MainGame::update() {
	while (gameState != GameState::EXIT) {
		draw();
		processInput();
		updateElements();
	}
}

void MainGame::reset()
{
	for (size_t i = 0; i < zombies.size(); i++)
	{
		delete zombies[i];
	}
	zombies.clear();
	for (size_t i = 0; i < humans.size(); i++)
	{
		delete humans[i];
	}
	humans.clear();
	delete player;
	levels.clear();
	currentLevel = 0;
}
