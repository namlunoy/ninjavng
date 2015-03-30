#ifndef _JumpLayer_
#define _JumpLayer_
#include "cocos2d.h"
#include "D_Ninja.h"
USING_NS_CC;

class D_Jump_Layer:public Layer
{
public:
	~D_Jump_Layer();
	bool init();
	CREATE_FUNC(D_Jump_Layer);
	D_Ninja *ninja;
	//Touch
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
};

#endif
