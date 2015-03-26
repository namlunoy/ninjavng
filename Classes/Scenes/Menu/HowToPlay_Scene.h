#ifndef _HOWTOPLAY_SCENE_
#define _HOWTOPLAY_SCENE_
#include "cocos2d.h"
#include "Layers\Menu\HowToPlay_Layer.h"
USING_NS_CC;

class HowToPlay_Scene :public Scene
{
public:
	HowToPlay_Scene();
	~HowToPlay_Scene();
	bool init();
	CREATE_FUNC(HowToPlay_Scene);

private:
	HowToPlay_Layer* layer;
};

#endif