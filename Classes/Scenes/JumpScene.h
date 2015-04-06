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
	static Scene* createPhysicScene();
	bool initWithPhysics();
	CREATE_FUNC(JumpScene);
//private:
	/*JumpLayer *layer;
	Scene *scene;*/
};

#endif
