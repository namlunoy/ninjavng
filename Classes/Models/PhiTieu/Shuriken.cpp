#include "Shuriken.h"

Shuriken::Shuriken(){}
Shuriken::~Shuriken(){}

Shuriken::Shuriken(Vec2 start)
{
	_sprite = Sprite::create("Shuriken.png");
	this->addChild(_sprite);
	this->setPosition(start);
}

Shuriken* Shuriken::createSuriken(Vec2 start)
{
	Shuriken* shuriken = new Shuriken(start);
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
