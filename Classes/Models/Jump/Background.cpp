#include "Background.h"
#include "Utility/Config.h"

Background::Background()
{
}
Background::~Background()
{
}

bool Background::init()
{
	if (!Layer::init()) return false;
	
	auto background = Sprite::create("BambooForest1.PNG");
	background->setPosition(Config::centerPoint);
	background->setScale(Config::getScale(background));
	this->addChild(background);

	return true;
}