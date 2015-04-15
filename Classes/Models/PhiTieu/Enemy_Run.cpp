#include "Enemy_Run.h"


Enemy_Run::~Enemy_Run(){}

Enemy_Run::Enemy_Run()
{
	this->autorelease();
	_sprite = Sprite::create("Enemy_Run1.png");
	_sprite->setScale(0.1f);
	this->addChild(_sprite);

	_body = PhysicsBody::createBox(_sprite->getBoundingBox().size,PhysicsMaterial(1,0,0));
	_body->setCollisionBitmask(Tags::ENEMY);
	_body->setContactTestBitmask(true);
	_body->setGravityEnable(false);
	_body->setDynamic(false);
	this->setPhysicsBody(_body);
}

void Enemy_Run::setupAction()
{
	switch (_level)
	{
	case 1:
		//_action = MoveTo::cre
		break;
	}
}

Enemy_Run* Enemy_Run::create(int level)
{
	Enemy_Run* enemy = new Enemy_Run();
	enemy->setup(level, "Enemy_Run", EnemyType::Run);
	enemy->setupAction();
	return enemy;
}


