#include "PhiTieuScene.h"

PhiTieuScene::PhiTieuScene(){}
PhiTieuScene::~PhiTieuScene(){}

Scene* PhiTieuScene::createScene()
{
	Scene* _scene = Scene::createWithPhysics();

	auto phiTieuLayer = PhiTieuLayer::create();
	_scene->addChild(phiTieuLayer, 0);

	auto hudLayer = PhiTieuHUDLayer::create();
	_scene->addChild(hudLayer, 1);

	
	return _scene;
}


