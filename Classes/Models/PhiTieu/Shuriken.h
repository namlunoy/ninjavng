#ifndef _Shuriken_
#define _Shuriken_

#include "cocos2d.h"

USING_NS_CC;

class Shuriken : public Node{
private:
	Sprite* _sprite;
	bool init();
	

public:
	Shuriken();
	~Shuriken();
	Shuriken(Vec2 start);
	static Shuriken* createSuriken(Vec2 start);
	
};
#endif
