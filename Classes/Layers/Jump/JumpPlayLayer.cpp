#include "Layers/Jump/JumpPlayLayer.h"
#include "Utility/Config.h"
#include "Scenes/HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "Scenes/JumpScene.h"
#include "Utility/Definition.h"
using namespace ui;
using namespace std;

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

void JumpPlayLayer::ShowScoreBoard()
{
	//Bảng điều khiển
	Sprite * scoreBoard = Sprite::create("ScoreBoard.png");
	scoreBoard->setPosition(Point(Config::centerPoint));

	//Replay Button
	Button * replayButton = Button::create("ReplayButton.png");
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
	Label * currentScore = Label::create();
	currentScore->setPosition(Point(scoreBoard->getContentSize().width / 2, scoreBoard->getContentSize().height / 2 + 60));
	currentScore->setSystemFontSize(230);
	currentScore->setColor(Color3B::BLACK);
	currentScore->setString(std::to_string(this->score));

	//Add to board 
	scoreBoard->addChild(currentScore);
	scoreBoard->addChild(replayButton);
	scoreBoard->setScale(0.5);

	//Nền mờ
	Sprite * opacity = Sprite::create("opacity.png");
	opacity->setPosition(Config::centerPoint);
	opacity->setOpacity(128);

	//AddChild
	this->addChild(opacity);
	this->addChild(scoreBoard);
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
	//jumpLayer->spring->ScaleDownSpring(timeTouch);
}

void JumpPlayLayer::onTouchEnded(Touch *touch, Event *unused_event)
{
	if (jumpLayer->ninja->isJumping == false)
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
		jumpLayer->MovePillar(delta*5);	
	}

	if (jumpLayer->ninja->isDeath == true && jumpLayer->ninja->getPhysicsBody()->getNode() != nullptr)
	{
		jumpLayer->pillar->StopPillar();
		jumpLayer->ninja->removeFromParent();
		ShowScoreBoard();
	}

	if (jumpLayer->ninja->isJumping == false)
	{
		jumpLayer->pillar->StopPillar();
		jumpLayer->UpdatePillar();
	}

	if (jumpLayer->ninja->finishJump == true)
	{
		score++;
		log("%d", score);
		jumpLayer->ninja->finishJump = false;
		jumpLayer->scoreText->setString(std::to_string(this->score));
	}

	if (tinh)
	{
		timeTouch += delta;
	}
}