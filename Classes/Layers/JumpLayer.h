#ifndef _JumpLayer_
#define _JumpLayer_
#include "cocos2d.h"
#include "Models/Ninja.h"
#include "Models/Pillar.h"
USING_NS_CC;

class JumpLayer : public Layer
{
public:
	~JumpLayer();
	bool init();
	CREATE_FUNC(JumpLayer);
	PhysicsWorld *physicsWorld;
	void SetPhysicsWorld (PhysicsWorld *world) {physicsWorld = world; }
	void SpawnPillar(float spawn);
	Pillar *pillar;
	Ninja *ninja;
	bool onContactBegin(PhysicsContact &contact);

	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
};

#endif
