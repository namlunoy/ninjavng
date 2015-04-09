#include "Ninja_D.h"

Ninja_D::~Ninja_D(){}
Ninja_D::Ninja_D(Layer *layer)
{
	auto ninja = Sprite::create("Ninja2.png");
	ninja->setPosition(100, 250);
	bodyNinja = PhysicsBody::createBox(Size(ninja->getBoundingBox().size));
	bodyNinja->setMass(1.0f);
	bodyNinja->setGravityEnable(true);
	bodyNinja->setAngularVelocityLimit(0.0f);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	ninja->setPhysicsBody(bodyNinja);
	layer->addChild(ninja);
}

void Ninja_D::JumpAction(float force)
{
	CCLOG("Force Ninja");
	bodyNinja->applyForce(Vect(0, force));
}

