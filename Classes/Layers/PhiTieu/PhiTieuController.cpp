/*
 * PhiTieuController.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: conghoang
 */

#include "PhiTieuController.h"

PhiTieuController::PhiTieuController() {
}PhiTieuController::~PhiTieuController() {
}

void PhiTieuController::setupLayers(PhiTieuHUDLayer* hudLayer,
		PhiTieuLayer* mainLayer) {
	this->_hudLayer = hudLayer;
	this->_mainLayer = mainLayer;
}


PhiTieuController* PhiTieuController::_instance = NULL;
PhiTieuController* PhiTieuController::getInstance() {
	if(_instance == NULL)
		_instance = new PhiTieuController();
	return _instance;
}

void PhiTieuController::Jump() {
	_mainLayer->Jump();
}

void PhiTieuController::PhongTieu(Vec2 dest) {
	_mainLayer->PhongTieu(dest);
}
