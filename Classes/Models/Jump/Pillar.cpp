#include "Pillar.h"
#include "Utility/Definition.h"
#include "Utility/Config.h"
#include "cocos2d.h"
#include "stdint.h"

Pillar::Pillar()
{
	/*screenSize = Director::getInstance()->getVisibleSize();
	rootPoint = Director::getInstance()->getVisibleOrigin();*/
}

void Pillar::SpawnPillar(Layer *layer, Point spawnPosition, int order)
{
	auto pillar = Sprite::create("pillar.png");
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
	auto bodyPillar = PhysicsBody::createBox(pillar->getContentSize(), PhysicsMaterial(1.0f, 0.0f, 0.0f));//Tạo body có size bằng size pillar
	bodyPillar->setDynamic(false);//Không chịu tác dụng vật lý
	bodyPillar->setCollisionBitmask(WALL_COLLISION);
	bodyPillar->setContactTestBitmask(true);
	pillar->setPhysicsBody(bodyPillar);
	layer->addChild(pillar);
}

void Pillar::MovePillar()
{
	auto movePillar = MoveBy::create(Config::screenSize.width*0.005, Vec2(- Config::screenSize.width - 200, 0));
	this->runAction(movePillar);
}

void Pillar::StopPillar()
{
	this->stopAllActions();
}