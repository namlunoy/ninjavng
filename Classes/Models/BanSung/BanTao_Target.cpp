#include "BanTao_Target.h"
#include "Utility/Config.h"

BanTao_Target::BanTao_Target(){}
BanTao_Target::~BanTao_Target(){}

BanTao_Target* BanTao_Target::create(string fileName, float speed)
{
	BanTao_Target* target = new BanTao_Target();
	if (target && target->init(fileName))
		target->autorelease();
	else CC_SAFE_DELETE(target);

	//target->moveAction(speed);
	target->setPosition(Config::centerPoint.x + 180, Config::centerPoint.y  -30 + 155);
	target->setScale(0.1);
	target->setTag(13);

	return target;
}

bool BanTao_Target::init(string fileName)
{
	if (!Node::init())
		return false;
	_sprite = Sprite::create(fileName);
	this->addChild(_sprite);
	return true;
}


void BanTao_Target::moveAction(float speed)
{
	
	auto moveTo1 = MoveTo::create(speed, Vec2(Config::centerPoint.x - 180, Config::centerPoint.y - 30 + 155));
	auto moveTo2 = MoveTo::create(speed, Vec2(Config::centerPoint.x, Config::centerPoint.y + 155));
	auto moveTo3 = MoveTo::create(speed, Vec2(Config::centerPoint.x + 180, Config::centerPoint.y  -30 + 155));


	auto delay = DelayTime::create(0);
	this->runAction(CCRepeatForever::create(Sequence::create(moveTo3, moveTo1, moveTo2, nullptr)));
	this->isMove = true;
}

void BanTao_Target :: setScaleTarget(float scale)
{
	this->setScale(scale);
}

