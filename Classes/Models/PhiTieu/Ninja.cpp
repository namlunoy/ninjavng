﻿#include "Ninja.h"
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

	//Khởi tạo sprite chính
	_sprite = Sprite::create(fileName);
	_sprite->setPosition(0, 0);
	this->addChild(_sprite);

	//Thêm body
	_body = PhysicsBody::createBox(_sprite->getBoundingBox().size,
		PhysicsMaterial(_ninjaModel.density, _ninjaModel.restitution, _ninjaModel.friction));
	_body->setMass(_ninjaModel.mass);
	_body->setGravityEnable(false);
	_body->setAngularVelocityLimit(0.0f);
	_body->setTag(Tags::NINJA);
	_body->setCollisionBitmask(Tags::NINJA);
	_body->setContactTestBitmask(true);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	//add contact event listener
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Ninja::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
	//	schedule(CC_SCHEDULE_SELECTOR(PhysicsDemoCollisionProcessing::tick), 0.3f);

	this->setPhysicsBody(_body);

	return true;
}

void Ninja::runAnimation(string name, int count, float time, bool isRepeat)
{
	XHelper::runAnimation(name, count, time, true, this->_sprite);
}

//-------------------- Công -------------------------

void Ninja::jump()
{
	jumpCount++;
	log("Ninja::jump()");
	int count = this->getActionManager()->getNumberOfRunningActionsInTarget(this);
	if(jumpCount <= 2)
	{

		this->getActionManager()->removeAllActionsFromTarget(this);
		auto jumpAction = JumpTo::create(1.0f, originalPosition, 300, 1);
		//auto action = Sequence::create(jumpAction,CC_CALLBACK_0(Ninja::resetJumpCount));
		this->runAction(jumpAction);
	}

}

void Ninja::resetJumpCount()
{
	jumpCount = 0;
}

bool Ninja::onContactBegin(PhysicsContact& contact)
{
	auto bodyA = contact.getShapeA()->getBody();
	auto bodyB = contact.getShapeB()->getBody();
	//log("%s", Tags::getName(bodyA->getTag()));
	//log("%s", Tags::getName(bodyB->getTag()));
	return false;
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



