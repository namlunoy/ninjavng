/*
 * Heart.h
 *
 *  Created on: May 14, 2015
 *      Author: conghoang
 */

#ifndef MODELS_PHITIEU_HEART_H_
#define MODELS_PHITIEU_HEART_H_

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class Heart : public Node {
private:
	Sprite* _sprite;
public:
	static Heart* create();
	Heart();
	virtual ~Heart();
};

#endif /* MODELS_PHITIEU_HEART_H_ */
