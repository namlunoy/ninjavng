#ifndef _JumpLayer_
#define _JumpLayer_
#include "cocos2d.h"
#include "Models/Ninja.h"
USING_NS_CC;

class JumpLayer:public Layer
{
public:
	~JumpLayer();
	bool init();
	CREATE_FUNC(JumpLayer);
	Ninja *ninja;
	//Touch
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
private:
	cocos2d::PhysicsWorld *physicsWorld;
};

#endif
