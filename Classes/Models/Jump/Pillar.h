#ifndef _PILLAR_H_
#define _PILLAR_H_
#include "cocos2d.h"
#include "Utility/Config.h"
USING_NS_CC;
using namespace std;
 
class Pillar: public Node
{
public:
	Pillar();
	~Pillar();
	Sprite *sprite;
	PhysicsBody *body;
	bool init();
	static Pillar* createPillar();
	void MovePillar(float duration);
	void StopPillar();
	bool onContactBegin(PhysicsContact &contact);
};

#endif
