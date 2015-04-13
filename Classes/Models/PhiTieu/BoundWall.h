#ifndef _BoundWall_
#define _BoundWall_

#include "cocos2d.h"
#include "Utility/XHelper.h"

USING_NS_CC;

class BoundWall : public Node
{
public:
	static BoundWall* createWall(WallType type, Size size);
	BoundWall(WallType type, Size screenSize);
	~BoundWall();
};

#endif


