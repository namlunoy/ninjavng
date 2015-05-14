#include "Enemy_Run.h"

void Enemy_Run::reset() {
	 Enemy_Run::MIN = 150;
	 Enemy_Run::MAX = 200;
	 Enemy_Run::delta = 12;
}

Enemy_Run::~Enemy_Run() {
}
Enemy_Run::Enemy_Run() {
}
float Enemy_Run::MIN = 150;
float Enemy_Run::MAX = 200;
float Enemy_Run::delta = 12;

void Enemy_Run::setupAction() {
	float time = 0;
	switch (getLevel()) {
	case 1:
		//Tính toán thời gian
		_speed = random(MIN, MAX);
		time = Config::screenSize.width / _speed;
		this->setPosition(Config::getSpawnStart_low());
		_action = MoveTo::create(time, Config::getSpawnEnd_low());
		this->runAction(_action);
		break;
	}
}

Enemy_Run* Enemy_Run::create() {
	MIN += delta;
	MAX += delta;
	Enemy_Run* enemy = new Enemy_Run();
	enemy->setup("Enemy_Run", EnemyType::Run);
	enemy->setupAction();

	return enemy;
}

