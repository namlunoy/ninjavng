#include "D_Jump_Layer.h"


D_Jump_Layer::D_Jump_Layer()
{
}


D_Jump_Layer::~D_Jump_Layer()
{
}

bool Layer1::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!D_Jump_Scene::init());

		//lam gi thi lam

		bRet = true;
	} while (0);

	return bRet;
}