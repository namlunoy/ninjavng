#ifndef _ABOUT_SCENE_
#define _ABOUT_SCENE_
#include "cocos2d.h"
#include "Layers\Menu\About_Layer.h"
USING_NS_CC;

class About_Scene : public Scene
{
public:
	About_Scene();
	~About_Scene();

	bool init();
	CREATE_FUNC(About_Scene);

private:
	About_Layer* layer;
};
#endif
