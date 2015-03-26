#ifndef _HIGHSCORE_SCENE_
#define _HIGHSCORE_SCENE_
#include "cocos2d.h"
#include "Layers\Menu\HighScore_Layer.h"
USING_NS_CC;
class Highscore_Scene : public Scene
{
public:
	Highscore_Scene();
	~Highscore_Scene();
	bool init();
	CREATE_FUNC(Highscore_Scene);

private:
	HighScore_Layer* layer;
};

#endif