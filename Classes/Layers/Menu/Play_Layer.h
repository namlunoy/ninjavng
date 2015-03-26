#ifndef _PLAY_LAYER_
#define _PLAY_LAYER_

#include "cocos2d.h"
USING_NS_CC;

class Play_Layer: public Layer
{
public:
	Play_Layer();
	~Play_Layer();
	virtual bool init();
	CREATE_FUNC(Play_Layer);
};
#endif
