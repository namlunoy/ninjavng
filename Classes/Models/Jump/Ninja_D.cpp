#include "Ninja_D.h"
#include "Utility/Definition.h"

Ninja_D::~Ninja_D(){}
Ninja_D::Ninja_D()
{
	sprite = Sprite::create("Jump_Sprite/Ninja2.png");
	sprite->setAnchorPoint(Vec2(0.62f, 0.022f));
	this->addChild(sprite);
	body = PhysicsBody::createBox(Size(30, 2), PhysicsMaterial(100.0f, 0.0f, 100.0f), Vec2(0,0));
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
	
	//Thuộc tính Ninja
	isDeath = false;
	isJumping = false;
	finishJump = false;
	isableJump = true;
	xScore = 0;

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
	this->isableJump = false;
	if (body != nullptr && body->getNode() != nullptr)
		body->applyImpulse(Vect(0, force));
}

bool Ninja_D::onContactBegin(PhysicsContact &contact)
{
	auto body_a = contact.getShapeA()->getBody();
	auto body_b = contact.getShapeB()->getBody();

	//Ninja vs Pillar
	if ((body_a->getTag() == NINJA_COLLISION && body_b->getTag() == PILLAR_COLLISION)
		|| (body_a->getTag() == PILLAR_COLLISION && body_b->getTag() == NINJA_COLLISION))
	{
		this->isJumping = false;
	}
	//Ninja vs Ground
	else if ((body_a->getTag() == NINJA_COLLISION && body_b->getTag() == GROUND_COLLISION)
		|| (body_a->getTag() == GROUND_COLLISION && body_b->getTag() == NINJA_COLLISION))
	{
		this->isJumping = false;
		this->isDeath = true;
		this->getPhysicsBody()->removeFromWorld();
		this->sprite->removeFromParent();
	}
	//Ninja vs xScore Node
	else if ((body_a->getCategoryBitmask() & body_b->getCollisionBitmask()) == 0
		|| (body_b->getCategoryBitmask() & body_a->getCollisionBitmask()) == 0)
	{
		this->xScore++;
	}
	//Ninja vs Score Node
	else if (body_a->getTag() == SCORE_COLLISION && body_b->getTag() == NINJA_COLLISION)
	{
		body_a->removeFromWorld();
		body_a->getNode()->removeFromParent();
		this->isJumping = false;
		this->finishJump = true;
		this->isableJump = true;
	}
	else if (body_a->getTag() == NINJA_COLLISION && body_b->getTag() == SCORE_COLLISION)
	{
		body_b->removeFromWorld();
		body_b->getNode()->removeFromParent();
		this->isJumping = false;
		this->finishJump = true;
		this->isableJump = true;
	}

	return true;
}
