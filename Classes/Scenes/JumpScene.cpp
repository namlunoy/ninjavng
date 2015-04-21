#include "JumpScene.h"
USING_NS_CC;

JumpScene::JumpScene()
{
}

JumpScene::~JumpScene(){}

Scene* JumpScene::createPhysicScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setSpeed(2.5f);
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//Background
	auto backgroundLayer = Background::create();
	scene->addChild(backgroundLayer, 0);

	//Jump
	auto jumplayer = JumpLayer::create();
	jumplayer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(jumplayer,1);

	//GamePlay
	auto gamePlayLayer = JumpPlayLayer::create();
	gamePlayLayer->SetJumpLayer(jumplayer);
	scene->addChild(gamePlayLayer,2);

	return scene;
}

bool JumpScene::init()
{
	if (!JumpScene::init()) return false;
		
	/*layer = JumpLayer::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);*/

	return true;
}
