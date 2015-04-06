#include "JumpScene.h"
USING_NS_CC;

JumpScene::JumpScene()
{
}

JumpScene::~JumpScene(){}

Scene* JumpScene::createPhysicScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	//scene->getPhysicsWorld()->setGravity(Vec2(0, -9.8f));
	auto layer = JumpLayer::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);
	return scene;
}

bool JumpScene::initWithPhysics()
{
	if (!JumpScene::initWithPhysics()) return false;
		
	/*layer = JumpLayer::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);*/

	return true;
}
