#include "Play_Scene.h"
#include "Layers/Menu/Play_Layer.h"


Play_Scene::Play_Scene() :layer(nullptr)
{
}


Play_Scene::~Play_Scene()
{
}

bool Play_Scene::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Play_Scene::init());

		layer = Play_Layer::create();
		addChild(layer);

		bRet = true;
	} while (0);

	return bRet;
}