#ifndef _Nen_
#define _Nen_
#include "cocos2d.h"
#include "Utility/Config.h"
USING_NS_CC;
class Nen : public Node
{
public:
	static Nen* Tao_Nen();
	Nen();
	~Nen();
	PhysicsBody* Body_Nen;
	bool init();
};
#endif