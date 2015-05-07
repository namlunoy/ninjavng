/*
 * Power.h
 *
 *  Created on: May 7, 2015
 *      Author: conghoang
 */

#ifndef MODELS_PHITIEU_POWER_H_
#define MODELS_PHITIEU_POWER_H_

#include "cocos2d.h"

USING_NS_CC;

class Power : public Node {
private:
	Sprite* _power;
	int level;
	float minPower;
	float up;
public:
	Power();
	virtual ~Power();
	bool init();
	void updatePower();
	void setupByLevel();
	bool fire();
	static Power* createPower(int lv);
};

#endif /* MODELS_PHITIEU_POWER_H_ */
