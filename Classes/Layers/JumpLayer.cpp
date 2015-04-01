#include "JumpLayer.h"
#include "cocos2d.h"
#include "Models/Ninja.h"
#include "Utility/Config.h"

USING_NS_CC;

JumpLayer::~JumpLayer()
{
}

bool JumpLayer::init()
{
	if (!Layer::init()) return false;
	//Screen
	Size size = Director::getInstance()->getVisibleSize();

	//Background
	auto background = Sprite::create("Background.jpg");
	background->setPosition(size.width / 2, size.height / 2);
	background->setScale(Config::getScale(background));
	this->addChild(background,-1);

	//Ninja
	ninja = Ninja::create("Ninja2.png");
	ninja->setPosition(Config::centerPoint);
	this->addChild(ninja,1);

	//Touch
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(JumpLayer::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(JumpLayer::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(JumpLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

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
	ninja->jumpAction();
}
#pragma endregion 
