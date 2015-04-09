#include "Pillar.h"
#include "Utility/Definition.h"
#include "Utility/Config.h"
#include "cocos2d.h"
#include "stdint.h"
#include "chipmunk.h"

Pillar::Pillar()
{
	/*screenSize = Director::getInstance()->getVisibleSize();
	rootPoint = Director::getInstance()->getVisibleOrigin();*/
}

void Pillar::SpawnPillar(Layer *layer, Point spawnPosition, int order)
{
	auto pillar = Sprite::create("building.png");
	if (order == 1)
	{
		pillar->setPosition(Point(spawnPosition));
	}
	else if (order == 2)
	{
		auto randomHeight = CCRANDOM_0_1()*pillar->getContentSize().height / 2;
		spawnPosition.y = randomHeight;
		pillar->setPosition(Point(spawnPosition));
	}
	auto bodyPillar = PhysicsBody::createEdgeBox(pillar->getContentSize(), PhysicsMaterial(1.0f, 0.0f, 1.0f));
	bodyPillar->setDynamic(false);
	pillar->setPhysicsBody(bodyPillar);
	layer->addChild(pillar);
}

void Pillar::MovePillar()
{
	auto movePillar = MoveBy::create(Config::screenSize.width*0.005, Vec2(- Config::screenSize.width - 200, 0));
}

void Pillar::StopPillar()
{
	this->stopAllActions();
}