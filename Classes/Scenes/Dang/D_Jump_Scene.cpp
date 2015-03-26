#include "D_Jump_Scene.h"


D_Jump_Scene::D_Jump_Scene() :layer(nullptr)
{
}


D_Jump_Scene::~D_Jump_Scene()
{
}

bool D_Jump_Scene::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Scene::init());

		layer = D_Jump_Layer::create();
		addChild(layer);

		bRet = true;
	} while (0);

	return bRet;
}