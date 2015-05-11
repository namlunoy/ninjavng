#ifndef _JumpLayer_
#define _JumpLayer_
#include "cocos2d.h"
#include "Models/Jump/Ninja_D.h"
#include "Models/Jump/Pillar.h"
#include "Models/Jump/Spring.h"
#include "Models/Jump/ScoreNode.h"
#include <iostream>
#include <list>
USING_NS_CC;

class JumpLayer : public Layer
{
public:
	JumpLayer();
	JumpLayer(int i);
	~JumpLayer();
	static JumpLayer * createJumpLayer(int i);
	bool init();
	CREATE_FUNC(JumpLayer);

	//Screen
	Size screenSize;

	//Physics
	PhysicsWorld *physicsWorld;
	void SetPhysicsWorld(PhysicsWorld *world);

	//Ninja
	Ninja_D* ninja;

	//Pillar
	int randomName;
	Pillar *pillar;
	std::list< Pillar* > listPillar;
	std::list< Pillar* >::iterator firstPillar;
	Point firstSpawnPoint;
	void UpdatePillar();
	void SpawnPillarWithPos(Point pos);
	void MovePillar(float duration);
	void StopPillar();
	
	//Score
	Label * scoreText;
};

#endif
