#ifndef _PHITIEU_LAYER_
#define _PHITIEU_LAYER_

#include "cocos2d.h"
#include "Config.h"
#include "Cong_Shuriken.h"
#include "Ninja.h"

USING_NS_CC;

class Cong_PhiTieuLayer : public Layer
{
public:
	Ninja* ninja;
	Cong_PhiTieuLayer();
	~Cong_PhiTieuLayer();
	bool init();
	CREATE_FUNC(Cong_PhiTieuLayer);
	bool touchScreen(Touch* t, Event* e);
};
#endif

