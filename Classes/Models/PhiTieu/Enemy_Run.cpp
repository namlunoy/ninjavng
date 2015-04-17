#include "Enemy_Run.h"
#include "Utility/XHelper.h"

Enemy_Run::~Enemy_Run() {
}
Enemy_Run::Enemy_Run() {
	//Enemy::Enemy();
	_fileName = "Enemy_Run";
	this->autorelease();

	//---------  Sprite --------
	_sprite = Sprite::create("Enemy_Run1.png");
	_sprite->setScale(0.1f);
	this->addChild(_sprite);

	//--------------  PhysicsBody --------------
	_body = PhysicsBody::createBox(_sprite->getBoundingBox().size,
			PhysicsMaterial(1, 0, 0));
	_body->setCollisionBitmask(Tags::ENEMY);

	_body->setContactTestBitmask(true);
	_body->setGravityEnable(false);
	_body->setDynamic(false);
	this->setPhysicsBody(_body);

	//--------------  Sự kiện va chạm --------------
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Enemy_Run::onDestroy, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener,this);

	//------------- Chạy animation hiện tại ----------
	XHelper::runAnimation(_fileName, 2, 0.2f, true, _sprite);
}

void Enemy_Run::setupAction() {
	float time = 0;
	switch (_level) {
	case 1:
		//Tính toán thời gian
		_speed = 130;
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

bool Enemy_Run::onDestroy(PhysicsContact& contact) {
	log("Enemy_Run::onDestroy");
	this->getActionManager()->removeAllActionsFromTarget(this);
	_sprite->setVisible(false);
	auto particle = ParticleFireworks::create();
	particle->setDuration(3);
	this->addChild(particle);
	return false;
}

