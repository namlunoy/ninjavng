#ifndef _JumpLayer_
#define _JumpLayer_
#include "cocos2d.h"
#include "Models/Jump/Ninja_D.h"
#include "Models/Jump/Pillar.h"
#include <iostream>
#include <list>
USING_NS_CC;

class JumpLayer : public Layer
{
public:
	JumpLayer();
	~JumpLayer();
	bool init();
	CREATE_FUNC(JumpLayer);
	PhysicsWorld *physicsWorld;
	void SetPhysicsWorld (PhysicsWorld *world) {physicsWorld = world; }
	Ninja_D* ninja;

	//Pillar
	Pillar *pillar;
	Pillar *lastPillar;
	Pillar *nextPillar;
	std::list< Pillar* > listPillar;
	Point firstSpawnPoint;
	Point prevSpawnPoint;
	Point nextSpawnPoint;
	Point randomPoint;
	void MovePillar();
	void SpawnPillar();
	void update(float delta);
};

#endif
