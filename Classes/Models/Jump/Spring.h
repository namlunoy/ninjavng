#ifndef _SPRING_
#define _SPRING_
#include "cocos2d.h"
USING_NS_CC;
 
class Spring: public Node
{
public:
	Spring();
	Sprite *sprite;
	PhysicsBody *body;
	bool init();
	static Spring* createSpring();
};

#endif// _SPRING_
