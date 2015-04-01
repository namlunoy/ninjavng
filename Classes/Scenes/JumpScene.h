#ifndef _JumpScene_
#define _JumpScene_
#include "cocos2d.h"
#include "Layers/JumpLayer.h"
#include "cocos2d.h"
USING_NS_CC;

class JumpScene:public cocos2d::Scene
{
public:
	JumpScene();
	~JumpScene();
	bool init();
	CREATE_FUNC(JumpScene);
private:
	JumpLayer *layer;
};

#endif
