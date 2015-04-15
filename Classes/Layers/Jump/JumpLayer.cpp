﻿#include "JumpLayer.h"
#include "cocos2d.h"
#include "Models/Jump/Ninja_D.h"
#include "Utility/Config.h"
#include "Utility/Definition.h"
#include "Models/Jump/Pillar.h"
#include <iostream>
#include <list>
USING_NS_CC;

JumpLayer::~JumpLayer(){}
JumpLayer::JumpLayer()
{
	firstSpawnPoint = Point(100, 0);
	pillar = Pillar::createPillar();
	pillar->SpawnPillar(this, firstSpawnPoint);
	//prevSpawnPoint = firstSpawnPoint;
	//CCLOG("%f", pillar->getCurrenPos().x);
	//listPillar(1, pillar);
	////listPillar.push_back(pillar);
}

bool JumpLayer::init()
{
	if (!Layer::init()) return false;

	//Tạo 1 đối tượng Ninja
	ninja = new Ninja_D(this);

	//this->scheduleUpdate();
	//this->schedule(schedule_selector(JumpLayer::SpawnPillar), 1);
	/*prevSpawnPoint = Point(rootPoint.x + firstSpawnPoint.x, 0);
	do
	{
		auto distance = cocos2d::random(DISTANCE_SPAWN_MIN, DISTANCE_SPAWN_MAX);
		auto heightRandom = CCRANDOM_0_1()*pillar->getContentSize().height / 2;
		auto nextSpawnPoint = Point(prevSpawnPoint.x + distance, heightRandom);
		prevSpawnPoint.x = nextSpawnPoint.x;
		Pillar *p = Pillar::createPillar(nextSpawnPoint);
		p->SpawnPillar(this);
	} while (screenSize.width - prevSpawnPoint.x > DISTANCE_MAX);*/

	return true;
}

//void JumpLayer::SpawnPillar(Point pos)
//{
//	pillar->SpawnPillar(this, pos);
//}
//
//void JumpLayer::MovePillar()
//{
//	pillar->MovePillar();
//}

void JumpLayer::update(float delta)
{
	/*do
	{*/
	/*while (Config::screenSize.width - prevSpawnPoint.x > DISTANCE_SPAWN_MAX)
	{
		auto distance = cocos2d::random(DISTANCE_SPAWN_MIN, DISTANCE_SPAWN_MAX);
		auto heightRandom = CCRANDOM_0_1() * 175;
		CCLOG("%f", heightRandom);
		nextSpawnPoint = Point(prevSpawnPoint.x + distance, heightRandom);
		prevSpawnPoint = nextSpawnPoint;
		pillar = Pillar::createPillar();
		pillar->SpawnPillar(this, nextSpawnPoint);
	}*/
		
	/*} while (Config::screenSize.width - prevSpawnPoint.x > DISTANCE_SPAWN_MAX);*/
}
