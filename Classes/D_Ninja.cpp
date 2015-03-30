#include "D_Ninja.h"
#include "cocos2d.h"
USING_NS_CC;


D_Ninja::D_Ninja(Vec2 posStart)
{
	ninjaSprite = Sprite::create("Ninja2.png");
	ninjaSprite->setPosition(posStart);
	//currentPos = ninjaSprite->getPosition();
}

D_Ninja::~D_Ninja()
{
}

void D_Ninja::jumpAction()
{
	auto jump = JumpTo::create(1.5, currentPos, 50, 1);
	ninjaSprite->runAction(jump);
}