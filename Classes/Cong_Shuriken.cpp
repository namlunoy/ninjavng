#include "Cong_Shuriken.h"

Cong_Shuriken::Cong_Shuriken(Vec2 start)
{
	_sprite = Sprite::create("Shuriken.png");
	this->addChild(_sprite);
	this->setPosition(start);
}

Cong_Shuriken* Cong_Shuriken::createSuriken(Vec2 start)
{
	Cong_Shuriken* shuriken = new Cong_Shuriken(start);
	return shuriken;
}

bool Cong_Shuriken::init()
{
	return true;

}