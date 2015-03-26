#include "About_Scene.h"
#include "Layers/Menu/About_Layer.h"


About_Scene::About_Scene() :layer(nullptr)
{
}


About_Scene::~About_Scene()
{
}

bool About_Scene::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!About_Scene::init());
		layer = About_Layer::create();
		addChild(layer);

		bRet = true;
	} while (0);

	return bRet;
}