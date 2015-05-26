#include "Models/Jump/Spring.h"
#include "Utility/Definition.h"

Spring::Spring()
{
	sprite = Sprite::create("Jump_Sprite/Spring_3.png");
	sprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	sprite->setPosition(Point(0, -sprite->getContentSize().height / 2));
	this->addChild(sprite);
	body = PhysicsBody::createBox(sprite->getBoundingBox().size, PhysicsMaterial(100, 0, 100));
	body->setMass(1000000.0f);
	body->setRotationEnable(false);
	body->setDynamic(true);
	body->setCollisionBitmask(SPRING_COLLISION);
	body->setContactTestBitmask(true);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
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