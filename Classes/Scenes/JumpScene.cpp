#include "JumpScene.h"
USING_NS_CC;

JumpScene::JumpScene(){}

JumpScene::~JumpScene(){}

bool JumpScene::init()
{
	if (!Scene::init()) return false;
		
	layer = JumpLayer::create();
	this->addChild(layer);

	return true;
}
