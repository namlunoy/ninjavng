/*
 * ChemLayer.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#include "ChemLayer.h"

ChemLayer::ChemLayer() {
}
ChemLayer::~ChemLayer() {
}

bool ChemLayer::init() {
	auto label = LabelTTF::create("Chem","Arial",30);
	label->setPosition(Vec2(100,100));
	this->addChild(label);
	return true;
}

