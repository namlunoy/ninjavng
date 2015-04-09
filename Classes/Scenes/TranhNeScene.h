/*
 * TranhNeScene.h
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#ifndef SCENES_TRANHNESCENE_H_
#define SCENES_TRANHNESCENE_H_

#include "cocos2d.h"
#include "Layers/TranhNe/TranhNeLayer.h"

USING_NS_CC;

class TranhNeScene {
public:
	static Scene* createScene();

	TranhNeScene();
	virtual ~TranhNeScene();
};

#endif /* SCENES_TRANHNESCENE_H_ */
