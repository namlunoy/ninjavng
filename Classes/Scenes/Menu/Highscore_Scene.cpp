#include "Highscore_Scene.h"


Highscore_Scene::Highscore_Scene() :layer(nullptr)
{
}


Highscore_Scene::~Highscore_Scene()
{
}

bool Highscore_Scene::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Highscore_Scene::init());

		layer = HighScore_Layer::create();
		addChild(layer);

		bRet = true;
	} while (0);

	return bRet;
}