#pragma once
#include <string>
#include <vector>
#include "SpriteBatch.h"

using namespace std;
const int TILE_WIDTH = 64;

class Level
{

private:
	vector<string> levelData;
	int numHumans;
	void parseLevel();
	glm::vec2 playerPosition;
	vector<glm::vec2> zombiesPosition;
	vector<glm::vec2> cajasPosition;
	vector<glm::vec2> waterPosition;
	vector<glm::vec2> vidriosPosition;
	SpriteBatch spriteBatch;
public:
	int getNumHumans() const {
		return numHumans;
	}
	glm::vec2 getPlayerPosition() const {
		return playerPosition;
	}

	vector<glm::vec2> getZombiesPosition() const {
		return zombiesPosition;
	}
	vector<glm::vec2> getCajasPosition() const {
		return cajasPosition;
	}
	vector<glm::vec2> getWaterPosition() const {
		return waterPosition;
	}
	vector<glm::vec2> getVidriosPosition() const {
		return vidriosPosition;
	}
	vector<string> getLevelData() {
		return levelData;
	}
	SpriteBatch getSpriteBatch() {
		return spriteBatch;
	}
	int getWidth() const {
		return levelData[0].size();
	}

	int getHeight() const {
		return levelData[0].size();
	}

	Level(const string& fileName);
	void draw();
	~Level();
};

