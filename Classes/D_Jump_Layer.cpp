#include "D_Jump_Layer.h"
#include "cocos2d.h"
#include "D_Ninja.h"
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
	this->addChild(background);

	D_Ninja *ninja = new D_Ninja(Vec2(400,320));
	this->addChild(ninja,1);
	
	//ninja.jumpAction();
	return true;
}