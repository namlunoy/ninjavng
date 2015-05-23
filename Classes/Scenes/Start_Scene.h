#ifndef _Start_Scene_
#define _Start_Scene_
#include "cocos2d.h"
#include "Layers/Jump/Start_Layer.h"
#include "Utility/Config.h"
#include "Models/Jump/Background.h"
USING_NS_CC;

class Start_Scene : public Scene
{
public:
	Start_Scene();
	~Start_Scene();
	static Scene * createStartScene();
	bool init();
	CREATE_FUNC(Start_Scene);
};

#endif