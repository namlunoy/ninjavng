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
	auto scene = Scene::createWithPhysics();
	// Lệnh debug này cho phép nhìn thấy các khung body vật lý áp dụng vào các đối tượng ( đường viền đỏ bao quanh đối tượng)
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	//Thiết lập gia tốc trọng lực bằng 0, để các đối tượng của chúng ta ko rơi xuống đáy màn hình
	scene->getPhysicsWorld()->setGravity(Vect(0.0f,0.0f));
	auto layer = ChemLayer::create();
	scene->addChild(layer);
	return scene;
}

