#include "NinjaModel.h"


NinjaModel::NinjaModel(){
	log("NinjaModel::NinjaModel()");
	setPhysic(1.0f, 0.1f, 0, 0);
	force_Y = 1000.0f;
}

NinjaModel::~NinjaModel(){}

void NinjaModel::setPhysic(float mass, float density, float restitution, float friction)
{
	this->mass = mass;
	this->density = density;
	this->restitution = restitution;
	this->friction = friction;
}