#include "Enemy.h"


Enemy::Enemy()
{
	//Khởi tạo các thuộc tính
}


Enemy::~Enemy()
{
}

void Enemy::setup(int level, std::string fileName, EnemyType type)
{
	_level = level;
	_fileName = fileName;
	_type = type;
	_sprite = Sprite::create(fileName + ".png");
	XHelper::runAnimation(fileName, 2, 0.3f, true, _sprite);
}
