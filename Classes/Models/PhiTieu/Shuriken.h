#ifndef _Shuriken_
#define _Shuriken_

#include "cocos2d.h"

USING_NS_CC;

class Shuriken : public Node{
private:
	Sprite* _sprite;
	PhysicsBody* _body;
	static float force;// = 700.0f;
	bool init();


public:
	Shuriken();
	~Shuriken();
	static Shuriken* createSuriken();
	void phong(Vec2 direction);
	bool onContactBegin(PhysicsContact& contact);
};
#endif
