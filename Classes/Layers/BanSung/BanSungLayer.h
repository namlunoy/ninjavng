/*
 * BanSungLayer.h
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#ifndef LAYERS_BANSUNG_BANSUNGLAYER_H_
#define LAYERS_BANSUNG_BANSUNGLAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class BanSungLayer : public Layer {
public:
	CREATE_FUNC(BanSungLayer);
	bool init();
	BanSungLayer();
	virtual ~BanSungLayer();
};

#endif /* LAYERS_BANSUNG_BANSUNGLAYER_H_ */
