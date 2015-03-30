#include "D_Jump_Scene.h"
USING_NS_CC;

D_Jump_Scene::D_Jump_Scene()
{
}
D_Jump_Scene::~D_Jump_Scene()
{
}

bool D_Jump_Scene::init()
{
	if (!Scene::init()) return false;
		
	layer = D_Jump_Layer::create();
	this->addChild(layer);

	return true;
}