#include "D_Jump_Layer.h"
#include "cocos2d.h"
#include "D_Ninja.h"
#include "Config.h"
USING_NS_CC;

D_Jump_Layer::~D_Jump_Layer()
{
}

bool D_Jump_Layer::init()
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
	ninja = new D_Ninja(Vec2(400,320));
	this->addChild(ninja,1);
	ninja->jumpAction();
	//Touch
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(D_Jump_Layer::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(D_Jump_Layer::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(D_Jump_Layer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;
}

#pragma region Touch
bool D_Jump_Layer::onTouchBegan(Touch *touch, Event *unused_event)
{
	return true;
}

void D_Jump_Layer::onTouchMoved(Touch *touch, Event *unused_event)
{
	
}

void D_Jump_Layer::onTouchEnded(Touch *touch, Event *unused_event)
{
	CCLOG("Mot cai gi do");
}
#pragma endregion 