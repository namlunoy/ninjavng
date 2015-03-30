#include "Cong_Shuriken.h"

Cong_Shuriken::Cong_Shuriken(){}
Cong_Shuriken::~Cong_Shuriken(){}

Cong_Shuriken::Cong_Shuriken(Vec2 start)
{
	_sprite = Sprite::create("Shuriken.png");
	this->addChild(_sprite);
	this->setPosition(start);
}

Cong_Shuriken* Cong_Shuriken::createSuriken(Vec2 start)
{
	Cong_Shuriken* shuriken = new Cong_Shuriken(start);
	if (shuriken && shuriken->init())
		shuriken->autorelease();
	else
		CC_SAFE_DELETE(shuriken);
		
	return shuriken;
}

bool Cong_Shuriken::init()
{
	if (!Node::init())
		return false;
	return true;
}