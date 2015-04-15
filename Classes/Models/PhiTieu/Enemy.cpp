#include "Enemy.h"


Enemy::Enemy()
{}

Enemy::~Enemy()
{}

void Enemy::setup(int level, std::string fileName, EnemyType type)
{
	_level = level;
	_fileName = fileName;
	_type = type;
	_sprite = Sprite::create(fileName + ".png");
}
