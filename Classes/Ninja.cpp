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

void Ninja::runAnimation( string name, int count, float time, bool isRepeat)
{
	
	name = "ninja_dungyen";
	
	//Nạp file mô tả plist vào cache
	CCLOG(&name[0]);
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile(name + ".plist");

	//Nạp spritesheet vào batch
	SpriteBatchNode* spriteSheet = SpriteBatchNode::create(name + ".png");

	//Chuyển thành sprite frame
	Vector<SpriteFrame*> frames(count);
	char frameName[100];
	for (int i = 1; i <= count; i++)
	{
		sprintf(frameName, "%s%d.png", &name[0], i);
		CCLOG("framename : %s", frameName);
		auto frame = cache->getSpriteFrameByName(frameName);
		frames.pushBack(frame);
	}

	//Tạo animation từ frames
	Animation* animation = Animation::createWithSpriteFrames(frames, time);
	Action* action = nullptr;
	if (isRepeat)
		action = RepeatForever::create(Animate::create(animation));
	else action = Animate::create(animation);


	Sprite* spriteAnimate = Sprite::createWithSpriteFrameName(frameName);
	spriteAnimate->runAction(action);
	spriteSheet->addChild(spriteAnimate);
	spriteSheet->setPosition(100, 100);
	this->addChild(spriteSheet);
}

//-------------------- Công -------------------------

//--------------------- Đăng ------------------------