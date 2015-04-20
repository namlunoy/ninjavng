#include "Enemy_Run.h"


Enemy_Run::~Enemy_Run() {
}
Enemy_Run::Enemy_Run() {
}

void Enemy_Run::setupAction() {
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

Enemy_Run* Enemy_Run::create(int level) {
	Enemy_Run* enemy = new Enemy_Run();
	enemy->setup(level, "Enemy_Run", EnemyType::Run);
	enemy->setupAction();

	return enemy;
}

