#include "Background.h"
#include "Utility/Config.h"

Background::Background()
{
}
Background::~Background()
{
}

Background::Background(int i)
{
	char name[100];
	sprintf(name, "Bamboo/Background_bamboo_%d.png", i);
	auto background = Sprite::create(name);
	//auto background = Sprite::create("Bamboo/Background_bamboo_2.png");
	background->setPosition(Config::centerPoint);
	background->setScale(Config::getScale(background));
	this->addChild(background);
}

bool Background::init()
{
	if (!Layer::init()) return false;
	
	/*auto background = Sprite::create("Bamboo/Background_bamboo_2.png");
	background->setPosition(Config::centerPoint);
	background->setScale(Config::getScale(background));
	this->addChild(background);*/

	return true;
}

Background * Background::createBackground(int i)
{
	Background * bg = new Background(i);
	bg->init();
	bg->autorelease();
	return bg;
}
