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
	cache = SpriteFrameCache::getInstance();
	return true;
}

void Ninja::runAnimation(string name, int count, float time, bool isRepeat)
{
	this->_actionManager->removeAllActions();
	//Nạp file mô tả plist vào cache
	CCLOG(&name[0]);
	//SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	//cache->addSpriteFramesWithFile(name + ".plist");


	//Chuyển thành sprite frame
	Animation* animation = Animation::create();
	animation->setDelayPerUnit(time);
	char frameName[100];
	for (int i = 1; i <= count; i++)
	{
		sprintf(frameName, "%s%d.png", &name[0], i);
		CCLOG("framename : %s", frameName);
		auto frame = cache->getSpriteFrameByName(frameName);
		animation->addSpriteFrame(frame);
	}

	Action* action = nullptr;
	if (isRepeat)
		action = RepeatForever::create(Animate::create(animation));
	else action = Animate::create(animation);


	_sprite->runAction(action);

}

//-------------------- Công -------------------------
void Ninja::addPlistFile(string fileName)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(fileName);
}


//--------------------- Đăng ------------------------

void Ninja::jumpAction()
{
	auto jump = JumpTo::create(1.5, this->getPosition(), 50, 1);
	this->runAction(jump);
	this->isJumping = true;
	CCLOG("___%d", this->isJumping);
}

