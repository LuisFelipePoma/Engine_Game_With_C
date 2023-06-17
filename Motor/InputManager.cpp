#include "InputManager.h"

bool InputManager::wasKeyDown(unsigned int keyCode)
{
	auto it = previousKey.find(keyCode);
	if (it != previousKey.end()) {
		return it->second;
	}
	return false;
}

InputManager::InputManager() : mouseCoords(0.0f, 0.0f)
{
}

void InputManager::update()
{
	for (auto& it : keys) {
		previousKey[it.first] = it.second;
	}
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
	return false;
}

bool InputManager::isKeyDown(unsigned int keyCode)
{
	auto it = keys.find(keyCode);
	if (it != keys.end())
	{
		return it->second;
	}
	return false;
}

InputManager::~InputManager()
{

}
