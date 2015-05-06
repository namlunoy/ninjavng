﻿#include "Layers/Jump/JumpPlayLayer.h"
#include "Utility/Config.h"
#include "Scenes/HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "Scenes/JumpScene.h"
#include "Utility/Definition.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace ui;
using namespace std;

JumpPlayLayer::JumpPlayLayer(){}
JumpPlayLayer::~JumpPlayLayer(){}

bool JumpPlayLayer::init()
{
	//Score
	this->score = 0;

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

void JumpPlayLayer::ShowScoreBoard()
{
	//Bảng điều khiển
	Sprite * scoreBoard = Sprite::create("ScoreBoard.png");
	scoreBoard->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	scoreBoard->setPosition(Point(Config::centerPoint));

	//Replay Button
	Button * replayButton = Button::create("ReplayButton.png");
	replayButton->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	replayButton->setPosition(Point(scoreBoard->getContentSize().width/2, replayButton->getContentSize().height/2 + 70));
	replayButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(TransitionFade::create(0.5, JumpScene::createPhysicScene(), Color3B(34, 177, 76)));
			break;
		default:
			break;
		}
	});

	//Điểm
	Label* currentScore = Label::create();
	currentScore->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	currentScore->setPosition(Point(scoreBoard->getContentSize().width / 2, scoreBoard->getContentSize().height/2 + 60));
	currentScore->setSystemFontSize(230);
	currentScore->setColor(Color3B::BLACK);
	stringstream ss;
	ss<<this->score;
	currentScore->setString(ss.str());

	//Add to board 
	scoreBoard->addChild(currentScore);
	scoreBoard->addChild(replayButton);
	scoreBoard->setScale(0.5);

	//Nền mờ
	Sprite * opacity = Sprite::create("opacity.png");
	opacity->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	opacity->setScale(Config::getScale(opacity));
	opacity->setPosition(Config::centerPoint);
	opacity->setOpacity(128);

	//AddChild
	this->addChild(opacity);
	this->addChild(scoreBoard);
}

void JumpPlayLayer::ShowXScore(int diem)
{
	xScore = Label::create();
	xScore->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	xScore->setPosition(Point(Config::screenSize.width / 3, Config::screenSize.height / 2 + 150));
	xScore->setSystemFontSize(30);
	xScore->setColor(Color3B::RED);
	stringstream ss;
	ss << "+";
	ss << diem;
	xScore->setString(ss.str());
	this->addChild(xScore);

	//Delay
	DelayTime * delayTime = DelayTime::create(2.0f);
	CallFunc * removeXScore = CallFunc::create(CC_CALLBACK_0(JumpPlayLayer::RemoveXScore, this));
	xScore->runAction(Sequence::createWithTwoActions(delayTime, removeXScore));
}

void JumpPlayLayer::RemoveXScore()
{
	this->xScore->removeFromParent();
}

float JumpPlayLayer::Clamp(float a)
{
	if (a < 1.5f) return 1.5f;
	else if (a > 8.5f) return 8.5f;
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
	if (jumpLayer->ninja->isJumping == false && jumpLayer->ninja->getParent() != NULL 
		&& jumpLayer->ninja->getPhysicsBody()->getNode() != nullptr && jumpLayer->ninja->getPhysicsBody() != nullptr)
	{
		jumpLayer->ninja->JumpAction(2500.0f * Clamp(timeTouch * 8.75f));
	}	
	tinh = false;
}
#pragma endregion 

void JumpPlayLayer::update(float delta)
{
	if (jumpLayer->ninja->isJumping == true)
	{
		jumpLayer->MovePillar(delta * 2.5);	
	}

	if (jumpLayer->ninja->isJumping == false && jumpLayer->ninja->isDeath == false)
	{
		jumpLayer->pillar->StopPillar();
		jumpLayer->UpdatePillar();
	}

	if (jumpLayer->ninja->isDeath == true && jumpLayer->ninja->getPhysicsBody()->getNode() != nullptr && jumpLayer->ninja->getPhysicsBody() != nullptr)
	{
		jumpLayer->pillar->StopPillar();
		jumpLayer->ninja->removeFromParent();
		ShowScoreBoard();
	}

	if (jumpLayer->ninja->finishJump == true)
	{
		if (jumpLayer->ninja->xScore <= 1)
		{
			this->score += 1;
			jumpLayer->ninja->xScore = 0;
		}
		else if (jumpLayer->ninja->xScore > 1)
		{
			this->score += (jumpLayer->ninja->xScore * 2);
			ShowXScore(jumpLayer->ninja->xScore * 2);
			jumpLayer->ninja->xScore = 0;
		}
		jumpLayer->ninja->finishJump = false;
		stringstream ss;
		ss<<this->score;
		jumpLayer->scoreText->setString(ss.str());
	}

	if (tinh)
	{
		timeTouch += delta;
	}
}
