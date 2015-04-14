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
	//sprite->setPosition(0, CCRANDOM_0_1()*sprite->getContentSize().height / 2);
	sprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	sprite->setPhysicsBody(body);
	this->addChild(sprite);
}

bool Pillar::init()
{
	if (!Node::init())
		return false;
	return true;
}

Pillar* Pillar::createPillar(/*Point pos*/)
{
	Pillar* pillar = new Pillar();
	//pillar->setPosition(pos);
	return pillar;
}

void Pillar::SpawnPillar(Layer *layer, Point pos)
{
	layer->addChild(this);
	this->setPosition(pos);
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
//Chưa chạy