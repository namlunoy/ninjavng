/*
 * TranhNeScene.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#include "TranhNeScene.h"

TranhNeScene::TranhNeScene() {}
TranhNeScene::~TranhNeScene() {}

Scene* TranhNeScene::createScene() 
{
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vect(0.0f, 0.0f));
	auto layer = TranhNeLayer::create();
	scene->addChild(layer);
	return scene;
}

