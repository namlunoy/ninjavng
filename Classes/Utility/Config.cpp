#include "Config.h"


Config::Config(){}
Config::~Config(){}

Vec2 Config::centerPoint = Vec2(0,0);
Size Config::screenSize = Size(0, 0);


float Config::getScale(Node* p)
{
	float xScale = screenSize.width / p->getContentSize().width;
	float yScale = screenSize.height / p->getContentSize().height;
	return max(xScale, yScale);
}

float Config::getScale(string backgroundFileName)
{
	Sprite* background = Sprite::create(backgroundFileName);
	float theScale = getScale(background);
	//background->release();
	return theScale;
}

