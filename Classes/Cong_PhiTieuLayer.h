#ifndef _PHITIEU_LAYER_
#define _PHITIEU_LAYER_

#include "cocos2d.h"
#include "Config.h"
#include "Cong_Shuriken.h"

USING_NS_CC;

class Cong_PhiTieuLayer : public Layer
{
public:
	Cong_PhiTieuLayer();
	~Cong_PhiTieuLayer();
	bool init();
	CREATE_FUNC(Cong_PhiTieuLayer);
};
#endif

