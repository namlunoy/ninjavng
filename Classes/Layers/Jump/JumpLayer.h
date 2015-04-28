#ifndef _JumpLayer_
#define _JumpLayer_
#include "cocos2d.h"
#include "Models/Jump/Ninja_D.h"
#include "Models/Jump/Pillar.h"
#include "Models/Jump/Spring.h"
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
	std::list< Pillar* > listPillar;
	std::list< Pillar* >::iterator firstPillar;
	Point firstSpawnPoint;
	void UpdatePillar();
	void MovePillar(float duration);
	void StopPillar();
	void SpawnPillar(/*Point pos*/);
	void SpawnPillarWithPos(Point pos);

	//Spring
	Spring * spring;
};

#endif
