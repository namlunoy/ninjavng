#ifndef _ABOUT_LAYER_
#define _ABOUT_LAYER_
#include "cocos2d.h"
USING_NS_CC;

class About_Layer : public Layer
{
public:
	About_Layer();
	~About_Layer();
	bool init();
	CREATE_FUNC(About_Layer);
};

#endif