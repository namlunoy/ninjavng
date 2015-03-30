#include "Cong_PhiTieuScene.h"

Cong_PhiTieuScene::Cong_PhiTieuScene(){}
Cong_PhiTieuScene::~Cong_PhiTieuScene(){}

bool Cong_PhiTieuScene::init()
{
	if (!Scene::init())
		return false;

	phiTieuLayer = Cong_PhiTieuLayer::create();
	this->addChild(phiTieuLayer);

	return true;
}