/*
 * BanSungScene.h
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#ifndef SCENES_BANSUNGSCENE_H_
#define SCENES_BANSUNGSCENE_H_

#include "cocos2d.h"
#include "Layers/BanSung/BanSungLayer.h"

USING_NS_CC;

class BanSungScene {
public:
	static Scene* createScene();
	BanSungScene();
	virtual ~BanSungScene();
};

#endif /* SCENES_BANSUNGSCENE_H_ */
