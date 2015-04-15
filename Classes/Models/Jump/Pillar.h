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
	Point getCurrenPos();
	bool init();
	static Pillar* createPillar();
	void MovePillar(Vec2 vec);
	void StopPillar();
	//void chaydi()
	//{
	//	log("chay mau");
	//	log("%f", this->getPosition().x);
	//	CallFunc *runCallback = CallFunc::create(CC_CALLBACK_0(Pillar::check, this));
	//	auto chay = MoveTo::create(1, Config::centerPoint);
	//	//this->getActionManager()->removeAllActionsFromTarget(this);
	//	this->runAction(Sequence::create(chay, runCallback, nullptr));
	//}

	bool onContactBegin(PhysicsContact &contact);
};

#endif _PILLAR_H_
