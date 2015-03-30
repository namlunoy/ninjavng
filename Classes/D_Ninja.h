#ifndef _D_Ninja_
#define _D_Ninja_
#include "cocos2d.h"
USING_NS_CC;

class D_Ninja: public cocos2d::Node
{
public:
	D_Ninja(Vec2 posStart);
	~D_Ninja();
	Sprite* ninjaSprite;
	Vec2 currentPos;
	void jumpAction();
};

#endif