#ifndef UTILITY_DEFINITION_H_
#define UTILITY_DEFINITION_H_

#define DISTANCE_SPAWN_MAX 280
#define DISTANCE_SPAWN_MIN 115

#define PILLAR_COLLISION 0x000001
#define NINJA_COLLISION 0x000002
#define WALL_COLLISION 0x000003
#define GROUND_COLLISION 0x000004
#define SPRING_COLLISION 0x000005
#define SCORE_COLLISION 0x000006

#include "cocos2d.h"
USING_NS_CC;

class Definition {
public:
	Definition();
	virtual ~Definition();
	Point * buttonStart;
};

#endif
