#include "Ninja_D.h"
#include "Utility/Definition.h"

Ninja_D::~Ninja_D(){}
Ninja_D::Ninja_D(Layer *layer)
{
	auto ninja = Sprite::create("Ninja2.png");
	ninja->setPosition(100, 220);
	bodyNinja = PhysicsBody::createBox(Size(ninja->getBoundingBox().size), PhysicsMaterial(1.0f, 1.0f, 1.0f));
	bodyNinja->setMass(1.0f);
	bodyNinja->setAngularVelocityLimit(0.0f);
	bodyNinja->setCollisionBitmask(NINJA_COLLISION);
	bodyNinja->setContactTestBitmask(true);
	ninja->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	ninja->setPhysicsBody(bodyNinja);
	layer->addChild(ninja);
}

void Ninja_D::JumpAction(float force)
{
	CCLOG("Force Ninja");
	bodyNinja->applyForce(Vect(0, force));
}

