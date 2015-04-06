#ifndef _PHITIEU_SCENE_
#define _PHITIEU_SCENE_

#include "cocos2d.h"
#include "Layers/PhiTieuLayer.h"
#include "Layers/PhiTieuHUDLayer.h"

USING_NS_CC;

class PhiTieuScene :public Scene
{
private:
	PhiTieuLayer* phiTieuLayer;
	PhiTieuHUDLayer* hudLayer;
	PhysicsWorld* _physicWorld;

public:
	PhiTieuScene();
	~PhiTieuScene();
	bool initWithPhysics();
	CREATE_FUNC(PhiTieuScene);
};

#endif
