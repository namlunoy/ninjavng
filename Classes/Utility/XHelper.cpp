#include "XHelper.h"


XHelper::XHelper(){ }

XHelper::~XHelper(){ }

void XHelper::runAnimation(string name, int count, float time, bool isRepeat, Sprite* _sprite)
{
	if (_sprite != nullptr)
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
	else{
		log("XHelper::runAnimation : _sprite iss null");
	}

}

void XHelper::Log(Node* node, string tag)
{
	log("--------  %s --------", &tag[0]);
	log("BoundingBox : %f x %f", node->getBoundingBox().size.width, node->getBoundingBox().size.height);
	log("Position : (%f , %f)", node->getPosition().x, node->getPosition().y);
	log("ContentSize: %f x %f", node->getContentSize().width, node->getContentSize().height);
	log("Anchor: (%f , %f)", node->getAnchorPoint().x, node->getAnchorPoint().y);
}
