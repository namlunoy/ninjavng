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
	static float soLuong;
	//minPower là lượng mana tối thiểu để có thể phóng tiêu: 1/số lượng
	static float minPower;
	//Tốc độ phục hồi của mana: o.o1f ...
	static float up;
public:
	static void nangCap();
	Power();
	virtual ~Power();
	bool init();
	void updatePower();
	void setupByLevel();
	bool fire();
	static Power* createPower(int lv);
};

#endif /* MODELS_PHITIEU_POWER_H_ */
