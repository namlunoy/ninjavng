#ifndef _HIGHSCORE_LAYER_
#define _HIGHSCORE_LAYER_

#include "cocos2d.h"

USING_NS_CC;

class HighScore_Layer:public Layer
{
public:
	HighScore_Layer();
	~HighScore_Layer();
	virtual bool init();
	CREATE_FUNC(HighScore_Layer);
};
#endif
