#include "Ninja_D.h"
#include "Utility/Definition.h"

Ninja_D::~Ninja_D(){}
Ninja_D::Ninja_D()
{
	sprite = Sprite::create("Ninja2.png");
	this->addChild(sprite);
	body = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(1.0f, 0.0f, 1.0f));
	body->setMass(60.0f);
	body->setAngularVelocityLimit(0.0f);
	body->setRotationEnable(false);
	body->setTag(NINJA_COLLISION);
	body->setDynamic(true);
	body->setLinearDamping(0.5);
	body->setCollisionBitmask(0x02);
	body->setContactTestBitmask(true);
	body->setCategoryBitmask(0x01);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setPhysicsBody(body);
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
	this->isJumping = true;
	body->applyImpulse(Vect(0, force));
}

bool Ninja_D::onContactBegin(PhysicsContact &contact)
{
	auto body_a = contact.getShapeA()->getBody();
	auto body_b = contact.getShapeB()->getBody();

	/*if ((body_a->getCollisionBitmask() == NINJA_COLLISION && body_b->getCollisionBitmask() == PILLAR_COLLISION)
		|| (body_a->getCollisionBitmask() == PILLAR_COLLISION && body_b->getCollisionBitmask() == NINJA_COLLISION))
	{
		this->isJumping = false;
		this->body->resetForces();
	} 
	else if ((body_a->getCollisionBitmask() == NINJA_COLLISION && body_b->getCollisionBitmask() == WALL_COLLISION)
			|| (body_a->getCollisionBitmask() == WALL_COLLISION && body_b->getCollisionBitmask() == NINJA_COLLISION))
		{
			this->isDeath = true;
		}
	else if ((body_a->getCollisionBitmask() == NINJA_COLLISION && body_b->getCollisionBitmask() == SCORE_COLLISION)
			|| (body_a->getCollisionBitmask() == SCORE_COLLISION && body_b->getCollisionBitmask() == NINJA_COLLISION))
		{
			this->isJumping = false;
			this->body->resetForces();
			finishJump = true;
			log("CC");
		}*/

	if ((body_a->getTag() == NINJA_COLLISION && body_b->getTag() == PILLAR_COLLISION)
		|| (body_a->getTag() == PILLAR_COLLISION && body_b->getTag() == NINJA_COLLISION))
	{
		this->isJumping = false;
		this->body->resetForces();
	}
	else if ((body_a->getTag() == NINJA_COLLISION && body_b->getTag() == GROUND_COLLISION)
		|| (body_a->getTag() == GROUND_COLLISION && body_b->getTag() == NINJA_COLLISION))
	{
		this->isDeath = true;
	}
	else if ((body_a->getCategoryBitmask() & body_b->getCollisionBitmask()) == 0
			|| (body_b->getCategoryBitmask() & body_a->getCollisionBitmask()) == 0)
	{
		//this->isJumping = false;
		//this->body->resetForces();
		finishJump = true;
		log("CC");
	}

	return true;
}