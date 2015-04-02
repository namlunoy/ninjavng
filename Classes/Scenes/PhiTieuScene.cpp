#include "PhiTieuScene.h"

PhiTieuScene::PhiTieuScene(){}
PhiTieuScene::~PhiTieuScene(){}

bool PhiTieuScene::init()
{
	if (!Scene::init())
		return false;

	phiTieuLayer = PhiTieuLayer::create();
	this->addChild(phiTieuLayer, 0);

	hudLayer = PhiTieuHUDLayer::create();
	this->addChild(hudLayer, 1);

	return true;
}
