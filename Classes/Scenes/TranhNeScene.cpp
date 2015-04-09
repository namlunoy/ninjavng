/*
 * TranhNeScene.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#include "TranhNeScene.h"

TranhNeScene::TranhNeScene() {
}
TranhNeScene::~TranhNeScene() {
}

Scene* TranhNeScene::createScene() {
	auto scene = Scene::create();
	auto layer = TranhNeLayer::create();
	scene->addChild(layer);
	return scene;
}

