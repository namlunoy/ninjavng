#ifndef _NINJA_D_
#define _NINJA_D_

#include "cocos2d.h"
USING_NS_CC;

class Ninja_D : public Node
{
public:
	Ninja_D(Layer *layer);
	~Ninja_D();

	bool isJumping;
	bool isStanding;

	void JumpAction();
	PhysicsBody *bodyNinja;
};

#endif //_NINJA_D_