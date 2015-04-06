#include "Pillar.h"
#include "Utility/Definition.h"
#include "Utility/Config.h"
#include "cocos2d.h"
#include "stdint.h"

Pillar::Pillar()
{
	screenSize = Director::getInstance()->getVisibleSize();
	rootPoint = Director::getInstance()->getVisibleOrigin();
}

void Pillar::SpawnPillar(Layer *layer)
{
	auto pillar = Sprite::create("pillar.png");
	auto randomHeight = CCRANDOM_0_1()*pillar->getContentSize().height / 2;
	pillar->setPosition(Point(screenSize.width + pillar->getContentSize().width, randomHeight ));
	auto bodyPillar = PhysicsBody::createBox(pillar->getContentSize());//Tạo body có size bằng size pillar
	bodyPillar->setDynamic(false);//Không chịu tác dụng vật lý
	bodyPillar->setCollisionBitmask(WALL_COLLISION);
	bodyPillar->setContactTestBitmask(true);
	pillar->setPhysicsBody(bodyPillar);
	layer->addChild(pillar);

	//Move
	auto movePillar = MoveTo::create(screenSize.width*0.005, Vec2(rootPoint.x - pillar->getContentSize().width, randomHeight));
	pillar->runAction(movePillar);

}

void Pillar::MovePillar(Sprite *pillar)
{
	auto movePillar = MoveTo::create(screenSize.width*0.01*CCRANDOM_0_1(), Vec2(rootPoint.x - pillar->getContentSize().width, 0));
	pillar->runAction(movePillar);
}