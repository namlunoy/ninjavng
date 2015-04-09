/*
 * BanSungLayer.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#include "BanSungLayer.h"

BanSungLayer::BanSungLayer() {}

BanSungLayer::~BanSungLayer() {}

bool BanSungLayer::init()
{
	auto label = LabelTTF::create("Ban Sung","Arial",30);
	label->setPosition(Vec2(100,100));
	this->addChild(label);
	return true;
}

