/*
 * Item.h
 *
 *  Created on: May 14, 2015
 *      Author: conghoang
 */

#ifndef MODELS_PHITIEU_ITEM_H_
#define MODELS_PHITIEU_ITEM_H_

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class Item : public Node {
private:
	Sprite* _sprite;
public:
	static Item* create(int type);
	static Sprite* getHeart(int stt);
	bool onContact(PhysicsContact& contact);
	Item(int type);
	virtual ~Item();
};

#endif /* MODELS_PHITIEU_ITEM_H_ */
