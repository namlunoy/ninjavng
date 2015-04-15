#include "Ninja_D.h"
#include "Utility/Definition.h"

Ninja_D::~Ninja_D(){}
Ninja_D::Ninja_D()
{
	sprite = Sprite::create("Ninja2.png");
	body = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(1.0f, 0.0f, 1.0f));
	body->setMass(10.0f);
	body->setAngularVelocityLimit(0.0f);
	body->setCollisionBitmask(NINJA_COLLISION);
	body->setContactTestBitmask(true);
	this->setPhysicsBody(body);
	this->addChild(sprite);
}

bool Ninja_D::init()
{
	if (!Node::init())
		return false;



	return true;
}

Ninja_D* Ninja_D::createNinja()
{
	Ninja_D* n = new Ninja_D();
	n->init();
	n->autorelease();
	return n;
}

void Ninja_D::JumpAction(float force)
{
	CCLOG("Force");
	body->applyForce(Vect(0, force));
}

