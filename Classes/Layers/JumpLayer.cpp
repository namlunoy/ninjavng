#include "JumpLayer.h"
#include "cocos2d.h"
#include "Models/Ninja.h"
#include "Utility/Config.h"
#include "Utility/Definition.h"
#include "Models/Pillar.h"
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

	//Background
	auto background = Sprite::create("Background.jpg");
	background->setPosition(screenSize.width / 2, screenSize.height / 2);
	background->setScale(Config::getScale(background));
	this->addChild(background,-1);
	
	//Tạo tường xung quanh màn hình
	auto wall = Node::create();
	wall->setPosition(screenSize.width / 2, screenSize.height / 2);
	auto bodyWall = PhysicsBody::createBox(screenSize, PHYSICSBODY_MATERIAL_DEFAULT);
	bodyWall->setDynamic(false);
	bodyWall->setCollisionBitmask(WALL_COLLISION);
	bodyWall->setContactTestBitmask(true);
	wall->setPhysicsBody(bodyWall);
	this->addChild(wall);

	//Gọi hàm sinh các Pillar
	this->schedule(schedule_selector(JumpLayer::SpawnPillar), 1);

	//Tạo 1 đối tượng Ninja
	ninja = new Ninja(this);
	
	//Xử lý contact
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(JumpLayer::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	return true;
}

void JumpLayer::SpawnPillar(float spawn)
{
	pillar.SpawnPillar(this);
}

bool JumpLayer::onContactBegin(PhysicsContact &contact)
{
	PhysicsBody *a = contact.getShapeA()->getBody();
	PhysicsBody *b = contact.getShapeB()->getBody();

	if ((WALL_COLLISION == a->getCollisionBitmask() && NINJA_COLLISION == b->getCollisionBitmask()) ||
		(WALL_COLLISION == b->getCollisionBitmask() && NINJA_COLLISION == a->getCollisionBitmask()))
	{
		CCLOG("Death");
	}

	return true;
}