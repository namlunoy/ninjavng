#include "Pillar.h"
#include "Utility/Definition.h"
#include "Utility/Config.h"
#include "cocos2d.h"

Pillar::~Pillar(){}
//Pillar::Pillar(){}

Pillar::Pillar()
{
	sprite = Sprite::create("building.png");
	body = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(1, 0, 1));
	body->setDynamic(false);
	body->setCollisionBitmask(WALL_COLLISION);
	body->setContactTestBitmask(true);
	sprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	sprite->setPhysicsBody(body);
	//this->addChild(sprite);
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

Pillar* Pillar::createPillar(/*Point pos*/)
{
	Pillar* pillar = new Pillar();
	//pillar->setPosition(pos);
	return pillar;
}


Point Pillar::getCurrenPos()
{
	return this->getPosition();
}

void Pillar::SpawnPillar(Layer *layer, Point pos)
{
	this->addChild(sprite);
	layer->addChild(this);
	this->setPosition(pos);
	auto move = MoveBy::create(2, Vec2(222, 555));
	sprite->runAction(move);
}

void Pillar::MovePillar()
{
	auto movePillar = MoveBy::create(Config::screenSize.width * 0.05, Vec2(- Config::screenSize.width, 0));
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
	if ((body_a->getCollisionBitmask() == NINJA_COLLISION && body_b->getCollisionBitmask() == WALL_COLLISION)
		|| (body_a->getCollisionBitmask() == WALL_COLLISION && body_b->getCollisionBitmask() == NINJA_COLLISION))
	{
		CCLOG("contact");
		body_a->getNode()->stopAllActions();
		body_b->getNode()->stopAllActions();
	}

	return false;
}