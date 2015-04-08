#include "Ninja_D.h"

Ninja_D::Ninja_D(){}
Ninja_D::~Ninja_D(){}
Ninja_D::Ninja_D(Layer *layer)
{
	auto ninja = Sprite::create("Ninja2.png");
	ninja->setPosition(100, 200);
	bodyNinja = PhysicsBody::createBox(Size(ninja->getContentSize()), PhysicsMaterial(1.0f, 0.0f, 0.0f));
	//bodyNinja->setMass(1.0f);
	ninja->setPhysicsBody(bodyNinja);
	layer->addChild(ninja);
}

void Ninja_D::JumpAction(float force)
{
	bodyNinja->applyForce(Vect(0, force));
}

