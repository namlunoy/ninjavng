/*
 * Power.cpp
 *
 *  Created on: May 7, 2015
 *      Author: conghoang
 */

#include "Power.h"
#include "Models/PhiTieu/Ninja.h"

Power::Power() {
}

Power::~Power() {
}

bool Power::init() {

	setupByLevel(level);

	//------------- Power -------------------
	_power = Sprite::create("power.png");
	_power->setAnchorPoint(Vec2(0, 1));
	this->addChild(_power);

	//timer update
	Node* timer = Node::create();
	CallFunc* updatePower = CallFunc::create(CC_CALLBACK_0(Power::updatePower, this));
	DelayTime* delay = DelayTime::create(0.05f);
	timer->runAction(RepeatForever::create(Sequence::createWithTwoActions(delay, updatePower)));
	this->addChild(timer);

	return true;
}

void Power::updatePower() {
	float s = _power->getScaleX();
	s += up;
	if (s <= 1 && Ninja::Instance->isAlive) {
		_power->setScaleX(s);
	}
}

void Power::setupByLevel(int lv) {
	switch (lv) {
	case 1:
		minPower = 1.0f / 5.0f;
		up = 0.01f;
		break;
	case 2:
		minPower = 1.0f / 5.0f;
		up = 0.01f;
		break;
	case 3:
		minPower = 1.0f / 5.0f;
		up = 0.01f;
		break;
	case 4:
		minPower = 1.0f / 5.0f;
		up = 0.01f;
		break;
	case 5:
		minPower = 1.0f / 5.0f;
		up = 0.01f;
		break;
	}
	log("up = %f, minPow = %f", up, minPower);
}

bool Power::fire() {
	if (_power->getScaleX() >= minPower) {
		float s = _power->getScaleX() - minPower;
		_power->setScaleX(s);
		return true;
	} else {
		return false;
	}
}

Power* Power::createPower(int lv) {
	Power* p = new Power();
	p->init();
	p->level = lv;
	p->autorelease();
	return p;
}
