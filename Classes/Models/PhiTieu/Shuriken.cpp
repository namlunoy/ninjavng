#include "Shuriken.h"
#include "Utility/Tags.h"

Shuriken::~Shuriken(){}
float Shuriken::force = 700.0f;
Shuriken::Shuriken()
{
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	_sprite = Sprite::create("Shuriken.png");
	_sprite->setScale(0.11f);
	this->addChild(_sprite);
	// --------------- Physic  ------------
	//Đặc điểm: luôn quay, không chịu tác dụng của trọng lực, không chịu masat, ko va chạm

	_body = PhysicsBody::createBox(Size(20,20), PhysicsMaterial(1.0f, 0, 0));
	_body->setGravityEnable(false);
	_body->setMass(1.0f);
	_body->setAngularVelocity(-30);
	_body->setDynamic(true);
	_body->setTag(Tags::SHURIKEN);
	_body->setCollisionBitmask(true);
	_body->setContactTestBitmask(true);
	this->setPhysicsBody(_body);

	//adds contact event listener
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Shuriken::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);


}

Shuriken* Shuriken::createSuriken()
{
	Shuriken* shuriken = new Shuriken();
	if (shuriken && shuriken->init())
		shuriken->autorelease();
	else
		CC_SAFE_DELETE(shuriken);

	return shuriken;
}

bool Shuriken::init()
{
	if (!Node::init())
		return false;
	return true;
}

void Shuriken::phong(Vec2 direction)
{
	_body->applyImpulse(direction*force);
}

bool Shuriken::onContactBegin(PhysicsContact& contact)
{
	auto body_a = contact.getShapeA()->getBody();
	auto body_b = contact.getShapeB()->getBody();
	log("Shuriken::onContactBegin");
	if ((body_a->getTag() == Tags::SHURIKEN && body_b->getTag() == Tags::GROUND))
	{
		//log("Shuriken::onContactBegin : SHURIKEN vs GROUND");
		if (body_a->getNode() != nullptr)
			body_a->getNode()->removeFromParent();
	}
	else if ((body_a->getTag() == Tags::GROUND && body_b->getTag() == Tags::SHURIKEN))
	{
		//log("Shuriken::onContactBegin : GROUND vs SHURIKEN 2");
		if (body_b->getNode() != nullptr)
			body_b->getNode()->removeFromParent();
	}

	return false;
}
