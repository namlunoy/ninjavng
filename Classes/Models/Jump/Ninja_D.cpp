#include "Ninja_D.h"
#include "Utility/Definition.h"

Ninja_D::~Ninja_D(){}
Ninja_D::Ninja_D()
{
	sprite = Sprite::create("Ninja2.png");
	bodyNinja = PhysicsBody::createBox(Size(sprite->getBoundingBox().size), PhysicsMaterial(1.0f, 1.0f, 1.0f));
	bodyNinja->setMass(1.0f);
	bodyNinja->setAngularVelocityLimit(0.0f);
	bodyNinja->setCollisionBitmask(NINJA_COLLISION);
	bodyNinja->setContactTestBitmask(true);
	sprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->addChild(sprite);
	this->setPhysicsBody(bodyNinja);
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
	CCLOG("Force Ninja");
	bodyNinja->applyForce(Vect(0, force));
}

