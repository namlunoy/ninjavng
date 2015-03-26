#ifndef _PLAY_SCENE_
#define _PLAY_SCENE_
#include "cocos2d.h"
#include "Layers\Menu\Play_Layer.h"
USING_NS_CC;

class Play_Scene : public Scene
{
public:
	Play_Scene();
	~Play_Scene();
	bool init();
	CREATE_FUNC(Play_Scene);

private:
	Play_Layer* layer;
};
#endif
