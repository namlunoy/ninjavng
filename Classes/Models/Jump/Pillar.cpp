#include "Pillar.h"
#include "Utility/Definition.h"
#include "Utility/Config.h"
#include "cocos2d.h"

Pillar::~Pillar(){}
//Pillar::Pillar(){}

Pillar::Pillar()
{
	sprite = Sprite::create("building.png");
	this->addChild(sprite);
	body = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(1, 0, 0));
	body->setDynamic(false);
	body->setCollisionBitmask(WALL_COLLISION);
	body->setContactTestBitmask(true);
	this->setPhysicsBody(body);
}

bool Pillar::init()
{
	if (!Node::init())
		return false;

	////Contact
	//auto contactListener = EventListenerPhysicsContact::create();
	//contactListener->onContactBegin = CC_CALLBACK_1(Pillar::onContactBegin, this);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	return true;
}

Pillar* Pillar::createPillar()
{
	Pillar* pillar = new Pillar();
	pillar->init();
	pillar->autorelease();
	return pillar;
}

Point Pillar::getCurrenPos()
{
	return this->getPosition();
}

void Pillar::MovePillar(Vec2 vec)
{
	auto movePillar = MoveBy::create(10, vec);
	this->runAction(movePillar);
}

void Pillar::StopPillar()
{
	this->stopAllActions();
}

//bool Pillar::onContactBegin(PhysicsContact &contact)
//{
//	auto body_a = contact.getShapeA()->getBody();
//	auto body_b = contact.getShapeB()->getBody();
//	if ((body_a->getCollisionBitmask() == NINJA_COLLISION && body_b->getCollisionBitmask() == WALL_COLLISION)
//		|| (body_a->getCollisionBitmask() == WALL_COLLISION && body_b->getCollisionBitmask() == NINJA_COLLISION))
//	{
//		CCLOG("contact");
//
//		body_a->getNode()->stopAllActions();
//		body_b->getNode()->stopAllActions();
//	} else 
//
//	return true;
//}