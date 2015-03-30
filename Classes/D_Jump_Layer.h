#ifndef _JumpLayer_
#define _JumpLayer_
#include "cocos2d.h"
USING_NS_CC;

class D_Jump_Layer:public Layer
{
public:
	~D_Jump_Layer();
	bool init();
	CREATE_FUNC(D_Jump_Layer);
};

#endif
