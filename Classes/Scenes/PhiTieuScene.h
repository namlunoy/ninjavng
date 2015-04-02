#ifndef _PHITIEU_SCENE_
#define _PHITIEU_SCENE_

#include "cocos2d.h"
#include "Layers/PhiTieuLayer.h"
#include "Layers/PhiTieuHUDLayer.h"

USING_NS_CC;

class PhiTieuScene : public Scene
{
private:
	PhiTieuLayer* phiTieuLayer;
	PhiTieuHUDLayer* hudLayer;
public:
	PhiTieuScene();
	~PhiTieuScene();
	bool init();
	CREATE_FUNC(PhiTieuScene);
};

#endif
