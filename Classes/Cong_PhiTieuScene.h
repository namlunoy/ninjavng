#ifndef _PHITIEU_SCENE_
#define _PHITIEU_SCENE_

#include "cocos2d.h"
#include "Cong_PhiTieuLayer.h"

USING_NS_CC;

class Cong_PhiTieuScene : public Scene
{
private:
	Cong_PhiTieuLayer* phiTieuLayer;

public:
	Cong_PhiTieuScene();
	~Cong_PhiTieuScene();
	bool init();
	CREATE_FUNC(Cong_PhiTieuScene);
};

#endif
