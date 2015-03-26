#ifndef _HOWTOPLAY_LAYER_
#define _HOWTOPLAY_LAYER_

#include "cocos2d.h"

USING_NS_CC;
class HowToPlay_Layer :public Layer
{
public:
	HowToPlay_Layer();
	~HowToPlay_Layer();
	virtual bool init();
	CREATE_FUNC(HowToPlay_Layer);
};
#endif
