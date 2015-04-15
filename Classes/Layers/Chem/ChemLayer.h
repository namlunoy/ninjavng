/*
 * ChemLayer.h
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#ifndef LAYERS_CHEM_CHEMLAYER_H_
#define LAYERS_CHEM_CHEMLAYER_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Scenes/HelloWorldScene.h"

USING_NS_CC;
using namespace ui;

class ChemLayer : public Layer {
public:
	CREATE_FUNC(ChemLayer);
	bool init();

	ChemLayer();
	virtual ~ChemLayer();
};

#endif /* LAYERS_CHEM_CHEMLAYER_H_ */
