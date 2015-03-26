#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "Scenes\Menu\Play_Scene.h"
#include <vector>

USING_NS_CC;
using namespace ui;
using namespace std;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	if (!Layer::init())
		return false;
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//Menu
	auto menu_item_1 = MenuItemFont::create("Play", CC_CALLBACK_1(HelloWorld::Play, this));
	auto menu_item_2 = MenuItemFont::create("HighScore", CC_CALLBACK_1(HelloWorld::HighScore, this));
	auto menu_item_3 = MenuItemFont::create("About", CC_CALLBACK_1(HelloWorld::About, this));
	auto menu_item_4 = MenuItemFont::create("Quit", CC_CALLBACK_1(HelloWorld::Quit, this));

	menu_item_1->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 4));
	menu_item_2->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 3));
	menu_item_3->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 2));
	menu_item_4->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 1));

	auto *menu = Menu::create(menu_item_1, menu_item_2, menu_item_3, menu_item_4, NULL);
	menu->setPosition(Point(0, 0));
	this->addChild(menu);

	return true;
}

void HelloWorld::Play(Ref* pSender)
{
	CCLOG("Play");
	auto scene = Play_Scene::create();
	Director::getInstance()->replaceScene(TransitionZoomFlipAngular::create(0.5, scene));
}

void HelloWorld::HighScore(Ref* pSender)
{

}

void HelloWorld::About(Ref* pSender)
{

}

void HelloWorld::Quit(Ref* pSender)
{

}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
