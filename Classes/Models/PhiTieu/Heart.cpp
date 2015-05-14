/*
 * Heart.cpp
 *
 *  Created on: May 14, 2015
 *      Author: conghoang
 */

#include "Heart.h"
#include "Utility/Tags.h"

Heart::Heart() {
	//Khởi tạo hình dáng và các thuộc tính
	_sprite = Sprite::create("heart.png");
	_sprite->setScale(0.18f);

	PhysicsBody* body = PhysicsBody::createBox(Size(5, 700),PhysicsMaterial(1, 0, 0));
	body->setTag(Tags::HEART);
	body->setDynamic(true);
	body->setGravityEnable(false);
	body->setContactTestBitmask(true);
	body->setCollisionBitmask(true);
	_sprite->setPhysicsBody(body);
	this->addChild(_sprite);

	//Cho nó di chuyển
	auto quay = RepeatForever::create(RotateBy::create(3.0f,Vec3(0,1,0)));
	auto move = RepeatForever::create(MoveBy::create(3.0f,Vec2(-1,0)));
	this->runAction(Spawn::createWithTwoActions(quay,move));

}

Heart* Heart::create() {
	Heart* h = new Heart();
	return h;
}

Heart::~Heart() {}

