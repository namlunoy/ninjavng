#include "Enemy.h"


Enemy::Enemy(){
	log("Enemy()");
}

Enemy::~Enemy(){}

bool Enemy::onContact(PhysicsContact& contact) {

	auto a = contact.getShapeA()->getBody();
	auto b = contact.getShapeB()->getBody();

	if(a != NULL && b != NULL)
	{
		log("Enemy::onContact: %d",a->getTag());
	}

	//log("Enemy::onContact");
	return false;
}

void Enemy::setup(int level, std::string fileName, EnemyType type) {
	this->autorelease();

	_level = level;
	_fileName = fileName;
	_type = type;

	//---------  Sprite --------
	std::string file = fileName + "1.png";
	_sprite = Sprite::create(file);
	//Đoạn này đòi hỏi các hình ảnh kích thước phải giống nhau, không thể mỗi cái scale 1 kiểu được (có nhưng làm thế nó dối)
	_sprite->setScale(0.1f);
	this->addChild(_sprite);


	//--------------  PhysicsBody --------------
	_body = PhysicsBody::createBox(_sprite->getBoundingBox().size,PhysicsMaterial(1, 0, 0));
	_body->setDynamic(false);

	_body->setCollisionBitmask(true);
	_body->setContactTestBitmask(true);

	_body->setTag(Tags::ENEMY);
	this->setPhysicsBody(_body);



	//--------------- Bắt sự kiện va chạm  ---------------------
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Enemy::onContact,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	//------------- Chạy animation hiện tại ----------
		XHelper::runAnimation(_fileName, 2, 0.2f, true, _sprite);

}
