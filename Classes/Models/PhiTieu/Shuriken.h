#ifndef _Shuriken_
#define _Shuriken_

#include "cocos2d.h"

USING_NS_CC;

class Shuriken : public Node{
private:
	Sprite* _sprite;
	PhysicsBody* _body;

	bool init();
	

public:
	Shuriken();
	~Shuriken();
	static Shuriken* createSuriken();
	void phong(Vec2 huong);
	bool onContactBegin(PhysicsContact& contact);
};
#endif
