#ifndef _JumpScene_
#define _JumpScene_
#include "cocos2d.h"
#include "D_Jump_Layer.h"
#include "cocos2d.h"
USING_NS_CC;

class D_Jump_Scene:public cocos2d::Scene
{
public:
	D_Jump_Scene();
	~D_Jump_Scene();
	bool init();
	CREATE_FUNC(D_Jump_Scene);
private:
	D_Jump_Layer *layer;
};

#endif