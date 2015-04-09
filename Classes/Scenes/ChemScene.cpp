/*
 * ChemScene.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#include "ChemScene.h"

ChemScene::ChemScene() {}
ChemScene::~ChemScene() {}

Scene* ChemScene::createScene()
{
	auto scene = Scene::create();
	auto layer = ChemLayer::create();
	scene->addChild(layer);
	return scene;
}

