#include "PhiTieuHUDLayer.h"
#include "Utility/Config.h"
#include "Scenes/PhiTieuScene.h"
#include "SimpleAudioEngine.h"
#include <sstream>


PhiTieuHUDLayer* PhiTieuHUDLayer::Instance = nullptr;
PhiTieuHUDLayer::PhiTieuHUDLayer() {
}
PhiTieuHUDLayer::~PhiTieuHUDLayer() {
}

void PhiTieuHUDLayer::setPhiTieuLayer(PhiTieuLayer* p)
{
	_phiTieuLayer = p;
}

bool PhiTieuHUDLayer::init() {
	if (!Layer::init())
		return false;


	//Back Button
	auto backButton = Button::create("back_button-1.png", "back_button-1.png", "back_button-1.png");
	backButton->setAnchorPoint(Vec2(0, 0));
	backButton->setScale(0.3f, 0.5f);
	backButton->setPosition(Point(0, Config::screenSize.height - backButton->getContentSize().height / 2));
	backButton->addTouchEventListener(
		[&](Ref* sender, Widget::TouchEventType type) {
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

	//------------------ Music Background -----------------//
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sound_PhiTieu/Music1.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Sound_PhiTieu/Music1.mp3", true);

	//------------------ Button jump  ---------------------
	bt_jump = Button::create("bt_jump_1.png", "bt_jump_2.png", "bt_jump_2.png");
	bt_jump->setAnchorPoint(Vec2(0, 0));
	bt_jump->setPosition(Vec2(0, 0));
	bt_jump->setScale(0.5f);
	bt_jump->addTouchEventListener(this, toucheventselector(PhiTieuHUDLayer::click_Jump));
	this->addChild(bt_jump);

	//-----------------  Touch event ------------
	auto _touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(PhiTieuHUDLayer::touch_PhongTieu, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);


	//-------------- Trai tim ---------
	hearts.pushBack(Sprite::create("heart.png"));
	hearts.pushBack(Sprite::create("heart.png"));
	hearts.pushBack(Sprite::create("heart.png"));
	for (int i = 0; i < 3; i++)
	{
		hearts.at(i)->setScale(0.25f);
		hearts.at(i)->setPosition(Vec2(50 + 50 * i, Config::screenSize.height - 50));
		this->addChild(hearts.at(i));
	}




	//Tao thanh power
	power = Power::createPower(PhiTieuScene::GetLevel());
	power->setPosition(Vec2(30, Config::screenSize.height - 70));
	this->addChild(power);

	//------------------------ Label ---------------------------
	txt_score = Label::createWithTTF("0", "fonts/Karate.ttf", 37);
	txt_score->setPosition(Vec2(Config::screenSize.width - 30, Config::screenSize.height - 40));
	this->addChild(txt_score);

	txt_Back = Label::createWithTTF("0", "fonts/Karate.ttf", 37);
	txt_Back->setPosition(Vec2(Config::screenSize.width/2-100, 0));
	this->addChild(txt_Back);

	txt_Replay = Label::createWithTTF("0", "fonts/Karate.ttf", 37);
	txt_Replay->setPosition(Vec2(Config::screenSize.width/2+100, 0));
	this->addChild(txt_Replay);

	score = 0;
	PhiTieuHUDLayer::Instance = this;
	return true;
}

void PhiTieuHUDLayer::matMau()
{
	if (hearts.size() > 0)
	{
		hearts.at(hearts.size() - 1)->removeFromParent();
		hearts.popBack();
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound_PhiTieu/Fail.mp3");
	}
}

bool PhiTieuHUDLayer::touch_PhongTieu(Touch* t, Event* e) {
	if (Ninja::Instance != nullptr)
		if (power->fire())
			_phiTieuLayer->PhongTieu(t->getLocation());

	return true;
}

void PhiTieuHUDLayer::click_Jump(Ref* sender, TouchEventType touchType) {
	//Thực hiện nhảy
	if (touchType == TouchEventType::TOUCH_EVENT_BEGAN) {
		_phiTieuLayer->Jump();
	}
}



void PhiTieuHUDLayer::gameOver() {
	Sprite* over = Sprite::create("gameover.png");
	float scale = Config::getScale(over);
	over->setPosition(Config::centerPoint);
	over->setScale(scale);
	bt_jump->removeFromParent();
	power->removeFromParent();
	for(auto e : hearts)
		e->removeFromParent();
	this->addChild(over);
}

void PhiTieuHUDLayer::gameWin() {
	Sprite* over = Sprite::create("gameover.png");
	float scale = Config::getScale(over);
	over->setPosition(Config::centerPoint);
	over->setScale(scale);
	bt_jump->removeFromParent();
	power->removeFromParent();
	for(auto e : hearts)
		e->removeFromParent();
	this->addChild(over);
}

void PhiTieuHUDLayer::tangDiem() {
	score++;
	std::stringstream ss;
	ss << score;
	txt_score->setString(ss.str());
	//Animation
	auto phongTo = ScaleTo::create(0.1f, 1.8);
	auto thuNho = ScaleTo::create(0.1f, 1);
	txt_score->runAction(Sequence::createWithTwoActions(phongTo, thuNho));

	//Xử lý thắng
	if(score >= 30)
	{

	}
}
