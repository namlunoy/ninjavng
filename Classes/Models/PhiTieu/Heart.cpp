/*
 * Heart.cpp
 *
 *  Created on: May 14, 2015
 *      Author: conghoang
 */

#include "Heart.h"
#include "Utility/Tags.h"
#include "Utility/Config.h"

Heart::Heart() {
	//Khởi tạo hình dáng và các thuộc tính
	_sprite = Sprite::create("heart.png");
	_sprite->setScale(0.18f);
	this->addChild(_sprite);

	PhysicsBody* body = PhysicsBody::createBox(_sprite->getBoundingBox().size,PhysicsMaterial(1, 0, 0));
	body->setTag(Tags::HEART);
	body->setDynamic(true);
	body->setGravityEnable(false);
	body->setContactTestBitmask(true);
	body->setCollisionBitmask(true);


	//contact listner
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Heart::onContact, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
	this->setPhysicsBody(body);


	//Cho nó di chuyển
	auto quay = RepeatForever::create(RotateBy::create(3.0f,Vec3(0,1,0)));
	auto move = RepeatForever::create(MoveBy::create(3.0f,Vec2(-1,0)));
	this->runAction(Spawn::createWithTwoActions(quay,move));
	//this->runAction(move);
}

Heart* Heart::create() {
	Heart* h = new Heart();
	h->setPosition(Config::screenSize.width, Config::screenSize.height);
	return h;
}

Sprite* Heart::getHeart(int stt) {
	stt--;
	auto h = Sprite::create("heart.png");
	h->setScale(0.2f);
	h->setPosition(Vec2(30 + h->getBoundingBox().size.width * stt, Config::screenSize.height - 50));
	return h;
}

Heart::~Heart() {
}

bool Heart::onContact(PhysicsContact& contact) {
	auto a = contact.getShapeA()->getBody();
	auto b = contact.getShapeB()->getBody();


	//----------------   Va chạm vơi Enemy   ---------
	if(a != NULL && b != NULL && a->getNode() != NULL && b->getNode() != NULL)
	{

		if((a->getTag() == Tags::TARGET && b->getTag() == Tags::HEART)
						|| (a->getTag() == Tags::HEART && b->getTag() == Tags::TARGET))
			{
					log("HEART::onContactBegin : TARGET vs HEART");
					auto h = a->getTag() == Tags::HEART ? a : b;
					h->getNode()->removeFromParent();
			}
	}

	return false;
}
