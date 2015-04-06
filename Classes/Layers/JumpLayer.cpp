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
	/*auto wall = Node::create();
	wall->setPosition(screenSize.width / 2, screenSize.height / 2);
	auto bodyWall = PhysicsBody::createEdgeBox(screenSize, PhysicsMaterial(1.0f, 0.0f, 0.0f));
	bodyWall->setDynamic(false);
	bodyWall->setCollisionBitmask(WALL_COLLISION);
	bodyWall->setContactTestBitmask(true);
	wall->setPhysicsBody(bodyWall);
	this->addChild(wall);*/
	
	//Tạo cảnh ban đầu
	pillar->SpawnPillarFirst(this);

	//Gọi hàm sinh các Pillar
	this->schedule(schedule_selector(JumpLayer::SpawnPillar), 1);

	//Tạo 1 đối tượng Ninja
	ninja = new Ninja(this);
	
	//Xử lý contact
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(JumpLayer::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	//Xử lý Touch
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(JumpLayer::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(JumpLayer::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(JumpLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;
}

void JumpLayer::SpawnPillar(float spawn)
{
	pillar->SpawnPillar(this);
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

#pragma region Touch
bool JumpLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
	return true;
}

void JumpLayer::onTouchMoved(Touch *touch, Event *unused_event)
{

}

void JumpLayer::onTouchEnded(Touch *touch, Event *unused_event)
{
	CCLOG("Mot cai gi do");
	//ninja->jumpAction();
	
}
#pragma endregion 