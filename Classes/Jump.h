#ifndef _JUMP_
#define _JUMP_

#include "cocos2d.h"

USING_NS_CC;

class Jump : public cocos2d::Layer {
public:
	static Scene* createScene();
	virtual bool init();
	void jump(Sprite *s, float height, float duration);
	CREATE_FUNC(Jump);
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	float height;
	Sprite *ninjaSprite;
};

#endif
