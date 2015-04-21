#ifndef _PHITIEU_SCENE_
#define _PHITIEU_SCENE_

#include "cocos2d.h"
#include "Layers/PhiTieu/PhiTieuLayer.h"
#include "Layers/PhiTieu/PhiTieuHUDLayer.h"

USING_NS_CC;

class PhiTieuScene
{
private:

public:
	PhiTieuScene();
	~PhiTieuScene();
	static Scene* createScene();
};

#endif
