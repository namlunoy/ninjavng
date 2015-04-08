#ifndef _JumpLayer_
#define _JumpLayer_
#include "cocos2d.h"
#include "Models/Jump/Ninja_D.h"
#include "Models/Jump/Pillar.h"
#include "Layers/Jump/GamePlayLayer.h"
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
	Ninja_D* ninja;
	//bool onContactBegin(PhysicsContact &contact);

	//bool onTouchBegan(Touch *touch, Event *unused_event);
	//void onTouchMoved(Touch *touch, Event *unused_event);
	//void onTouchEnded(Touch *touch, Event *unused_event);
};

#endif
