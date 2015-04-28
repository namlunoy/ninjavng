#include "Models/Jump/Spring.h"

Spring::Spring()
{
	sprite = Sprite::create("spring.png");
	this->addChild(sprite);
	body = PhysicsBody::createBox(sprite->getBoundingBox().size, PhysicsMaterial(1, 0, 1));
	body->setAngularVelocityLimit(0.0f);
	body->setDynamic(false);
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