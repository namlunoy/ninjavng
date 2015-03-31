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
	Ninja* ninja = Ninja::create("Ninja2.png");
	ninja->setPosition(Config::centerPoint);
	this->addChild(ninja);
	string name = "ninja_dungyen";
	ninja->runAnimation(name, 2, 0.5f, true);

	return true;
}