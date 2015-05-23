#include "Start_Scene.h"



Start_Scene::Start_Scene()
{
}

Start_Scene::~Start_Scene()
{
}

Scene * Start_Scene::createStartScene()
{
	auto scene = Scene::create();

	//Screen
	Config::screenSize = Director::getInstance()->getVisibleSize();
	Size screenSize = Config::screenSize;
	Vec2 center(screenSize.width / 2, screenSize.height / 2);
	Config::centerPoint = center;

	//Random name
	//int randomName = cocos2d::random(1, 3);

	////Background
	//auto backgroundLayer = Background::createBackground(randomName);
	//scene->addChild(backgroundLayer, 0);

	//Start Layer
	auto start_layer = Start_Layer::createStartLayer();
	scene->addChild(start_layer, 1);

	return scene;
}

bool Start_Scene::init()
{
	

	return true;
}