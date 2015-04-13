#ifndef _PILLAR_H_
#define _PILLAR_H_
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
 
class Pillar: public Sprite
{
public:
	Pillar();
	Pillar(Sprite *pillar, float heightRandom, Point position, PhysicsBody *bodyPillar);
	Sprite *pillar;
	float heightRandom;
	Point position;
	PhysicsBody *bodyPillar;
	
	//Get, Set
	void SetPillar(Sprite *sprite);
	Sprite* GetPillar();
	void SetHeightRandom(float height);
	float GetHeightRandom();
	void SetPosition(Point position);
	Point GetPosition();
	void SetPhysicsBody(PhysicsBody *physicsBody);
	PhysicsBody* GetPhysicsBody();

	//void SpawnPillar(Layer *layer, Point spawnPosition, int order);
	void SpawnPillar(Layer *layer);
	void MovePillar();
	void StopPillar();
private:
	Size screenSize;
	Point rootPoint;
};

#endif _PILLAR_H_
