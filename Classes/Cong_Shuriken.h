#ifndef _CONG_SHURIKEN_
#define _CONG_SHURIKEN_

#include "cocos2d.h"

USING_NS_CC;

class Cong_Shuriken : public Node{
private:
	Sprite* _sprite;
	bool init();
	

public:
	Cong_Shuriken();
	~Cong_Shuriken();
	Cong_Shuriken(Vec2 start);
	static Cong_Shuriken* createSuriken(Vec2 start);
	
};
#endif
