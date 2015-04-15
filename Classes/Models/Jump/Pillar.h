#ifndef _PILLAR_H_
#define _PILLAR_H_
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
 
class Pillar: public Sprite
{
public:
	Pillar();
	~Pillar();
	Sprite *sprite;
	PhysicsBody *body;
	Point getCurrenPos();

	bool init();
	
	static Pillar* createPillar(/*Point pos*/);
	void SpawnPillar(Layer *layer, Point pos);
	void MovePillar();
	void StopPillar();

	bool onContactBegin(PhysicsContact &contact);
};

#endif _PILLAR_H_
