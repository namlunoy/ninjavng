/*
 * TranhNeLayer.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#include "TranhNeLayer.h"

TranhNeLayer::TranhNeLayer() {
}
TranhNeLayer::~TranhNeLayer() {
}

bool TranhNeLayer::init()
{
	auto label = LabelTTF::create("Tranh Ne","Arial",30);
	label->setPosition(Vec2(100,100));
	this->addChild(label);
	return true;
}

