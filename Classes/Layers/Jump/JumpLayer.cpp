#include "JumpLayer.h"
#include "cocos2d.h"
#include "Models/Jump/Ninja_D.h"
#include "Utility/Config.h"
#include "Utility/Definition.h"
#include "Models/Jump/Pillar.h"
USING_NS_CC;

JumpLayer::~JumpLayer()
{
}

bool JumpLayer::init()
{
	if (!Layer::init()) return false;
	//Screen
	Size screenSize = Director::getInstance()->getVisibleSize();
	Point rootPoint = Director::getInstance()->getVisibleOrigin();

	//Tạo 1 đối tượng Ninja
	ninja = new Ninja_D(this);

	//Tạo cảnh ban đầu
	auto firtsSpawnPoint = Point(100, 0);
	pillar->SpawnPillar(this, firtsSpawnPoint, 1);
	auto prevSpawnPoint = Point(rootPoint.x + 100, 0);
	do 
	{
		auto distance = cocos2d::random(DISTANCE_SPAWN_MIN, DISTANCE_SPAWN_MAX);
		auto nextSpawnPoint = Point(prevSpawnPoint.x+ distance, 0);
		prevSpawnPoint.x = nextSpawnPoint.x;
		pillar->SpawnPillar(this, nextSpawnPoint, 2);
	} while (screenSize.width - prevSpawnPoint.x > DISTANCE_MAX);

	return true;
}

void JumpLayer::SpawnPillar(float spawn)
{
	/*auto randomHeight = CCRANDOM_0_1()*pillar->getContentSize().height / 2;
	pillar->SpawnPillar(this, Point(Config::screenSize.width + pillar->getContentSize().width, randomHeight), 0);*/
}