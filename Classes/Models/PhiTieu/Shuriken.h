#ifndef _Shuriken_
#define _Shuriken_

#include "cocos2d.h"

USING_NS_CC;

class Shuriken : public Node{
private:
	Sprite* _sprite;
	PhysicsBody* _body;
	static float force;
	bool init();


public:
	Shuriken();
	~Shuriken();
	static void nangCap();
	static Shuriken* createSuriken();
	void phong(Vec2 direction);
	bool onContactBegin(PhysicsContact& contact);
};
#endif
