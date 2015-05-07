#include "PhiTieuScene.h"

PhiTieuScene::PhiTieuScene(){}
PhiTieuScene::~PhiTieuScene(){}
int PhiTieuScene::level = 0;
Scene* PhiTieuScene::createScene(int lv)
{
	PhiTieuScene::level = lv;
	Scene* _scene = Scene::createWithPhysics();
	_scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	_scene->getPhysicsWorld()->setGravity(Vec2(0, -98.0f));

	PhiTieuLayer* phiTieuLayer = PhiTieuLayer::create();
	_scene->addChild(phiTieuLayer, 0);
	phiTieuLayer->setPhysicWorld(_scene->getPhysicsWorld());

	PhiTieuHUDLayer* hudLayer = PhiTieuHUDLayer::create();
	_scene->addChild(hudLayer, 1);

	phiTieuLayer->setHUDLayer(hudLayer);
	hudLayer->setPhiTieuLayer(phiTieuLayer);

	return _scene;
}


