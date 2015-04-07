#include "NinjaModel.h"


NinjaModel::NinjaModel(){
	log("NinjaModel::NinjaModel()");
	setPhysic(3.0f, 1.0f, 0, 0);
	force_Y = 500.0f;
}

NinjaModel::~NinjaModel(){}

void NinjaModel::setPhysic(float mass, float density, float restitution, float friction)
{
	this->mass = mass;
	this->density = density;
	this->restitution = restitution;
	this->friction = friction;
}