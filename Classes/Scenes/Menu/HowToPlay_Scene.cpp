#include "HowToPlay_Scene.h"


HowToPlay_Scene::HowToPlay_Scene():layer(nullptr)
{

}


HowToPlay_Scene::~HowToPlay_Scene()
{
}

bool HowToPlay_Scene::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!HowToPlay_Scene::init());

		layer = HowToPlay_Layer::create();
		addChild(layer);

		bRet = true;
	} while (0);

	return bRet;
}