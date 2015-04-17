#include "Ninja_D.h"
#include "Utility/Definition.h"

Ninja_D::~Ninja_D(){}
Ninja_D::Ninja_D()
{
	sprite = Sprite::create("Ninja2.png");
	body = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(1.0f, 0.0f, 1.0f));
	body->setMass(3.0f);
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

	//Contact
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Ninja_D::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);


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

bool Ninja_D::onContactBegin(PhysicsContact &contact)
{
	auto body_a = contact.getShapeA()->getBody();
	auto body_b = contact.getShapeB()->getBody();
	if ((body_a->getCollisionBitmask() == NINJA_COLLISION && body_b->getCollisionBitmask() == WALL_COLLISION)
		|| (body_a->getCollisionBitmask() == WALL_COLLISION && body_b->getCollisionBitmask() == NINJA_COLLISION))
	{
		CCLOG("contact");
		isJumping = false;
		body_a->getNode()->stopAllActions();
		body_b->getNode()->stopAllActions();
	}
	else

		return true;
}