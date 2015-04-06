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

void Pillar::SpawnPillar(Layer *layer)
{
	auto pillar = Sprite::create("pillar.png");
	auto randomHeight = CCRANDOM_0_1()*pillar->getContentSize().height / 2;
	pillar->setPosition(Point(Config::screenSize.width + pillar->getContentSize().width, randomHeight));
	auto bodyPillar = PhysicsBody::createBox(pillar->getContentSize(), PhysicsMaterial(1.0f, 0.0f, 0.0f));//Tạo body có size bằng size pillar
	bodyPillar->setDynamic(false);//Không chịu tác dụng vật lý
	bodyPillar->setCollisionBitmask(WALL_COLLISION);
	bodyPillar->setContactTestBitmask(true);
	pillar->setPhysicsBody(bodyPillar);
	layer->addChild(pillar);
	//Move
	//MovePillar(pillar);
	//auto movePillar = MoveTo::create(screenSize.width*0.005, Vec2(rootPoint.x - pillar->getContentSize().width, randomHeight));
	/*auto movePillar = MoveBy::create(screenSize.width*0.005, Vec2(-screenSize.width-200, 0));
	pillar->runAction(movePillar);*/

}

void Pillar::SpawnPillarFirst(Layer *layer)
{
	auto pillar_1 = Sprite::create("pillar.png");
	pillar_1->setPosition(100, 0);
	auto bodyPillar_1 = PhysicsBody::createBox(pillar_1->getContentSize(), PhysicsMaterial(1.0f, 0.0f, 0.0f));//Tạo body có size bằng size pillar
	bodyPillar_1->setDynamic(false);//Không chịu tác dụng vật lý
	//bodyPillar_1->setCollisionBitmask(WALL_COLLISION);
	//bodyPillar_1->setContactTestBitmask(true);
	pillar_1->setPhysicsBody(bodyPillar_1);
	layer->addChild(pillar_1);
}

void Pillar::MovePillar(Sprite *pillar)
{
	auto movePillar = MoveBy::create(Config::screenSize.width*0.005, Vec2(-Config::screenSize.width - 200, 0));
	pillar->runAction(movePillar);
}

void Pillar::StopPillar()
{
	this->stopAllActions();
}