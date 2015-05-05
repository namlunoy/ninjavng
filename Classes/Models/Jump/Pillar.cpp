#include "Pillar.h"
#include "Utility/Definition.h"
#include "Utility/Config.h"
#include "cocos2d.h"

Pillar::~Pillar(){}
//Pillar::Pillar(){}

Pillar::Pillar()
{
	sprite = Sprite::create("Bamboo.png");
	this->addChild(sprite);
	body = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(1, 0, 1));
	body->setDynamic(false);
	//body->setGravityEnable(false);
	body->setCollisionBitmask(true);
	body->setTag(PILLAR_COLLISION);
	body->setContactTestBitmask(true);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setPhysicsBody(body);
}

bool Pillar::init()
{
	if (!Node::init())
		return false;

	//Contact
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Pillar::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

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

void Pillar::MovePillar(float duration)
{
	auto movePillar = MoveBy::create(duration, Vec2(-2.7f, 0));
	this->runAction(movePillar);
}

void Pillar::StopPillar()
{
	//this->getActionManager()->removeAllActionsFromTarget(this);
	this->stopAllActions();
}

bool Pillar::onContactBegin(PhysicsContact &contact)
{
	auto body_a = contact.getShapeA()->getBody();
	auto body_b = contact.getShapeB()->getBody();

	if (body_a->getCollisionBitmask() == PILLAR_COLLISION && body_b->getCollisionBitmask() == WALL_COLLISION)
	{
		if (body_a->getNode() != nullptr) body_a->getNode()->removeFromParent();
	}
	else if (body_a->getCollisionBitmask() == WALL_COLLISION && body_b->getCollisionBitmask() == PILLAR_COLLISION)
	{
		if (body_b->getNode() != nullptr) body_b->getNode()->removeFromParent();
	}

	if ((body_a->getTag() == WALL_COLLISION && body_b->getTag() == PILLAR_COLLISION)
		|| (body_a->getTag() == PILLAR_COLLISION && body_b->getTag() == WALL_COLLISION))
	{
		log("Pillar + Wall");
	}

	return true;
}
