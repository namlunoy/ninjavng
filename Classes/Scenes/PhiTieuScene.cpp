#include "PhiTieuScene.h"

PhiTieuScene::PhiTieuScene(){}
PhiTieuScene::~PhiTieuScene(){}

Scene* PhiTieuScene::createScene()
{
	Scene* _scene = Scene::createWithPhysics();
	_scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	_scene->getPhysicsWorld()->setGravity(Vec2(0, -98.0f));

	PhiTieuLayer* phiTieuLayer = PhiTieuLayer::create();
	_scene->addChild(phiTieuLayer, 0);
	phiTieuLayer->setPhysicWorld(_scene->getPhysicsWorld());

	PhiTieuHUDLayer* hudLayer = PhiTieuHUDLayer::create();
	_scene->addChild(hudLayer, 1);

	PhiTieuController::getInstance()->setupLayers(hudLayer,phiTieuLayer);
	return _scene;
}


