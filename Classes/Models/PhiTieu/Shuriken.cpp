#include "Shuriken.h"
#include "Utility/Tags.h"

Shuriken::~Shuriken(){}

Shuriken::Shuriken()
{
	_sprite = Sprite::create("Shuriken.png");
	_body = PhysicsBody::createBox(this->getBoundingBox().size, PhysicsMaterial(0.1f,0,0));
	_body->setGravityEnable(false);
	_body->setAngularVelocity(30);

	_body->setCollisionBitmask(Tags::SHURIKEN);
	_body->setContactTestBitmask(true);

	//adds contact event listener
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Shuriken::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	//schedule(CC_SCHEDULE_SELECTOR(PhysicsDemoCollisionProcessing::tick), 0.3f);

	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setPhysicsBody(_body);
	this->addChild(_sprite);
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

void Shuriken::phong(Vec2 huong)
{
	log("huong: %f - %f", huong.x, huong.y);
	_body->applyForce(huong);
}

bool Shuriken::onContactBegin(PhysicsContact& contact)
{
	auto body_a = contact.getShapeA()->getBody();
	auto body_b = contact.getShapeB()->getBody();
	
	if ((body_a->getCollisionBitmask() == Tags::SHURIKEN && body_b->getCollisionBitmask() == Tags::NINJA) ||
		(body_a->getCollisionBitmask() == Tags::NINJA && body_b->getCollisionBitmask() == Tags::SHURIKEN))
	{
		log("Cham!ccc");
		return false;
	}
	
	return true;
}