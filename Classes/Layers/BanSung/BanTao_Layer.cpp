﻿#include "Scenes/HelloWorldScene.h"
#include "Layers/BanSung/BanTao_Layer.h"
#include "Scenes/BanTao_Scence.h"
#include "ui/CocosGUI.h"
#include <iostream>
#include "Models/BanSung/BanTao_Target.h"
#include "Utility/Config.h"
#include "Utility/XHelper.h"


using namespace std;
using namespace ui;

BanTao_Layer::BanTao_Layer() { }
BanTao_Layer::~BanTao_Layer(){ }


int mang;
float speed;
float score;

bool BanTao_Layer::init()
{
	mang = 3;
	speed = 1;
	score = 0;

	if (!Layer::init())
		return false;

	//Hiển thị background
	Sprite* background = Sprite::create("soc_bg.jpg");
	background->setPosition(Config::centerPoint);
	background->setScale(Config::getScale(background));
	this->addChild(background, -1);
	
	//Thêm mạng
	headSprite();
	
	//Thêm Animation kid 
	auto kidstart = Sprite::create("kid.png");
	kidstart->setPosition(Config::centerPoint.x, Config::centerPoint.y);
	kidstart->setScale(1.2);
	XHelper::runAnimation("kidstart", 2, 0.5f, true, kidstart);
	this->addChild(kidstart);
	kidstart->setTag(15);

	//Thêm comment
	commentPut("commentStart.png");

	//Thêm sprite quả táo 
	appleSprite();

	//button start
	auto button = Button::create("Start2.png", "Start1.png", "Start2.png");
	button->setTag(12);
	button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			std::cout << "Button 1 clicked" << std::endl;
			onStart(speed);
			break;
		default:
			break;
		}
	});
	button->setPosition(Point(Config::centerPoint.x, Config::centerPoint.y - 190));


	button->setScale(0.4);
	this->addChild(button);

	//button back
	auto backButton = Button::create("backbutton.png", "backbutton2.png");
	backButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
		{
												  auto scene = HelloWorld::createScene();
												  Director::getInstance()->replaceScene(scene);
												  init();
												  
		}
			break;
		default:
			break;
		}
	});
	backButton->setPosition(Vec2(100, 100));
	this->addChild(backButton, 0);


	

	return true;
}

void BanTao_Layer::onStart( float speed)
{
	//xóa buttonStart, comment
	this->removeChildByTag(12);
	this->removeChildByTag(10);

	//Thêm target
	BanTao_Target* target = BanTao_Target::create("target2.png",speed);
	this->addChild(target, 1);
	
	
	//Touch
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(BanTao_Layer::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(BanTao_Layer::onTouchEnded, this, target);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}



bool BanTao_Layer::onTouchBegan(Touch *touch, Event *unused_event)
{

	return true;
}


void BanTao_Layer::onTouchEnded(Touch *touch, Event *unused_event, BanTao_Target *target)
{
	
	//tạo paticle
	auto emitter = ParticleFire::create();
	Vec2 xxx = touch->getLocation();
	emitter->setPosition(target->getPosition());
	emitter->setDuration(0.5);
	this->addChild(emitter, 10);

	//tính xem tọa độ của cái target có trùng quả táo không?
	// nếu trùng thì quả táo biến mất
	if (XHelper::checkShoot(Vec2(Config::centerPoint.x, Config::centerPoint.y + 158), 40, target->getPosition()))
	{

		commentPut("commentWin.png");
		//xóa đi apple
		this->removeChildByTag(11);
		
		//thêm lại apple 
		this->runAction(Sequence::create(
			DelayTime::create(1),
			CallFunc::create(CC_CALLBACK_0(BanTao_Layer::appleSprite, this)),
			nullptr));
		//tạo target mới
		this->removeChildByTag(13);
		speed = speed - 0.1;

		BanTao_Target* target = BanTao_Target::create("target2.png",speed);
		this->addChild(target,1);

		score = score + 10;
		CCLOG("Score: %f", score);
	}
	else
	{

		mang--;
		CCLOG("Mang: %d", mang);
		commentPut("commentFail.png");
		checkLive();
	}

}


void BanTao_Layer::commentPut(string name)
{

	auto comment = Sprite::create(name);
	comment->setPosition(Point(Config::centerPoint.x + 150, Config::centerPoint.y + 150));
	comment->setScale(0.8);
	this->addChild(comment);
	comment->setTag(10);
}

void BanTao_Layer::appleSprite()
{
	auto apple = Sprite::create("apple.png");
	apple->setPosition(Vec2(Config::centerPoint.x, Config::centerPoint.y + 158));
	apple->setScale(0.5);
	this->addChild(apple);
	apple->setTag(11);
}

void BanTao_Layer::headSprite()
{
	auto head1 = Sprite::create("head1.png");
	head1->setPosition(Vec2(Config::centerPoint.x - 350, Config::centerPoint.y + 200));
	head1->setScale(0.6);
	this->addChild(head1, 0);
	head1->setTag(16);
	auto head2 = Sprite::create("head1.png");
	head2->setPosition(Vec2(Config::centerPoint.x - 290, Config::centerPoint.y + 200));
	head2->setScale(0.6);
	this->addChild(head2, 0);
	head2->setTag(17);
	auto head3 = Sprite::create("head1.png");
	head3->setPosition(Vec2(Config::centerPoint.x - 230, Config::centerPoint.y + 200));
	head3->setScale(0.6);
	this->addChild(head3, 0);
	head3->setTag(18);
}
void BanTao_Layer::checkLive()
{
	

	if (mang>=3)
	{
		
	}
	if (mang==2)
	{
		this->removeChildByTag(18);
		CCLOG("Con 2 mang");
	}
	if (mang==1)
	{
		this->removeChildByTag(17);
		CCLOG("Con 1 mang");
	}
	if (mang<1)
	{
		this->removeChildByTag(16);
		CCLOG("Game over");
		Director::getInstance()->getEventDispatcher()->pauseEventListenersForTarget(this);

		//xóa đi cái target, thằng người để cho thằng khác vào!
		this->removeChildByTag(10);
		this->removeChildByTag(13);
		this->removeChildByTag(15);


		commentPut("commentGameOver.png");

		auto kidcry = Sprite::create("kid.png");
		kidcry->setPosition(Config::centerPoint.x, Config::centerPoint.y);
		kidcry->setScale(1.2);
		XHelper::runAnimation("cry", 2, 0.5f, true, kidcry);
		this->addChild(kidcry);
		kidcry->setTag(15);

		this->runAction(Sequence::create(
			DelayTime::create(2),
			
			CallFunc::create(CC_CALLBACK_0(BanTao_Layer::restart, this)),
			nullptr));

	}
}

void BanTao_Layer::restart()
{
	this->removeAllChildren();
	//Scene* newScene = BanTao_Scence::create();

	auto newScene = BanTao_Scence::create();
	Director::getInstance()->replaceScene(newScene);
	init();
}

void BanTao_Layer::setHudLayer(BanTao_HudLayer* pHudLayer)
{
	__pHudLayer = pHudLayer;
}

//void BanTao_Layer::update(cocos2d::ccTime dt)
//{
//
//}
