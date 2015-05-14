#include "Enemy.h"
#include "Layers/PhiTieu/PhiTieuHUDLayer.h"
#include "Scenes/PhiTieuScene.h"
#include "SimpleAudioEngine.h"
#include "Models/PhiTieu/Ninja.h"
#include "Layers/PhiTieu/Generator.h"

Enemy::~Enemy(){}
Enemy::Enemy(){}



int Enemy::getLevel()
{
	return PhiTieuScene::GetLevel();
}

void Enemy::DestroyIfDie()
{
	if (!Ninja::Instance->isAlive)
		this->removeFromParent();
}

bool Enemy::onContact(PhysicsContact& contact) {

	auto a = contact.getShapeA()->getBody();
	auto b = contact.getShapeB()->getBody();

	if(a != NULL && b != NULL && a->getNode() != NULL && b->getNode() != NULL)
	{
		//Tuong tac voi phitieu
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound_PhiTieu/Kill.mp3");
		if((a->getTag() == Tags::SHURIKEN && b->getTag() == Tags::ENEMY)
			|| (a->getTag() == Tags::ENEMY && b->getTag() == Tags::SHURIKEN) )
		{
			log("Enemy::onContact : ENEMY vs SHURIKEN");
			b->getNode()->removeFromParent();
			a->getNode()->removeFromParent();
			PhiTieuHUDLayer::Instance->tangDiem();
			
		}

		//Tuong tac voi thanh
		if((a->getTag() == Tags::ENEMY && b->getTag() == Tags::TARGET)
				|| (a->getTag() == Tags::TARGET && b->getTag() == Tags::ENEMY))
		{
			log("Enemy::onContact : ENEMY vs TARGET");
			PhysicsBody* e = a->getTag() == Tags::ENEMY?a:b;
			e->getNode()->removeFromParent();

			//Xử lý game over
			Ninja::Instance->isAlive = false;
			log("Contact");
			log(Ninja::Instance->isAlive);
			PhiTieuLayer::instance->gameOver();
		}

		//Va voi thang ninja thi viet ben kia roi
	}

	return false;
}

void Enemy::setup( std::string fileName, EnemyType type) {
	this->autorelease();

	
	_fileName = fileName;
	_type = type;

	//---------  Sprite --------
	_sprite = Sprite::create("Enemy.png");
	//Đoạn này đòi hỏi các hình ảnh kích thước phải giống nhau, không thể mỗi cái scale 1 kiểu được (có nhưng làm thế nó dối)
	_sprite->setScale(0.1f);
	this->addChild(_sprite);


	//--------------  PhysicsBody --------------
	_body = PhysicsBody::createBox(_sprite->getBoundingBox().size,PhysicsMaterial(1, 0, 0));
	_body->setGravityEnable(false);
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
