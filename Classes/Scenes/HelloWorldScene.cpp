#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include <vector>
#include "JumpScene.h"
#include "PhiTieuScene.h"
#include "ChemScene.h"
#include "TranhNeScene.h"
#include "BanTao_Scence.h"
#include "Utility/Config.h"

using namespace ui;
using namespace std;
USING_NS_CC;

Scene* HelloWorld::createScene() {
	auto scene = Scene::create();
	auto layer = HelloWorld::create();
	scene->addChild(layer);
	return scene;
}

bool HelloWorld::init() {
	if (!Layer::init())
		return false;
	Config::screenSize = Director::getInstance()->getVisibleSize();
	Size screenSize = Config::screenSize;
	Vec2 center(screenSize.width / 2, screenSize.height / 2);
	Config::centerPoint = center;

	//Hiện thị background
	Sprite* bg = Sprite::create("Tranh_Ne\\Nen\\0.jpg");// ("bg2.jpg");
	bg->setPosition(screenSize.width / 2, screenSize.height / 2);
	bg->setScale(Config::getScale(bg));
	this->addChild(bg, -1);

	//Hiển thị các button
	//Tính toán vị trí
	for (int i = 1; i <= 5; i++) {
		char name[100];
		sprintf(name, "Tranh_Ne\\Scene_Chinh\\Thanh_%d.png",i);//"menu_icon_%d.png", i);
		Button* bt = Button::create(name, "menu_icon_selected.png",
			"menu_icon_selected.png"); bt->setScale(0.3f);
		int khoangcach = 10 + (bt->getContentSize().height)/3;
		Vec2 pos = center + Vec2(i+25, (i - 3) * khoangcach);
		 bt->setPosition(pos);
		this->addChild(bt);

		switch (i) {
		case 1:
			bt->addTouchEventListener(
				[&](Ref* sender, Widget::TouchEventType type) {
				switch (type)
				{
				case ui::Widget::TouchEventType::ENDED:
				{
					auto scene = BanTao_Scence::create();
					Director::getInstance()->replaceScene(scene);
				}
				}
			});
			break;
		case 2:
			bt->addTouchEventListener(
				[&](Ref* sender, Widget::TouchEventType type) {
				switch (type)
				{
				case ui::Widget::TouchEventType::ENDED:
				{
					auto scene = ChemScene::createScene();
					Director::getInstance()->replaceScene(scene);
				}
				}
			});
			break;
		case 3:
			bt->addTouchEventListener(
				[&](Ref* sender, Widget::TouchEventType type) {
				switch (type)
				{
				case ui::Widget::TouchEventType::ENDED:
				{
					auto scene = JumpScene::createPhysicScene();
					Director::getInstance()->replaceScene(scene);
				}
				}
			});
			break;
		case 4:
			bt->addTouchEventListener(
				[&](Ref* sender, Widget::TouchEventType type) {
				switch (type)
				{
				case ui::Widget::TouchEventType::ENDED:
				{
					auto scene = PhiTieuScene::createScene();
					Director::getInstance()->replaceScene(scene);
				}
				}
			});
			break;
		case 5:
			bt->addTouchEventListener(
				[&](Ref* sender, Widget::TouchEventType type) {
				switch (type)
				{
				case ui::Widget::TouchEventType::ENDED:
				{
					auto scene = TranhNeScene::createScene();
					Director::getInstance()->replaceScene(scene);
				}
				}
			});
			break;
		}
	}

	return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
