#include "Pillar.h"
#include "Utility/Definition.h"
#include "Utility/Config.h"
#include "cocos2d.h"

Pillar::~Pillar(){}

Pillar::Pillar()
{
	sprite = Sprite::create("Bamboo/Bamboo_2.png");
	this->addChild(sprite);
	body = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(100, 0, 100));
	body->setDynamic(false);
	body->setCollisionBitmask(true);
	body->setTag(PILLAR_COLLISION);
	body->setContactTestBitmask(true);
	body->setCategoryBitmask(0x03);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setPhysicsBody(body);
}

Pillar::Pillar(int i)
{
	char name[100];
	sprintf(name, "Bamboo/Bamboo_%d.png", i);
	sprite = Sprite::create(name);
	this->addChild(sprite);
	body = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(100, 0, 100));
	body->setDynamic(false);
	body->setCollisionBitmask(true);
	body->setTag(PILLAR_COLLISION);
	body->setContactTestBitmask(true);
	body->setCategoryBitmask(0x03);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setPhysicsBody(body);
}

bool Pillar::init()
{
	if (!Node::init())
		return false;
	
	isContactWithWall = false;

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

Pillar* Pillar::createPillar(int i)
{
	Pillar* pillar = new Pillar(i);
	pillar->init();
	pillar->autorelease();
	return pillar;
}

void Pillar::MovePillar(float duration)
{
	auto movePillar = MoveBy::create(duration, Vec2(-2.7f, 0));
	this->runAction(movePillar);
}

void Pillar::StopPillar()
{
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
	else if ((body_a->getCategoryBitmask() & body_b->getCollisionBitmask()) == 0
		|| (body_b->getCategoryBitmask() & body_a->getCollisionBitmask()) == 0)
	{
		isContactWithWall = true;
	}

	return true;
}