/*
 * PhiTieu.cpp
 *
 *  Created on: Mar 23, 2015
 *      Author: Dang
 */

#include "TungAnh.h"
#include "ui/CocosGUI.h"

using namespace ui;

//Tao Scene va add layer hien tai vao scene
Scene* TungAnh::createScene()
{
	CCLOG("Tao scene!");
	Scene* _scene = Scene::create();
	auto layer = TungAnh::create();
	_scene->addChild(layer);
	return _scene;
}

//Ham khoi tao cac thu tren layer
bool TungAnh::init()
{
	CCLOG("init()");
	if (!Layer::init())
		return false;

	Size screenSize = Director::getInstance()->getVisibleSize();
	auto title = Label::createWithTTF("TungAnh", "fonts/arial.ttf", 100);
	title->setAnchorPoint(Vec2(0.5, 1));
	title->setPosition(Vec2(screenSize.width / 2, screenSize.height / 2));
	this->addChild(title);

	return true;
}
