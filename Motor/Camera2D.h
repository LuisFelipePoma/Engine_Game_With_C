#pragma once
#include<glm/gtc/matrix_transform.hpp>
#include <iostream>

using namespace std;

class Camera2D
{
private:
	glm::vec2 position;
	float scale;
	int screenWidth;
	int screenHeight;
	bool needsUpdateMatrix;
	glm::mat4 cameraMatrix;
	glm::mat4 orthoMatrix;
public:
	void update();
	void init(int screenWidth, int screenHeight);
	glm::vec2 getPosition() {
		return position;
	}
	glm::vec2 convertToScreenWorld(glm::vec2 screenScords);
	void setPosition(glm::vec2 newPosition) {
		position = newPosition;
		needsUpdateMatrix = true;
	}
	void setScale(float newScale) {
		scale = newScale;
		needsUpdateMatrix = true;
	}
	glm::mat4 getCameraMatrix() {
		return cameraMatrix;
	}
	float getScale() { 
		return scale; 
	}
	Camera2D();
	~Camera2D();
};

