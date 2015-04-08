#include "GamePlayLayer.h"

GamePlayLayer::GamePlayLayer()
{
}
GamePlayLayer::~GamePlayLayer()
{
}

bool GamePlayLayer::init()
{
	if (!GamePlayLayer::init()) return false;

	//Xử lý Touch
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(GamePlayLayer::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(GamePlayLayer::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(GamePlayLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;
}

void GamePlayLayer::update()
{

}

#pragma region Touch
bool GamePlayLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
	ninja->JumpAction(1000.0f);
	return true;
}

void GamePlayLayer::onTouchMoved(Touch *touch, Event *unused_event)
{

}

void GamePlayLayer::onTouchEnded(Touch *touch, Event *unused_event)
{
	CCLOG("Mot cai gi do");
	ninja->getPhysicsBody()->resetForces();
}
#pragma endregion 