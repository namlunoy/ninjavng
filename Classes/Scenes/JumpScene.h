#ifndef _JumpScene_
#define _JumpScene_
#include "cocos2d.h"
#include "Layers/Jump/JumpLayer.h"
#include "Layers/Jump/GamePlayLayer.h"
#include "Models/Jump/Background.h"
USING_NS_CC;

class JumpScene:public cocos2d::Scene
{
public:
	JumpScene();
	~JumpScene();
	static Scene* createPhysicScene();
	bool init();
	CREATE_FUNC(JumpScene);
//private:
	/*JumpLayer *layer;
	Scene *scene;*/
};

#endif
