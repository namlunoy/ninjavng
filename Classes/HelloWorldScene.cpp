#include "HelloWorldScene.h"
#include "PhiTieu.h"
#include "ui/CocosGUI.h"
#include <vector>
#include "Jump.h"
#include "BanSung.h"

USING_NS_CC;
using namespace ui;
using namespace std;

Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();
	auto layer = HelloWorld::create();
	scene->addChild(layer);
	return scene;
}

bool HelloWorld::init()
{
	if (!Layer::init())
		return false;

	Size screenSize = Director::getInstance()->getVisibleSize();
	//Size phoneSize(800, 480);
	//float xScale = screenSize.width / phoneSize.width;
	//float yScale = screenSize.height / phoneSize.height;
	//float scale = max(xScale, yScale);

	Vec2 center(screenSize.width / 2, screenSize.height / 2);

	//Hiện thị background
	Sprite* bg = Sprite::create("bg2.jpg");
	bg->setPosition(screenSize.width / 2, screenSize.height / 2);
	bg->setScale(0.5);
	this->addChild(bg, -1);

	//Hiển thị các button
	//Tính toán vị trí
	for (int i = 1; i <= 5; i++)
	{
		char name[100];
		sprintf(name, "menu_icon_%d.png", i);
		Button* bt = Button::create(name, "menu_icon_selected.png", "menu_icon_selected.png");
		int khoangcach = 20 + bt->getContentSize().width;
		Vec2 pos = center + Vec2((i - 3)* khoangcach, 0);
		bt->setPosition(pos);
		this->addChild(bt);

		switch (i)
		{
		case 1:
			bt->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
				switch (type)
				{
				case ui::Widget::TouchEventType::ENDED:
				{
					auto scene = BanSung::createScene();
					Director::getInstance()->replaceScene(scene);
				}
				}
			});
			break;
		case 2:
			bt->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
				switch (type)
				{
				case ui::Widget::TouchEventType::ENDED:
				{


				}
				}
			});
			break;
		case 3:
			bt->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
				switch (type)
				{
				case ui::Widget::TouchEventType::ENDED:
				{
					auto scene = Jump::createScene();
					Director::getInstance()->replaceScene(scene);
				}
				}
			});
			break;
		case 4:
			bt->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
				switch (type)
				{
				case ui::Widget::TouchEventType::ENDED:
				{
					auto scene = PhiTieu::createScene();
					Director::getInstance()->replaceScene(scene);
				}
				}
			});
			break;
		case 5:
			bt->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
				switch (type)
				{
				case ui::Widget::TouchEventType::ENDED:
				{
					auto scene = PhiTieu::createScene();
					Director::getInstance()->replaceScene(scene);
				}
				}
			});
			break;
		}
	}


	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
