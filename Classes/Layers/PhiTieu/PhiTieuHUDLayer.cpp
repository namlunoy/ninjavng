﻿#include "PhiTieuHUDLayer.h"

PhiTieuHUDLayer::PhiTieuHUDLayer() {
}
PhiTieuHUDLayer::~PhiTieuHUDLayer() {
}

void PhiTieuHUDLayer::setPhiTieuLayer(PhiTieuLayer* p)
{
	_phiTieuLayer = p;
}

bool PhiTieuHUDLayer::init() {
	if (!Layer::init())
		return false;

	//Back Button
	auto backButton = Button::create("back_button-1.png", "back_button-1.png","back_button - 1.png");
	backButton->setAnchorPoint(Vec2(0, 0));
	backButton->setScale(0.3f, 0.5f);
	backButton->setPosition(Point(0,Config::screenSize.height - backButton->getContentSize().height / 2));
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
	this->addChild(backButton);

	//------------------ Button jump  ---------------------
	bt_jump = Button::create("bt_jump_1.png", "bt_jump_2.png", "bt_jump_2.png");
	bt_jump->setAnchorPoint(Vec2(0, 0));
	bt_jump->setPosition(Vec2(0, 0));
	bt_jump->setScale(0.5f);
	bt_jump->addTouchEventListener(this,toucheventselector(PhiTieuHUDLayer::click_Jump));
	this->addChild(bt_jump);

	//-----------------  Touch event ------------
	auto _touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(PhiTieuHUDLayer::touch_PhongTieu, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener,this);


	//-------------- Trai tim ---------
	hearts.pushBack(Sprite::create("heart.png"));
	hearts.pushBack(Sprite::create("heart.png"));
	hearts.pushBack(Sprite::create("heart.png"));

	for(int i=0; i<3; i++)
	{
		hearts.at(i)->setScale(0.25f);
		hearts.at(i)->setPosition(Vec2(50 + 50*i , Config::screenSize.height - 50));
		this->addChild(hearts.at(i));
	}

	return true;
}

void PhiTieuHUDLayer::matMau()
{
	if(hearts.size() > 0)
	{
		hearts.at(hearts.size() - 1)->removeFromParent();
		hearts.popBack();
	}

	if(hearts.size() == 0)
	{
		//Xu ly thua
	}
}

bool PhiTieuHUDLayer::touch_PhongTieu(Touch* t, Event* e) {
	_phiTieuLayer->PhongTieu(t->getLocation());
	return true;
}

void PhiTieuHUDLayer::click_Jump(Ref* sender, TouchEventType touchType) {
	//Thực hiện nhảy
	if (touchType == TouchEventType::TOUCH_EVENT_BEGAN) {
		_phiTieuLayer->Jump();
	}
}
