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
	firstPillar = listPillar.begin();
}

bool JumpLayer::init()
{
	if (!Layer::init()) return false;

	//Tạo thằng Ninja
	ninja = Ninja_D::createNinja();
	ninja->setPosition(100, 220);
	this->addChild(ninja);

	pillar = Pillar::createPillar();
	pillar->setPosition(100, 0);
	this->addChild(pillar);
	listPillar.push_front(pillar);

	firstPillar = listPillar.begin();
	
	log("%f", (*firstPillar)->getPositionX());

	return true;
}

void JumpLayer::UpdatePillar()
{
	if ((800 - (*firstPillar)->getPositionX()) > DISTANCE_SPAWN_MAX)
	{
		float randomX = cocos2d::random(DISTANCE_SPAWN_MIN, DISTANCE_SPAWN_MAX);
		SpawnPillarWithPos(Point((*firstPillar)->getPositionX() + randomX, CCRANDOM_0_1() * 175));
	}
	firstPillar = listPillar.begin();
}

void JumpLayer::SpawnPillar(/*Point pos*/)
{
	Point pos = Point(Config::screenSize.width, CCRANDOM_0_1() * 175);
	Pillar *p = Pillar::createPillar();	
	p->setPosition(pos);
	this->addChild(p);
	listPillar.push_front(p);
}

void JumpLayer::SpawnPillarWithPos(Point pos)
{
	Pillar *p = Pillar::createPillar();
	p->setPosition(pos);
	this->addChild(p);
	listPillar.push_front(p);
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