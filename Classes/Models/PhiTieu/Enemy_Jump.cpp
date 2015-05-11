/*
 * Enemy_Jump.cpp
 *
 *  Created on: Apr 20, 2015
 *      Author: conghoang
 */

#include "Enemy_Jump.h"

Enemy_Jump::Enemy_Jump() {}

Enemy_Jump::~Enemy_Jump() {}

Enemy_Jump* Enemy_Jump::create() {
	Enemy_Jump* enemy = new Enemy_Jump();
	enemy->setup("Enemy_Jump", EnemyType::Jump);
	enemy->setupAction();
	return enemy;
}

/**
 * Với thằng số lần nhảy sẽ tăng theo
 */

void Enemy_Jump::setupAction() {
	float time = 0;
	switch (getLevel()) {
	case 1:
		//Tính toán thời gian
		_speed = random(150, 200);
		time = Config::screenSize.width / _speed;
		this->setPosition(Config::getSpawnStart_low());

		//run aciton
		auto run = MoveTo::create(time, Config::getSpawnEnd_low());
		auto jump = JumpBy::create(time, Vec2::ZERO, random(Config::screenSize.height / 2 - 50, Config::screenSize.height / 2 + 10), random(3, 6));
		_action = Spawn::createWithTwoActions(run, jump);
		//v
		this->runAction(_action);
		break;
	}
}
