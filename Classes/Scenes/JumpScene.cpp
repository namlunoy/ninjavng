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
	auto jumplayer = JumpLayer::create();
	jumplayer->setContentSize(Size(480, 800));
	jumplayer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(jumplayer,0);

	auto gamePlayLayer = GamePlayLayer::create();
	scene->addChild(gamePlayLayer,1);

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
