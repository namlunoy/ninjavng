/*
 * TranhNeLayer.h
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#ifndef LAYERS_TRANHNE_TRANHNELAYER_H_
#define LAYERS_TRANHNE_TRANHNELAYER_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Scenes/HelloWorldScene.h"

USING_NS_CC;
using namespace ui;

class TranhNeLayer: public Layer {
public:
	CREATE_FUNC(TranhNeLayer);
	bool init();

	TranhNeLayer();
	virtual ~TranhNeLayer();
};

#endif /* LAYERS_TRANHNE_TRANHNELAYER_H_ */
