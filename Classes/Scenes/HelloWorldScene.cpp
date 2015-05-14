#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include <vector>
#include "JumpScene.h"
#include "PhiTieuScene.h"
#include "PhiTieuMenuScene.h"
#include "ChemScene.h"
#include "TranhNeScene.h"
#include "BanTao_Scence.h"
#include "Utility/Config.h"
#include "SimpleAudioEngine.h"
using namespace ui;
using namespace std;
USING_NS_CC;

Scene* HelloWorld::createScene() {
	auto scene = Scene::create();
	auto layer = HelloWorld::create();
	scene->addChild(layer);

	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();

	Config::screenSize = Director::getInstance()->getVisibleSize();
	Size screenSize = Config::screenSize;
	Vec2 center(screenSize.width / 2, screenSize.height / 2);
	Config::centerPoint = center;

	//Hiện thị background
	Sprite* bg = Sprite::create("bg2.jpg");
	bg->setPosition(screenSize.width / 2, screenSize.height / 2);
	bg->setScale(Config::getScale(bg));
	scene->addChild(bg, -1);

	//Hiển thị các button
	//Tính toán vị trí
	for (int i = 1; i <= 5; i++) {
		char name[100];
		sprintf(name, "menu_icon_%d.png", i);
		Button* bt = Button::create(name, "menu_icon_selected.png",
			"menu_icon_selected.png");
		int khoangcach = 20 + bt->getContentSize().width;
		Vec2 pos = center + Vec2((i - 3) * khoangcach, 0);
		bt->setPosition(pos);
		scene->addChild(bt);

		switch (i) {
		case 1:
			bt->addTouchEventListener(
				[&](Ref* sender, Widget::TouchEventType type) {
				switch (type)
				{
				case ui::Widget::TouchEventType::ENDED:
				{
					auto scene = BanTao_Scence::create();
					Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene, Color3B::WHITE));
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
					Director::getInstance()->replaceScene(TransitionFlipX::create(0.5, scene, TransitionScene::Orientation::LEFT_OVER));
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
					Director::getInstance()->replaceScene(TransitionCrossFade::create(0.5, scene));
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
					auto scene = PhiTieuScene::createScene(1);
					Director::getInstance()->replaceScene(TransitionRotoZoom::create(0.5, scene));
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

	return scene;
}

bool HelloWorld::init() {
	if (!Layer::init())
		return false;

	this->setKeypadEnabled(true);
	this->setKeyboardEnabled(true);

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

void HelloWorld::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
	{
		Director::getInstance()->end();
	}
}