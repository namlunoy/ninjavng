#ifndef _JUMP_SCENE_
#define _JUMP_SCENE_
#include "cocos2d.h"
#include "D_Jump_Layer.h"

class D_Jump_Scene: public Scene
{
public:
	D_Jump_Scene();
	~D_Jump_Scene();
	virtual bool init();
	CREATE_FUNC(D_Jump_Scene);
private:
	D_Jump_Layer *layer;
};

#endif
