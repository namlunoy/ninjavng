#include "Ninja.h"
#include "Power.h"
#include "Shuriken.h"
#include "Utility/Definition.h"
#include "Utility/Config.h"
#include "Layers/PhiTieu/Generator.h"
#include "Utility/Tags.h"
#include "Layers/PhiTieu/PhiTieuLayer.h"
#include "SimpleAudioEngine.h"

Ninja::Ninja(){}
Ninja::~Ninja(){}
Ninja* Ninja::Instance = nullptr;
Ninja* Ninja::create(string fileName)
{
	Ninja* ninja = new Ninja();
	ninja->init(fileName);
	ninja->autorelease();
	Ninja::Instance = ninja;
	return ninja;
}

bool Ninja::init(string fileName)
{
	if (!Node::init())
		return false;
	isAlive = true;
	Ninja::Instance = this;
	jumpCount = 0;
	isAvaiableToFire = true;

	//-------------  Khởi tạo sprite chính -------------
	_sprite = Sprite::create(fileName);
	_sprite->setPosition(0, 0);
	this->addChild(_sprite);

	//-------------   Physic Body  --------------
	_body = PhysicsBody::createBox(_sprite->getBoundingBox().size,PhysicsMaterial(_ninjaModel.density, _ninjaModel.restitution, _ninjaModel.friction));
	_body->setGravityEnable(false);
	_body->setDynamic(true);
	_body->setTag(Tags::NINJA);
	_body->setCollisionBitmask(1);
	_body->setContactTestBitmask(1);

	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setPhysicsBody(_body);


	//contact listner
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Ninja::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);


	return true;
}

void Ninja::runAnimation(string name, int count, float time, bool isRepeat)
{
	XHelper::runAnimation(name, count, time, true, this->_sprite);
}

void Ninja::fire(Vec2 src, Vec2 dest) {
	Vec2 huong = (dest - src);
	huong.normalize();
	auto su = Shuriken::createSuriken();
	su->setPosition(src);
	su->phong(huong);
	this->getParent()->addChild(su);
}


bool Ninja::onContactBegin(PhysicsContact& contact)
{
	auto a = contact.getShapeA()->getBody();
	auto b = contact.getShapeB()->getBody();


	//----------------   Va chạm vơi Enemy   ---------
	if(a != NULL && b != NULL && a->getNode() != NULL && b->getNode() != NULL)
	{
		if((a->getTag() == Tags::NINJA && b->getTag() == Tags::ENEMY)
				|| (a->getTag() == Tags::ENEMY && b->getTag() == Tags::NINJA))
		{
			log("Ninja::onContactBegin : NINJA vs ENEMY");
			auto e = a->getTag() == Tags::ENEMY ? a : b;
			e->getNode()->removeFromParent();
			PhiTieuLayer::instance->matMau();
		}

		else if((a->getTag() == Tags::NINJA && b->getTag() == Tags::HEART)
						|| (a->getTag() == Tags::HEART && b->getTag() == Tags::NINJA))
				{
					log("Ninja::onContactBegin : NINJA vs HEART");
					auto h = a->getTag() == Tags::HEART ? a : b;
					h->getNode()->removeFromParent();
					//Thêm trái tim
					PhiTieuHUDLayer::Instance->tangHeart();
		}else if((a->getTag() == Tags::NINJA && b->getTag() == Tags::ITEM)
				|| (a->getTag() == Tags::ITEM && b->getTag() == Tags::NINJA))
		{
			log("Ninja::onContactBegin : NINJA vs ITEM");
			auto h = a->getTag() == Tags::ITEM ? a : b;
			h->getNode()->removeFromParent();
			//Thêm trái tim
			Shuriken::nangCap();
			Power::nangCap();
		}
	}

	return false;
}

void Ninja::jump()
{
	jumpCount++;
	log("Ninja::jump()");
	int count = this->getActionManager()->getNumberOfRunningActionsInTarget(this);
	if(jumpCount <= 2)
	{
		this->getActionManager()->removeAllActionsFromTarget(this);
		auto jumpAction = JumpTo::create(1.0f, originalPosition, 300, 1);
		CallFunc *resetJump = CallFunc::create(CC_CALLBACK_0(Ninja::resetJumpCount, this));
		this->runAction(Sequence::create(jumpAction, resetJump, nullptr));
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound_PhiTieu/Jump.wav");
	}

}

void Ninja::resetJumpCount(){
	jumpCount = 0;
}


void Ninja::runAnimation_DungYen()
{
	runAnimation("DungYen", 2, 0.5f, true);
}

void Ninja::runAnimation_Nhay()
{
	//runAnimation("ninja_nhay", 2, 0.5f, true);
}

void Ninja::setOriginalPosition(Vec2 ori)
{
	this->originalPosition = ori;
}


