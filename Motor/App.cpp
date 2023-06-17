#include "App.h"

App::App()
{
}

App::~App()
{
}

void App::onInit()
{
}

void App::addScreens()
{
	gameplayScreen = make_unique<GameplayScreen>(&window);
	screenList->addScreen(gameplayScreen.get());
	screenList->setScreen(gameplayScreen->getIndex());
}

void App::onExit()
{
}
