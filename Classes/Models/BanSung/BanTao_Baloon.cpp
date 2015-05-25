#include "BanTao_Baloon.h"
#include "Utility/Config.h"

BanTao_Baloon::BanTao_Baloon(){}
BanTao_Baloon::~BanTao_Baloon(){}

BanTao_Baloon* BanTao_Baloon::create(string fileName)
{
	BanTao_Baloon* baloon = new BanTao_Baloon();
	if (baloon && baloon->init(fileName))
		baloon->autorelease();
	else CC_SAFE_DELETE(baloon);
	return baloon;
}

bool BanTao_Baloon::init(string fileName)
{
	if (!Node::init())
		return false;
	_sprite = Sprite::create(fileName);
	this->addChild(_sprite);
	return true;
}

void BanTao_Baloon::boom()
{
	// tạo paticle
	auto emitter = CCParticleFireworks::create();
	emitter->setPosition(this->getPosition());
	emitter->setDuration(0.5);
	this->addChild(emitter, 10);
}

