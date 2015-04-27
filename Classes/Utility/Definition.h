/*
 * Definition.h
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#ifndef UTILITY_DEFINITION_H_
#define UTILITY_DEFINITION_H_

#define DISTANCE_SPAWN_MAX 300
#define DISTANCE_SPAWN_MIN 120

#define PILLAR_COLLISION 0x000001
#define NINJA_COLLISION 0x000002
#define WALL_COLLISION 0x000003

class Definition {
public:
	Definition();
	virtual ~Definition();
};

#endif /* UTILITY_DEFINITION_H_ */
