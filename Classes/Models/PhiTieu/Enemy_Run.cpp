#include "Enemy_Run.h"


Enemy_Run::~Enemy_Run(){}

Enemy_Run::Enemy_Run()
{
	this->autorelease();
	_sprite = Sprite::create("Enemy_Run1");

}

void Enemy_Run::setAction()
{
	switch (_level)
	{
	case 1:

		break;
	}
}

Enemy_Run* Enemy_Run::create(int level)
{
	Enemy_Run* enemy = new Enemy_Run();
	enemy->setup(level, "Enemy_Run", EnemyType::Run);
	enemy->setAction();
	return enemy;
}


