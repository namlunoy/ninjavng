#include "Models/Jump/Spring.h"
#include "Utility/Definition.h"

Spring::Spring()
{
	sprite = Sprite::create("spring.png");
	this->addChild(sprite);
	body = PhysicsBody::createBox(sprite->getBoundingBox().size, PhysicsMaterial(1, 0, 0));
	body->setRotationEnable(false);
	body->setDynamic(false);
	body->setCollisionBitmask(SPRING_COLLISION);
	body->setContactTestBitmask(true);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setPhysicsBody(body);
};

bool Spring::init()
{
	if (!Node::init())
		return false;
	return true;
}

Spring* Spring::createSpring()
{
	Spring* sp = new Spring();
	sp->init();
	sp->autorelease();
	return sp;
}

void Spring::ScaleUpSpring(float s)
{	

}

void Spring::ScaleDownSpring(float s)
{
	this->setScaleY(s);
}