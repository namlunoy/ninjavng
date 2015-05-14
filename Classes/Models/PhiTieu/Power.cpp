/*
 * Power.cpp
 *
 *  Created on: May 7, 2015
 *      Author: conghoang
 */

#include "Power.h"
#include "Models/PhiTieu/Ninja.h"
#include "Scenes/PhiTieuScene.h"

Power::Power() {}
Power::~Power() {}
float Power::soLuong = 8.0f;
float Power::minPower = 0.1f;
float Power::up = 0.01f;

bool Power::init() {

	setupByLevel();

	//------------- Power -------------------
	_power = Sprite::create("power.png");
	_power->setAnchorPoint(Vec2(0, 1));
	this->addChild(_power);

	Sprite* _power2 = Sprite::create("power.png");
	_power2->setOpacity(160);
	_power2->setAnchorPoint(Vec2(0, 1));
	this->addChild(_power2);

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

void Power::setupByLevel() {
	minPower = 1.0f / soLuong;
	up = 0.01f;
}
void Power::nangCap() {
	soLuong++;
	minPower = 1.0f / soLuong;
	//up += 0.006f;
}

bool Power::fire() {
	log(Ninja::Instance->isAlive);
	if (_power != nullptr && Ninja::Instance->isAlive)
		if (_power->getScaleX() >= minPower) {
			float s = _power->getScaleX() - minPower;
			_power->setScaleX(s);
			return true;
		}
	return false;
}

Power* Power::createPower(int lv) {
	Power* p = new Power();
	p->init();
	p->autorelease();
	return p;
}
