#include "Layers/Jump/JumpPlayLayer.h"
#include "Utility/Config.h"
#include "Scenes/HelloWorldScene.h"
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
	/*def = UserDefault::sharedUserDefault();
	bestScore = def->getIntegerForKey("HIGHSCORE");
	log("bestscore: %d", bestScore);
	def->setIntegerForKey("HIGHSCORE", 100);
	def->flush();
	log("Bestscore2: %d", bestScore);*/

	//Sound
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Sound_Jump/Jump.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Sound_Jump/Ground.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Sound_Jump/FinishJump.mp3");

	//Music background
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sound_Jump/Bird.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound_Jump/Bird.mp3", true);

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

void JumpPlayLayer::ShowScoreBoard(int diem)
{
	this->isShowScoreBoard = true;

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
	//Text CurrentScore
	Label * textTempScore = Label::create();
	textTempScore->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	textTempScore->setPosition(Point(scoreBoard->getContentSize().width / 3 - 70, scoreBoard->getContentSize().height / 2 + 130));
	textTempScore->setSystemFontSize(35);
	textTempScore->setColor(Color3B::BLACK);
	textTempScore->setString("Score");

	//Điểm vừa chơi
	Label* tempScore = Label::create();
	tempScore->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	tempScore->setPosition(Point(scoreBoard->getContentSize().width / 3 - 70, scoreBoard->getContentSize().height / 2 + 90));
	tempScore->setSystemFontSize(35);
	tempScore->setColor(Color3B::BLACK);
	stringstream ss;
	ss << diem;
	tempScore->setString(ss.str());

	//Text HighScore
	Label * textHighScore = Label::create();
	textHighScore->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	textHighScore->setPosition(Point(scoreBoard->getContentSize().width / 3 - 70, scoreBoard->getContentSize().height / 2 + 20));
	textHighScore->setSystemFontSize(35);
	textHighScore->setColor(Color3B::BLACK);
	textHighScore->setString("High Score");

	//High Score
	Label* highScore = Label::create();
	highScore->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	highScore->setPosition(Point(scoreBoard->getContentSize().width / 3 - 70, scoreBoard->getContentSize().height / 2 - 20));
	highScore->setSystemFontSize(35);
	highScore->setColor(Color3B::BLACK);
	/*if (diem > bestScore)
	{
		bestScore = diem;
		def->setIntegerForKey("HIGHSCORE", bestScore);
		def->flush();
	}*/
	stringstream ss2;
	ss2 << diem;
	highScore->setString(ss2.str());

	//Add to board 
	scoreBoard->addChild(textTempScore);
	scoreBoard->addChild(tempScore);
	scoreBoard->addChild(textHighScore);
	scoreBoard->addChild(highScore);
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
	if (jumpLayer->ninja->isJumping == false && jumpLayer->ninja->getParent() != NULL && jumpLayer->ninja->isDeath == false)
	{
		jumpLayer->ninja->JumpAction(2500.0f * Clamp(timeTouch * 8.75f));
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound_Jump/Jump.mp3", false, 1.0f, 1.0f, 1.0f);
	}	
	tinh = false;
}
#pragma endregion 

void JumpPlayLayer::update(float delta)
{
	if (jumpLayer->ninja->isJumping == true)
	{
		jumpLayer->MovePillar(delta);	
	}

	if (jumpLayer->ninja->isJumping == false && jumpLayer->ninja->isDeath == false)
	{
		jumpLayer->pillar->StopPillar();
		jumpLayer->UpdatePillar();
	}

	if (jumpLayer->ninja->isDeath == true && jumpLayer->ninja->getPhysicsBody()->getNode() != nullptr && jumpLayer->ninja->getPhysicsBody() != nullptr && isShowScoreBoard == false)
	{
		jumpLayer->pillar->StopPillar();
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound_Jump/Ground.mp3", false, 1.0f, 1.0f, 1.0f);
		ShowScoreBoard(this->score);
		//jumpLayer->ninja->removeFromParent();
	}

	if (jumpLayer->ninja->finishJump == true)
	{
		if (jumpLayer->ninja->xScore <= 1)
		{
			this->score += 1;
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound_Jump/FinishJump.mp3", false, 1.0f, 1.0f, 1.0f);
			jumpLayer->ninja->xScore = 0;
		}
		else if (jumpLayer->ninja->xScore > 1)
		{
			this->score += (jumpLayer->ninja->xScore * 2);
			ShowXScore(jumpLayer->ninja->xScore * 2);
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound_Jump/FinishJump.mp3", false, 1.0f, 1.0f, 1.0f);
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
