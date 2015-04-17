#include "Models/Jump/Spring.h"

Spring::Spring()
{
	sprite = Sprite::create("spring.png");
	body = PhysicsBody::createBox(sprite->getBoundingBox().size, PhysicsMaterial(1, 0, 1));
	body->setAngularVelocityLimit(0.0f);
	body->setDynamic(false);
	this->setPhysicsBody(body);
	this->addChild(sprite);
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
	return sp;
}
