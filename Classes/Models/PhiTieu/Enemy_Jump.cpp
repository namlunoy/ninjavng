/*
 * Enemy_Jump.cpp
 *
 *  Created on: Apr 20, 2015
 *      Author: conghoang
 */

#include "Enemy_Jump.h"

Enemy_Jump::Enemy_Jump() {}

Enemy_Jump::~Enemy_Jump() {}

Enemy_Jump* Enemy_Jump::create(int level) {
	Enemy_Jump* enemy = new Enemy_Jump();
	enemy->setup(level, "Enemy_Jump", EnemyType::Jump);
	enemy->setupAction();
	return enemy;
}


void Enemy_Jump::setupAction() {
	float time = 0;
	switch (_level) {
	case 1:
		//Tính toán thời gian
		_speed = 500;
		time = Config::screenSize.width / _speed;
		this->setPosition(Config::getSpawnStart_low());
		_action = MoveTo::create(time, Config::getSpawnEnd_low());
		this->runAction(_action);
		break;
	}
}
