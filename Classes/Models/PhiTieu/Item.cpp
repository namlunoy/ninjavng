/*
 * Heart.cpp
 *
 *  Created on: May 14, 2015
 *      Author: conghoang
 */

#include "Item.h"
#include "Utility/Tags.h"
#include "Utility/Config.h"

Item::Item(int type) {
	//Khởi tạo hình dáng và các thuộc tính
	if(type == Tags::HEART)
	{
		_sprite = Sprite::create("heart.png");
		_sprite->setScale(0.18f);
	}else{
		_sprite = Sprite::create("Shuriken.png");
		_sprite->setScale(0.12f);
	}


	this->addChild(_sprite);

	PhysicsBody* body = PhysicsBody::createBox(_sprite->getBoundingBox().size,PhysicsMaterial(1, 0, 0));
	body->setTag(type);
	body->setDynamic(true);
	body->setGravityEnable(false);
	body->setContactTestBitmask(true);
	body->setCollisionBitmask(true);


	//contact listner
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Item::onContact, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
	this->setPhysicsBody(body);



}

Item* Item::create(int type) {
	Item* h = new Item(type);
	h->setPosition(Config::screenSize.width + 50, Config::screenSize.height - 100);
	return h;
}

Sprite* Item::getHeart(int stt) {
	stt--;
	auto h = Sprite::create("heart.png");
	h->setScale(0.2f);
	h->setPosition(Vec2(30 + h->getBoundingBox().size.width * stt, Config::screenSize.height - 50));
	return h;
}

Item::~Item() {
}

bool Item::onContact(PhysicsContact& contact) {
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

	if(a != NULL && b != NULL && a->getNode() != NULL && b->getNode() != NULL)
	{
		if((a->getTag() == Tags::TARGET && b->getTag() == Tags::ITEM)
						|| (a->getTag() == Tags::ITEM && b->getTag() == Tags::TARGET))
			{
					log("HEART::onContactBegin : TARGET vs HEART");
					auto h = a->getTag() == Tags::ITEM ? a : b;
					h->getNode()->removeFromParent();
			}
	}

	return false;
}
