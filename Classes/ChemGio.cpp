/*
 * PhiTieu.cpp
 *
 *  Created on: Mar 23, 2015
 *      Author: Dang
 */

#include "ChemGio.h"
#include "ui/CocosGUI.h"

using namespace ui;

//Tao Scene va add layer hien tai vao scene
Scene* ChemGio::createScene()
{
	CCLOG("Tao scene!");
	Scene* _scene = Scene::create();
	auto layer = ChemGio::create();
	_scene->addChild(layer);
	return _scene;
}

//Ham khoi tao cac thu tren layer
bool ChemGio::init()
{
	CCLOG("init()");
	if (!Layer::init())
		return false;

	Size screenSize = Director::getInstance()->getVisibleSize();
	auto title = Label::createWithTTF("ChemGio", "fonts/arial.ttf", 100);
	title->setAnchorPoint(Vec2(0.5, 1));
	title->setPosition(Vec2(screenSize.width / 2, screenSize.height / 2));
	this->addChild(title);

	return true;
}
