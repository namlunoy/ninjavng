#ifndef _JumpLayer_
#define _JumpLayer_
#include "cocos2d.h"
#include "Models/Jump/Ninja_D.h"
#include "Models/Jump/Pillar.h"
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
};

#endif
