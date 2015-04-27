#include "JumpPlayLayer.h"
#include "Utility/Config.h"
#include "Scenes/HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "Utility/Definition.h"
using namespace ui;

JumpPlayLayer::JumpPlayLayer(){}
JumpPlayLayer::~JumpPlayLayer(){}

bool JumpPlayLayer::init()
{
	//Back Button
	auto backButton = Button::create("back_button-1.png", "back_button-1.png");
	backButton->setAnchorPoint(Vec2(0, 0));
	backButton->setScale(0.3f, 0.5f);
	backButton->setPosition(Point(0, Config::screenSize.height - backButton->getContentSize().height / 2));
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

	//Xử lý Touch
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(JumpPlayLayer::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(JumpPlayLayer::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(JumpPlayLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	this->scheduleUpdate();
	return true;
}

void JumpPlayLayer::SetJumpLayer(JumpLayer *jumplayer)
{
	this->jumpLayer = jumplayer;
}

float JumpPlayLayer::Clamp(float a)
{
	if (a < 2.0f) return 2.0f;
	else if (a > 9.0f) return 9.0f;
	else return a;
}

#pragma region Touch
bool JumpPlayLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
	tinh = true;
	timeTouch = 0.0f;
	return true;
}

void JumpPlayLayer::onTouchMoved(Touch *touch, Event *unused_event)
{
}

void JumpPlayLayer::onTouchEnded(Touch *touch, Event *unused_event)
{
	jumpLayer->ninja->JumpAction(2500.0f * Clamp(timeTouch * 8.75f));
	//log("%f", timeTouch);log("%f", timeTouch);
	tinh = false;
}
#pragma endregion 

void JumpPlayLayer::update(float delta)
{
	if (jumpLayer->ninja->isJumping == true)
	{
		jumpLayer->MovePillar(delta / 3);		
	}
	if (jumpLayer->ninja->isJumping == false)
	{
		jumpLayer->pillar->StopPillar();
		jumpLayer->UpdatePillar();
	}

	if (tinh)
	{
		timeTouch += delta;
	}
}