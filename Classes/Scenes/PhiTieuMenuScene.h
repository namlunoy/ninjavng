/*
 * PhiTieuMenuScene.h
 *
 *  Created on: Apr 22, 2015
 *      Author: conghoang
 */

#ifndef SCENES_PHITIEUMENUSCENE_H_
#define SCENES_PHITIEUMENUSCENE_H_

#include "cocos2d.h"



USING_NS_CC;


class PhiTieuMenuScene : public Scene {
public:
	PhiTieuMenuScene();
	virtual ~PhiTieuMenuScene();
	static Scene* createScene();
	static int SelectedLevel;
};

#endif /* SCENES_PHITIEUMENUSCENE_H_ */
