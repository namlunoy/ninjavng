#include "BanTao_Apple.h"
#include "Utility/Config.h"

BanTao_Apple::BanTao_Apple(){}
BanTao_Apple::~BanTao_Apple(){}

BanTao_Apple* BanTao_Apple::create(string fileName)
{
	BanTao_Apple* apple = new BanTao_Apple();
	if (apple && apple->init(fileName))
		apple->autorelease();
	else CC_SAFE_DELETE(apple);

	//target->moveAction(speed);
	//apple->setPosition(Config::centerPoint.x + 180, Config::centerPoint.y - 30 + 155);
	//apple->setScale(0.1);
	apple->setTag(13);

	return apple;
}

bool BanTao_Apple::init(string fileName)
{
	if (!Node::init())
		return false;
	_sprite = Sprite::create(fileName);
	this->addChild(_sprite);
	return true;
}

void BanTao_Apple::setPotionApple(Vec2 potision)
{
	this->setPosition(potision);
}


void BanTao_Apple::setScaleApple(float scale)
{
	this->setScale(scale);
}

