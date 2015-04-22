#include "JumpLayer.h"
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
}

bool JumpLayer::init()
{
	if (!Layer::init()) return false;

	//Tạo thằng Ninja
	ninja = Ninja_D::createNinja();
	ninja->setPosition(100, 220);
	this->addChild(ninja);

	pillar = Pillar::createPillar();
	pillar->setPosition(100,0);
	this->addChild(pillar);
	listPillar.push_back(pillar);

	for (int i = 1; i < 5; i++)
	{
		SpawnPillar(i * 150 + 100);
	}

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

void JumpLayer::setRandomPoint()
{

}

void JumpLayer::SpawnPillar(float distance)
{
	Pillar *p = Pillar::createPillar();
	auto height = CCRANDOM_0_1()*p->getContentSize().height / 2;
	p->setPosition(distance, height);
	this->addChild(p);
	listPillar.push_back(p);

}

void JumpLayer::MovePillar(float duration)
{
	for (std::list<Pillar*>::iterator it = listPillar.begin(); it != listPillar.end(); ++it)
	{
		(*it)->MovePillar(duration);
	}
}

void JumpLayer::StopPillar()
{
	for (std::list<Pillar*>::iterator it = listPillar.begin(); it != listPillar.end(); ++it)
	{
		(*it)->StopPillar();
	}
}

void JumpLayer::update(float delta)
{

}