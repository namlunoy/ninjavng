#include "Layers/Jump/JumpPlayLayer.h"
#include "Utility/Config.h"
#include "Scenes/HelloWorldScene.h"
#include "Scenes/Start_Scene.h"
#include "ui/CocosGUI.h"
#include "Scenes/JumpScene.h"
#include "Utility/Definition.h"
#include "SimpleAudioEngine.h"
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
	this->isShowScoreBoard = false;

	//HighScore Store
	bestScore = UserDefault::getInstance()->getIntegerForKey("JUMP_HIGHSCORE");

	//Music background
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sound_Jump/Bird.mp3");
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound_Jump/Bird.mp3", true);

	//Xử lý Touch
	onTouch = false;
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

void JumpPlayLayer::ShowScoreBoard(int diem)
{
	this->isShowScoreBoard = true;

	//Nền mờ
	Sprite * opacity = Sprite::create("opacity.png");
	opacity->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	opacity->setScale(Config::getScale(opacity));
	opacity->setPosition(Config::centerPoint);
	opacity->setOpacity(192);

	//Replay Button
	Button * replayButton = Button::create("ReplayButton.png");
	replayButton->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	replayButton->setPosition(Point(opacity->getContentSize().width / 2, opacity->getContentSize().height * 0.65 / 7));
	replayButton->setScale(0.5f);
	replayButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(TransitionFade::create(0.5, JumpScene::createPhysicScene(), Color3B::WHITE));
			break;
		default:
			break;
		}
	});

	//Home Button
	Button * homeButton = Button::create("Home.png");
	homeButton->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	homeButton->setPosition(Point(opacity->getContentSize().width / 8, opacity->getContentSize().height * 0.65 / 7));
	homeButton->setScale(0.5f);
	homeButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(TransitionFade::create(0.5, Start_Scene::createStartScene(), Color3B::WHITE));
			break;
		default:
			break;
		}
	});

	//Text GameOver
	Label * textGameOver = Label::create("GAME OVER", "fonts/Vnhatban.TTF", 90, Size::ZERO, TextHAlignment::CENTER, TextVAlignment::CENTER);
	textGameOver->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	textGameOver->setPosition(Point(opacity->getContentSize().width / 2, opacity->getContentSize().height * 4 / 5));
	textGameOver->setColor(Color3B::WHITE);

	//Điểm
	//Text Current Score
	Label * textTempScore = Label::create("SCORE", "fonts/Vnhatban.TTF", 38, Size::ZERO, TextHAlignment::CENTER, TextVAlignment::CENTER);
	textTempScore->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	textTempScore->setPosition(Point(opacity->getContentSize().width * 2.4 / 5, opacity->getContentSize().height * 3.7/ 7));
	textTempScore->setColor(Color3B::WHITE);

	//Current Score
	Label* tempScore = Label::create("0", "fonts/Vnhatban.TTF", 38, Size::ZERO, TextHAlignment::CENTER, TextVAlignment::CENTER);
	tempScore->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	tempScore->setPosition(Point(opacity->getContentSize().width * 2.4 / 5, opacity->getContentSize().height * 3 / 7));
	tempScore->setColor(Color3B::WHITE);
	stringstream ss;
	ss << diem;
	tempScore->setString(ss.str());

	//Text HighScore
	Label * textHighScore = Label::create("HIGH SCORE", "fonts/Vnhatban.TTF", 38, Size::ZERO, TextHAlignment::CENTER, TextVAlignment::CENTER);
	textHighScore->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	textHighScore->setPosition(Point(opacity->getContentSize().width * 2.4 / 5, opacity->getContentSize().height * 2.2 / 7));
	textHighScore->setColor(Color3B::WHITE);

	//High Score
	Label* highScore = Label::create("0", "fonts/Vnhatban.TTF", 38, Size::ZERO, TextHAlignment::CENTER, TextVAlignment::CENTER);
	highScore->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	highScore->setPosition(Point(opacity->getContentSize().width * 2.4 / 5, opacity->getContentSize().height * 1.5 / 7));
	highScore->setColor(Color3B::WHITE);
	if (diem > bestScore)
	{
		bestScore = diem;
		UserDefault::getInstance()->setIntegerForKey("JUMP_HIGHSCORE", diem);
	}
	stringstream ss2;
	ss2 << bestScore;
	highScore->setString(ss2.str());

	//Huy Chuong
	Label * achievement = Label::create("REWARD", "fonts/Vnhatban.TTF", 38, Size::ZERO, TextHAlignment::CENTER, TextVAlignment::CENTER);
	achievement->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	achievement->setColor(Color3B::WHITE);
	achievement->setPosition(Point(opacity->getContentSize().width * 2.7 / 5, opacity->getContentSize().height * 3.7 / 7));
	Sprite * huyChuong = nullptr;
	if (diem < 10)
	{
		huyChuong = Sprite::create("HuyChuong/Khong.png");
	} 
	else if (diem >= 10 && diem < 20)
	{
		huyChuong = Sprite::create("HuyChuong/Dong.png");
	}
	else if (diem >= 20 && diem < 30)
	{
		huyChuong = Sprite::create("HuyChuong/Bac.png");
	}
	else if (diem >= 30 && diem < 40)
	{
		huyChuong = Sprite::create("HuyChuong/Vang.png");
	}
	else if (diem >= 40)
	{
		huyChuong = Sprite::create("HuyChuong/KimCuong.png");
	}
	huyChuong->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	huyChuong->setScale(0.5);
	huyChuong->setPosition(Point(opacity->getContentSize().width * 3.4 / 5, opacity->getContentSize().height * 2.6 / 7));

	//Rectange
	DrawNode * drawNode = DrawNode::create();
	drawNode->drawRect(Vec2(opacity->getContentSize().width * 0.5 / 8, opacity->getContentSize().height * 4.5 / 7), 
		Vec2(opacity->getContentSize().width * 7.5 / 8, opacity->getContentSize().height * 4.5 / 7), 
		Vec2(opacity->getContentSize().width * 7.5 / 8, opacity->getContentSize().height * 1.3 / 7), 
		Vec2(opacity->getContentSize().width * 0.5 / 8, opacity->getContentSize().height * 1.3 / 7), Color4F::WHITE);

	//Add to board 
	opacity->addChild(textTempScore);
	opacity->addChild(tempScore);
	opacity->addChild(textHighScore);
	opacity->addChild(highScore);
	opacity->addChild(replayButton);
	opacity->addChild(homeButton);
	opacity->addChild(achievement);
	opacity->addChild(huyChuong);
	opacity->addChild(textGameOver);
	opacity->addChild(drawNode);

	//AddChild
	this->addChild(opacity);
}

void JumpPlayLayer::ShowXScore(int diem)
{
	xScore = Label::create();
	xScore->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	xScore->setPosition(Point(Config::screenSize.width / 2, Config::screenSize.height / 2 + 100));
	xScore->setSystemFontSize(30);
	xScore->setColor(Color3B::RED);
	stringstream ss;
	ss << "+";
	ss << diem;
	xScore->setString(ss.str());
	this->addChild(xScore);

	//Delay
	DelayTime * delayTime = DelayTime::create(1.2f);
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
	else if (a > 10.0f) return 10.0f;
	else return a;
}

float JumpPlayLayer::Clamp_2(float a)
{
	float b;
	b = a * 0.15f + 3.5f;
	return b;
}

float JumpPlayLayer::Clamp_Spring(float a)
{
	if (a < 1.0f) return 1.0f;
	else if (a > 5.0f) return 5.0f;
	else return a;
}

bool JumpPlayLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
	tinh = true;
	timeTouch = 0.0f;
	onTouch = true;
	return true;
}

void JumpPlayLayer::onTouchEnded(Touch *touch, Event *unused_event)
{
	if (jumpLayer->ninja->isJumping == false && jumpLayer->ninja->isDeath == false && jumpLayer->ninja->isableJump == true)
	{
		jumpLayer->ninja->JumpAction(2560.0f * Clamp(timeTouch * 8.75f));
		//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound_Jump/Jump.mp3", false, 1.0f, 1.0f, 1.0f);
		if (jumpLayer->isShowHowToPlay == true)
		{
			jumpLayer->howToPlay->removeFromParent();
			jumpLayer->isShowHowToPlay = false;
		}
	}	
	onTouch = false;
	tinh = false;
}

void JumpPlayLayer::update(float delta)
{
	/*if (onTouch == true)
	{
		jumpLayer->spring->ScaleDownSpring(1 / Clamp_Spring(timeTouch*10.0f));
	}*/

	if (jumpLayer->ninja->isJumping == true)
	{
		jumpLayer->MovePillar(delta / (2 * Clamp(timeTouch * 10.0f)), Clamp_2(Clamp(timeTouch * 10.0f)));
	}

	if (jumpLayer->ninja->isJumping == false && jumpLayer->ninja->isDeath == false)
	{
		jumpLayer->pillar->StopPillar();
		jumpLayer->UpdatePillar();
	}

	if (jumpLayer->ninja->isDeath == true && jumpLayer->ninja->getPhysicsBody()->getNode() != nullptr && jumpLayer->ninja->getPhysicsBody() != nullptr && isShowScoreBoard == false)
	{
		jumpLayer->pillar->StopPillar();
		//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound_Jump/Ground.mp3", false, 1.0f, 1.0f, 1.0f);
		ShowScoreBoard(this->score);
	}

	if (jumpLayer->ninja->finishJump == true)
	{
		if (jumpLayer->ninja->xScore <= 1)
		{
			this->score += 1;
			//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound_Jump/FinishJump.mp3", false, 1.0f, 1.0f, 1.0f);
			jumpLayer->ninja->xScore = 0;
		}
		else if (jumpLayer->ninja->xScore > 1)
		{
			this->score += (jumpLayer->ninja->xScore * 2);
			ShowXScore(jumpLayer->ninja->xScore * 2);
			//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound_Jump/FinishJump.mp3", false, 1.0f, 1.0f, 1.0f);
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