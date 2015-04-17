#ifndef _NINJA_D_
#define _NINJA_D_

#include "cocos2d.h"
USING_NS_CC;

class Ninja_D : public Node
{
public:
	Ninja_D();
	~Ninja_D();
	Sprite *sprite;
	PhysicsBody *body;
	bool init();
	bool isJumping;
	static Ninja_D* createNinja();
	void JumpAction(float force);

	bool onContactBegin(PhysicsContact &contact);
	
};

#endif //_NINJA_D_