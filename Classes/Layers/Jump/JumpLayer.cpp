#include "JumpLayer.h"
#include "cocos2d.h"
#include "Models/Jump/Ninja_D.h"
#include "Utility/Config.h"
#include "Utility/Definition.h"
#include "Models/Jump/Pillar.h"
#include "ui/CocosGUI.h"
#include "Scenes/HelloWorldScene.h"
using namespace ui;
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

	//Back Button
	auto backButton = Button::create("back_button-1.png", "back_button-1.png", "back_button - 1.png");
	backButton->setAnchorPoint(Vec2(0, 0));
	backButton->setScale(0.3, 0.5);
	backButton->setPosition(Point(0, screenSize.height - backButton->getContentSize().height/2));
	backButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			//auto helloScene = HelloWorld::createScene();
			Director::getInstance()->replaceScene(HelloWorld::createScene());
			break;
		default:
			break;
		}
	});
	this->addChild(backButton);

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
	
	
	//Xử lý contact
	/*auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(JumpLayer::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);*/

	//Xử lý Touch
	/*auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(JumpLayer::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(JumpLayer::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(JumpLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);*/

	return true;
}

void JumpLayer::SpawnPillar(float spawn)
{
	/*auto randomHeight = CCRANDOM_0_1()*pillar->getContentSize().height / 2;
	pillar->SpawnPillar(this, Point(Config::screenSize.width + pillar->getContentSize().width, randomHeight), 0);*/
}

//bool JumpLayer::onContactBegin(PhysicsContact &contact)
//{
//	PhysicsBody *a = contact.getShapeA()->getBody();
//	PhysicsBody *b = contact.getShapeB()->getBody();
//
//	if ((WALL_COLLISION == a->getCollisionBitmask() && NINJA_COLLISION == b->getCollisionBitmask()) ||
//		(WALL_COLLISION == b->getCollisionBitmask() && NINJA_COLLISION == a->getCollisionBitmask()))
//	{
//		CCLOG("Death");
//	}
//
//	return true;
//}

//#pragma region Touch
//bool JumpLayer::onTouchBegan(Touch *touch, Event *unused_event)
//{
//
//	return true;
//}
//
//void JumpLayer::onTouchMoved(Touch *touch, Event *unused_event)
//{
//
//}
//
//void JumpLayer::onTouchEnded(Touch *touch, Event *unused_event)
//{
//	CCLOG("Mot cai gi do");
//	//ninja->jumpAction();	
//}
//#pragma endregion 