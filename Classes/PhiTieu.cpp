/*
 * PhiTieu.cpp
 *
 *  Created on: Mar 23, 2015
 *      Author: Dang
 */

#include "PhiTieu.h"
#include "Cong_Shuriken.h"
#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include <cmath>
#include <sstream>

using namespace ui;
using namespace std;

//Tao Scene va add layer hien tai vao scene
Scene* PhiTieu::createScene()
{
	CCLOG("Tao scene!");
	Scene* _scene = Scene::create();
	auto layer = PhiTieu::create();
	_scene->addChild(layer);
	return _scene;
}

//Ham khoi tao cac thu tren layer
bool PhiTieu::init()
{
	CCLOG("init()");
	if (!Layer::init())
		return false;

	//Tên cảnh
	screenSize = Director::getInstance()->getVisibleSize();
	auto title = Label::createWithTTF("Phi tieu", "fonts/arial.ttf", 100);
	title->setAnchorPoint(Vec2(0.5, 1));
	title->setPosition(Vec2(screenSize.width / 2, screenSize.height));
	this->addChild(title);

	//Text để check
	_log = Label::createWithTTF("check", "fonts/arial.ttf", 20);
	_log->setAnchorPoint(Vec2(0, 1));
	_log->setPosition(Vec2(0, screenSize.height));
	this->addChild(_log);

	//touch event
	auto _touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(PhiTieu::touch, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);

	//Shuriken
	shuriken = Sprite::create("Shuriken.png");
	shuriken->setPosition(Vec2(screenSize.width / 2, screenSize.height / 2));
	shuriken->setScale(0.3f);

	shuriken->runAction(RepeatForever::create(RotateBy::create(0.2, 100)));

	this->addChild(shuriken);
	stringstream ss;
	ss << screenSize.height << "x" << screenSize.width;
	_log->setString(ss.str());



	//Back button
	//auto backButton = Label::createWithTTF("Back", "fonts/arial.ttf", 30);
	auto backButton = Button::create("back.png", "backSelected.png");
	backButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
		{
			CCLOG("Chay vao roi!");
			auto scene = HelloWorld::createScene();
			Director::getInstance()->replaceScene(scene);
		}
		break;
		default:
			break;
		}
	});
	backButton->setPosition(Vec2(100, 100));
	this->addChild(backButton);

	return true;
}


bool PhiTieu::touch(Touch* t, Event* e)
{
	//CCLOG("Cham vao man hinh!");
	//char s[100];
	//sprintf(s, "(%d\n%d)", t->getLocationInView().x, t->getLocationInView().y);
	//_log->setString(s);

	Vec2 newPos(t->getLocationInView().x, screenSize.height - (t->getLocationInView().y));
	//Vec2 oldPos(t->getPreviousLocationInView().x, screenSize.height - (t->getPreviousLocationInView().y));

	////shuriken->setPosition(t->getLocation());
	//float v = 0.1;
	//Vec2 xxx = t->getPreviousLocationInView();
	//Vec2 yyy = t->getLocationInView();
	//float d = sqrt(xxx.x*xxx.x + xxx.y*xxx.y);
	//float time = d * 1000000 / v;
	//stringstream ss;
	//ss << "\nx:" << oldPos.x << "  y:" << oldPos.y;
	//ss << "\nx:" << newPos.x << "  y:" << newPos.y;
	//ss << "\nd:" << d << " v:" << v << " t:" << time;
	//_log->setString(_log->getString() + ss.str());

	//auto action = MoveTo::create(time, newPos);
	//shuriken->runAction(action);


	//Cong_Shuriken* o = new Cong_Shuriken(newPos);
	this->addChild(Cong_Shuriken::createSuriken(newPos));
	return true;
}