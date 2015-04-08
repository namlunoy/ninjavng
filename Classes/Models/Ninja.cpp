﻿#include "Ninja.h"
#include "Utility/Definition.h"
#include "Utility/Config.h"

Ninja::Ninja(){}
Ninja::~Ninja(){}

Ninja* Ninja::create(string fileName)
{
	Ninja* ninja = new Ninja();
	if (ninja && ninja->init(fileName))
		ninja->autorelease();
	else CC_SAFE_DELETE(ninja);
	return ninja;
}

bool Ninja::init(string fileName)
{
	if (!Node::init())
		return false;



	//Khởi tạo sprite chính
	_sprite = Sprite::create(fileName);
	_sprite->setPosition(0, 0);
	this->addChild(_sprite);

	//Thêm body
	_body = PhysicsBody::createBox(_sprite->getBoundingBox().size,
		PhysicsMaterial(_ninjaModel.density,_ninjaModel.restitution,_ninjaModel.friction));
	_body->setMass(_ninjaModel.mass);

	this->setPhysicsBody(_body);

	return true;
}

void Ninja::runAnimation(string name, int count, float time, bool isRepeat)
{
	XHelper::runAnimation(name, count, time, true, this->_sprite);
}

//-------------------- Công -------------------------

void Ninja::jump()
{
	log("Ninja::jump()");
	_body->applyForce(Vec2(0, _ninjaModel.force_Y));
	//_body->resetForces();
	log("Velocity: %f",_body->getVelocity().y);
}

void Ninja::runAnimation_DungYen()
{
	runAnimation("DungYen", 2, 0.5f, true);
}

void Ninja::runAnimation_Nhay()
{
	//runAnimation("ninja_nhay", 2, 0.5f, true);
}



