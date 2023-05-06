#include "InputManager.h"

InputManager::InputManager()
{
}

void InputManager::setMouseCoords(float x, float y)
{
	mouseCoords.x = x;
	mouseCoords.y = y;
}

void InputManager::pressKey(unsigned int keyCode)
{
	keys[keyCode] = true;
}

void InputManager::releaseKey(unsigned int keyCode)
{
	keys[keyCode] = false;
}

bool InputManager::isKeyPressed(unsigned int keyCode)
{
	auto it = keys.find(keyCode);
	if (it != keys.end())
	{
		return it->second;
	}
}

InputManager::~InputManager()
{

}
