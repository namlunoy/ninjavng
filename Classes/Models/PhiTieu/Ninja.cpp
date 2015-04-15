#include "Ninja.h"
#include "Utility/Definition.h"
#include "Utility/Config.h"
#include "Utility/Tags.h"

Ninja::Ninja(){}
Ninja::~Ninja(){}

Ninja* Ninja::create(string fileName)
{
	Ninja* ninja = new Ninja();
	if (ninja && ninja->init(fileName))
		ninja->autorelease();
	else CC_SAFE_DELETE(ninja);
	return ninja;
}

bool Ninja::init(string fileName)
{
	if (!Node::init())
		return false;

	//this->scheduleUpdate();
	jumpCount = 0;
	//contact listner
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Ninja::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	//Khởi tạo sprite chính
	_sprite = Sprite::create(fileName);
	_sprite->setPosition(0, 0);
	this->addChild(_sprite);

	//Thêm body
	_body = PhysicsBody::createBox(_sprite->getBoundingBox().size,
		PhysicsMaterial(_ninjaModel.density, _ninjaModel.restitution, _ninjaModel.friction));
	_body->setMass(_ninjaModel.mass);
	_body->setDynamic(false);
	_body->setGravityEnable(false);
	_body->setAngularVelocityLimit(0.0f);
	_body->setTag(Tags::NINJA);
	_body->setCollisionBitmask(Tags::NINJA);
	_body->setContactTestBitmask(true);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setPhysicsBody(_body);

	return true;
}

void Ninja::runAnimation(string name, int count, float time, bool isRepeat)
{
	XHelper::runAnimation(name, count, time, true, this->_sprite);
}

bool Ninja::onContactBegin(PhysicsContact& contact)
{
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
		CallFunc *runCallback = CallFunc::create(CC_CALLBACK_0(Ninja::resetJumpCount, this));
		//DelayTime::create(1)
		this->runAction(Sequence::create(jumpAction, runCallback, nullptr));
		//this->runAction();
	}

}

void Ninja::resetJumpCount()
{
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




