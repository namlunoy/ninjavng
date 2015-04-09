/*
 * ChemScene.h
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#ifndef SCENES_CHEMSCENE_H_
#define SCENES_CHEMSCENE_H_

#include "cocos2d.h"
#include "Layers/Chem/ChemLayer.h"

USING_NS_CC;

class ChemScene {
public:
	static Scene* createScene();
	ChemScene();
	virtual ~ChemScene();
};

#endif /* SCENES_CHEMSCENE_H_ */
