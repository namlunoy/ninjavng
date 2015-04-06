﻿#include "PhiTieuLayer.h"


PhiTieuLayer::PhiTieuLayer() { }
PhiTieuLayer::~PhiTieuLayer(){ }


bool PhiTieuLayer::init()
{
	if (!Layer::init())
		return false;

	Shuriken* s = new Shuriken(Vec2(0, 0));
	this->addChild(s);

	//Hiển thị background
	_background = Sprite::create("cong_background.jpg");
	_background->setPosition(Config::centerPoint);
	theScale = Config::getScale(_background);
	_background->setScale(theScale);
	this->addChild(_background, -1);

	//Theem ninja
	 ninja = Ninja::create("Ninja2.png");
	ninja->setPosition(Config::centerPoint);
	this->addChild(ninja);
	ninja->runAnimation_DungYen();


	//Theem ninja
	ninja = Ninja::create("Ninja2.png");
	ninja->setPosition(Config::centerPoint + Vec2(100,100));
	this->addChild(ninja);
	ninja->runAnimation_Nhay();

	



	//Sự kiện key board
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(PhiTieuLayer::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	//Thêm button nhảy
	log("TEst thử");

	return true;
}

void PhiTieuLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	log("Key with keycode %d pressed", keyCode);
}



