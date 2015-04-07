﻿#ifndef _PILLAR_H_
#define _PILLAR_H_
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
 
class Pillar: public Sprite
{
public:
	Pillar();
	void SpawnPillar(Layer *layer);
	void SpawnPillarFirst(Layer *layer);
	void MovePillar(Sprite *pillar);
	void StopPillar();

private:
	Size screenSize;
	Point rootPoint;
};

#endif _PILLAR_H_