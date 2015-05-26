#include "JumpScene.h"
#include "cocos2d.h"
#include "Utility/Config.h"
USING_NS_CC;

JumpScene::JumpScene()
{
}

JumpScene::~JumpScene(){}

Scene* JumpScene::createPhysicScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setSpeed(3.5f);
	scene->getPhysicsWorld()->setGravity(Vect(0, -145.0f));
	scene->getPhysicsWorld()->setUpdateRate(0.5f);
	scene->getPhysicsWorld()->setSubsteps(10);
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//Screen
	/*Config::screenSize = Director::getInstance()->getVisibleSize();
	Size screenSize = Config::screenSize;
	Vec2 center(screenSize.width / 2, screenSize.height / 2);
	Config::centerPoint = center;*/

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

	/*auto listener = EventListenerKeyboard::create();
	listener->onKeyReleased = CC_CALLBACK_2(JumpScene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	cocos2d::Layer::setKeyboardEnabled(true);
	cocos2d::Layer::setKeypadEnabled(true);*/

	return true;
}