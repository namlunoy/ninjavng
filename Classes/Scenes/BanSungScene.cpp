/*
 * BanSungScene.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#include "BanSungScene.h"

BanSungScene::BanSungScene() {}
BanSungScene::~BanSungScene() {}

Scene* BanSungScene::createScene()
{
	auto scene = Scene::create();
	auto layer = BanSungLayer::create();
	scene->addChild(layer);
	return scene;
}



