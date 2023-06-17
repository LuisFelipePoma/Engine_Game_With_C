#pragma once
#include <algorithm>
#include "Game.h"
#include "GameplayScreen.h"
#include "ScreenList.h"

using namespace std;

class App : public Game
{
public:
	App();
	~App();
	virtual void onInit() override;
	virtual void addScreens() override;
	virtual void onExit() override;
private:
	unique_ptr<GameplayScreen> gameplayScreen = nullptr;
};

