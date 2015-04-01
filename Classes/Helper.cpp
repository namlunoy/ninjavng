#include "Helper.h"


Helper::Helper(){ }

Helper::~Helper(){ }

void Helper::runAnimation(string name, int count, float time, bool isRepeat,Sprite* _sprite)
{
	_sprite->getActionManager()->removeAllActionsFromTarget(_sprite);
	CCLOG(&name[0]);

	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile(name + ".plist");

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