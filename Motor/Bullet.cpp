#include "Bullet.h"
#include "ResourceManager.h"
#include "GLTexture.h"
#include <iostream>

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::init(glm::vec2 position, glm::vec2 direction, float speed, int lifetime)
{
    this->path = "Textures/bala.png";
    this->position = position;
    this->lifetime = lifetime;
    this->direction = direction;
    this->speed = speed;
    this->lifetime = lifetime;
}

void Bullet::draw(SpriteBatch& spritebatch)
{
    Color color;
    color.set(255, 255, 255, 255);
    glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);
    static GLTexture texture = ResourceManager::getTexture(path);
    glm::vec4 posAndSize = glm::vec4(position.x, position.y, 30, 30);
    spritebatch.draw(posAndSize, uv, texture.id, 0.0f, color);
}

bool Bullet::isExist()
{
    if (lifetime <= 0) {
        return true;
    }
    return false;
}

void Bullet::update(const vector<string>& levelData, vector<Human*>& humans, vector<Zombie*>& zombies)
{
    position += direction * speed;
    if (collideWithLevel(levelData))
    {
        lifetime = 1;
    }
    lifetime--;
}
