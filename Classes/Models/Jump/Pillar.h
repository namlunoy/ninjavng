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
	Pillar(int i);
	~Pillar();
	Sprite *sprite;
	PhysicsBody *body;
	bool init();
	static Pillar* createPillar();
	static Pillar* createPillar(int i);
	void MovePillar(float duration);
	void StopPillar();
	bool isContactWithWall;
	bool onContactBegin(PhysicsContact &contact);
};

#endif
