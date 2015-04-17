/*
 * Definition.h
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#ifndef UTILITY_DEFINITION_H_
#define UTILITY_DEFINITION_H_

#define SPAWN_COLUMN_FREQUENCY_MAX 0.01
#define SPAWN_COLUMN_FREQUENCY_MIN 0.005

#define DISTANCE_MAX 2.0
#define DISTANCE_MIN 0.5

#define DISTANCE_SPAWN_MAX 380
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
