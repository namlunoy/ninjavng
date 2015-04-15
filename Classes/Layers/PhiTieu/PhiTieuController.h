/*
 * PhiTieuController.h
 *
 *  Created on: Apr 15, 2015
 *      Author: conghoang
 */

#ifndef LAYERS_PHITIEU_PHITIEUCONTROLLER_H_
#define LAYERS_PHITIEU_PHITIEUCONTROLLER_H_

#include "cocos2d.h"
#include "PhiTieuHUDLayer.h"
#include "PhiTieuLayer.h"

USING_NS_CC;

//Sigleton Parttern
class PhiTieuController {
private:
	PhiTieuController();
	static PhiTieuController* _instance;
	PhiTieuHUDLayer* _hudLayer;
	PhiTieuLayer* _mainLayer;


public:
	static PhiTieuController* getInstance();
	void setupLayers(PhiTieuHUDLayer* hudLayer,PhiTieuLayer* mainLayer);
	virtual ~PhiTieuController();

	void Jump();
	void PhongTieu(Vec2 dest);
};

#endif /* LAYERS_PHITIEU_PHITIEUCONTROLLER_H_ */
