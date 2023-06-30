#include "Level.h"
#include <fstream>
#include "ResourceManager.h"
#include "Error.h"


Level::Level(const string& fileName)
{
	ifstream file;
	file.open(fileName);
	if (file.fail())
	{
		fatalError("Fallo al abrir" + fileName);
	}
	string tmp;
	file >> tmp >> numHumans;
	getline(file, tmp);
	while (getline(file,tmp))
	{
		levelData.push_back(tmp);
	}
	parseLevel();
}

void Level::parseLevel()
{
	spriteBatch.init();
	spriteBatch.begin();
	glm::vec4 uvRect(0.0f,0.0f,1.0f,1.0f);
	Color color;
	GLuint n;
	color.set(255, 255, 255, 255);
	Color colorPiso;
	colorPiso.set(50, 50, 50, 150);
	for (size_t y = 0; y < levelData.size(); y++)
	{
		for (size_t x = 0; x < levelData[y].size(); x++)
		{
			char tile = levelData[y][x];
			glm::vec4 desRect(x * TILE_WIDTH, y * TILE_WIDTH, TILE_WIDTH, TILE_WIDTH);
			switch (tile)
			{
			case 'R':
				spriteBatch.draw(desRect, uvRect, ResourceManager::getTexture("Textures/vallas.png").id,0.0f, color);
				break;
			case 'F':
				levelData[y][x] = '.';
				n = rand() % 3 + 1;
				if(n==1)spriteBatch.draw(desRect, uvRect, ResourceManager::getTexture("Textures/FYellow.png").id, 0.0f, color);
				if(n==2)spriteBatch.draw(desRect, uvRect, ResourceManager::getTexture("Textures/FWhite.png").id, 0.0f, color);
				if(n==3)spriteBatch.draw(desRect, uvRect, ResourceManager::getTexture("Textures/FBlue.png").id, 0.0f, color);
				break;
			case 'B':
				spriteBatch.draw(desRect, uvRect, ResourceManager::getTexture("Textures/bricks.png").id, 0.0f, color);
				break;
			case 'G':
				levelData[y][x] = '.';
				vidriosPosition.emplace_back(x * TILE_WIDTH, y * TILE_WIDTH);
				//spriteBatch.draw(desRect, uvRect, ResourceManager::getTexture("Textures/glass.png").id, 0.0f, color);
				break;
			case 'L':
				spriteBatch.draw(desRect, uvRect, ResourceManager::getTexture("Textures/light_bricks.png").id, 0.0f, color);
				break;
			case 'O':
				levelData[y][x] = '.';
				cajasPosition.emplace_back(x * TILE_WIDTH, y * TILE_WIDTH);
				//spriteBatch.draw(desRect, uvRect, ResourceManager::getTexture("Textures/caja.png").id, 0.0f, color);
				break;
			case '@':
				levelData[y][x] = '.';
				playerPosition.x = x * TILE_WIDTH;
				playerPosition.y = y * TILE_WIDTH;
				break;
			case 'Z':
				levelData[y][x] = '.';
				zombiesPosition.emplace_back(x * TILE_WIDTH, y * TILE_WIDTH);
				break;
			case 'W':
				levelData[y][x] = '.';
				waterPosition.emplace_back(x * TILE_WIDTH, y * TILE_WIDTH);
				//spriteBatch.draw(desRect, uvRect, ResourceManager::getTexture("Textures/water.png").id, 0.0f, color);
				break;
			case '.':
				spriteBatch.draw(desRect, uvRect, ResourceManager::getTexture("Textures/piso.png").id, 0.0f, colorPiso);
				break;
			default:
				break;
			}
		}
	}
	spriteBatch.end();
}

void Level::draw()
{
	spriteBatch.renderBatch();
}

Level::~Level()
{
}
