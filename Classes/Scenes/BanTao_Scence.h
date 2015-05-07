#ifndef _BANTAO_SCENE_
#define _BANTAO_SCENE_

#include "cocos2d.h"
#include "Layers/BanSung/BanTao_Layer.h"


USING_NS_CC;

class BanTao_Scence : public Scene
{
private:
	BanTao_Layer* banTaoLayer;


public:
	BanTao_Scence();
	~BanTao_Scence();
	bool init();
	CREATE_FUNC(BanTao_Scence);
};

#endif
