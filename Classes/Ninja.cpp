#include "Ninja.h"


Ninja::Ninja(){}
Ninja::~Ninja(){}

Ninja* Ninja::create(string fileName)
{
	Ninja* ninja = new Ninja();
	if (ninja && ninja->init(fileName))
		ninja->autorelease();
	else CC_SAFE_DELETE(ninja);
	return ninja;
}

bool Ninja::init(string fileName)
{
	if (!Node::init())
		return false;
	_sprite = Sprite::create(fileName);
	this->addChild(_sprite);
	return true;
}

//-------------------- Công -------------------------



//--------------------- Đăng ------------------------

void Ninja::jumpAction()
{
	auto jump = JumpTo::create(1.5, this->getPosition(), 50, 1);
	this->runAction(jump);
	this->isJumping = true;
	CCLOG("___%d", this->isJumping);
}