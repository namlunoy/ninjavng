#include "Cong_PhiTieuLayer.h"


Cong_PhiTieuLayer::Cong_PhiTieuLayer() { }
Cong_PhiTieuLayer::~Cong_PhiTieuLayer(){ }


bool Cong_PhiTieuLayer::init()
{
	if (!Layer::init())
		return false;

	Cong_Shuriken* s = new Cong_Shuriken(Vec2(0, 0));
	this->addChild(s);

	//Hiển thị background
	Sprite* background = Sprite::create("cong_background.jpg");
	background->setPosition(Config::centerPoint);
	background->setScale(Config::getScale(background));
	this->addChild(background, -1);

	//Theem ninja
	 ninja = Ninja::create("Ninja2.png");
	ninja->setPosition(Config::centerPoint);
	this->addChild(ninja);
	ninja->runAnimation_DungYen();

	//Theem ninja
	ninja = Ninja::create("Ninja2.png");
	ninja->setPosition(Config::centerPoint + Vec2(100,100));
	this->addChild(ninja);
	ninja->runAnimation_Nhay();

	//touch event
	auto _touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(Cong_PhiTieuLayer::touchScreen, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);

	return true;
}

bool Cong_PhiTieuLayer::touchScreen(Touch* t, Event* e)
{
	ninja->removeAllActions();
	return true;
}