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

/**
 * Với thằng số lần nhảy sẽ tăng theo
 */

void Enemy_Jump::setupAction() {
	float time = 0;
	switch (_level) {
	case 1:
		//Tính toán thời gian
		_speed = 190;
		time = Config::screenSize.width / _speed;
		this->setPosition(Config::getSpawnStart_low());

		//run aciton
		auto run = MoveTo::create(time, Config::getSpawnEnd_low());
		auto jump = JumpBy::create(3,Vec2::ZERO,Config::screenSize.height/2,3);
		_action = Spawn::createWithTwoActions(run,jump);
		//v
		this->runAction(_action);
		break;
	}
}
