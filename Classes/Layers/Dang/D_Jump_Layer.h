#ifndef _JUMP_LAYER_
#define  _JUMP_LAYER_
#include "cocos2d.h"
USING_NS_CC;

class D_Jump_Layer:public Layer
{
public:
	D_Jump_Layer();
	~D_Jump_Layer();
	bool init();
	CREATE_FUNC(D_Jump_Layer);
};
#endif
