/*
 * PhiTieuMenuScene.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: conghoang
 */

#include "PhiTieuMenuScene.h"
#include "PhiTieuScene.h"
#include "ui/CocosGUI.h"
#include "Utility/Config.h"
#include "HelloWorldScene.h"
#include <sstream>

using namespace ui;

PhiTieuMenuScene::PhiTieuMenuScene() {
}

PhiTieuMenuScene::~PhiTieuMenuScene() {
}
int PhiTieuMenuScene::SelectedLevel = 1;

Scene* PhiTieuMenuScene::createScene() {
	Scene* scene = Scene::create();

	//Hiển thị các button
	//Tính toán vị trí
	for (int i = 1; i <= 5; i++) {
		char name[100];
		sprintf(name, "menu_icon_%d.png", i);
		Button* bt = Button::create("cbt.png", "cbt.png","cbt.png");
		int khoangcach = 20 + bt->getContentSize().width;
		Vec2 pos = Config::centerPoint + Vec2((i - 3) * khoangcach, 0);
		bt->setPosition(pos);
		scene->addChild(bt);

		std::stringstream ss;
		ss<<i;
		Label* label = Label::createWithTTF(ss.str(),"fonts/njnaruto.ttf",20);
		bt->addChild(label);
		switch (i) {
		case 1:
			bt->addTouchEventListener(
					[&](Ref* sender, Widget::TouchEventType type) {
						switch (type)
						{
							case ui::Widget::TouchEventType::ENDED:
							{
								auto scene = PhiTieuScene::createScene(1);
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
					auto scene = PhiTieuScene::createScene(2);
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
					auto scene = PhiTieuScene::createScene(3);
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
					auto scene = PhiTieuScene::createScene(4);
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
					auto scene = PhiTieuScene::createScene(5);
					Director::getInstance()->replaceScene(scene);
				}
				}
			});
			break;
		}
	}

	//Back Button
	auto backButton = Button::create("back_button-1.png", "back_button-1.png",
			"back_button-1.png");
	backButton->setAnchorPoint(Vec2(0, 0));
	backButton->setScale(0.3f, 0.5f);
	backButton->setPosition(
			Point(0,
					Config::screenSize.height
							- backButton->getContentSize().height / 2));
	backButton->addTouchEventListener(
			[&](Ref* sender, Widget::TouchEventType type) {
				switch (type)
				{
					case ui::Widget::TouchEventType::BEGAN:
					break;
					case ui::Widget::TouchEventType::ENDED:
					//auto helloScene = HelloWorld::createScene();
					Director::getInstance()->replaceScene(HelloWorld::createScene());
					break;
					default:
					break;
				}
			});
	scene->addChild(backButton);

	return scene;
}
