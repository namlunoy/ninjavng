#include "JumpScene.h"
#include "cocos2d.h"
USING_NS_CC;

JumpScene::JumpScene()
{
}

JumpScene::~JumpScene(){}

Scene* JumpScene::createPhysicScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setSpeed(3.5f);
	scene->getPhysicsWorld()->setUpdateRate(0.5f);
	scene->getPhysicsWorld()->setSubsteps(10);
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//Random name
	int randomName = cocos2d::random(1, 3);

	//Background
	auto backgroundLayer = Background::createBackground(randomName);
	scene->addChild(backgroundLayer, 0);

	//Jump
	auto jumplayer = JumpLayer::createJumpLayer(randomName);
	jumplayer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(jumplayer, 1);

	//GamePlay
	auto gamePlayLayer = JumpPlayLayer::create();
	gamePlayLayer->SetJumpLayer(jumplayer);
	scene->addChild(gamePlayLayer, 2);

	return scene;
}

bool JumpScene::init()
{
	if (!JumpScene::init())
		return false;
		
	/*layer = JumpLayer::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);*/

	return true;
}
