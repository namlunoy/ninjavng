#include "Nen.h"
#include "Utility/Config.h"
Nen::Nen(){}
Nen::~Nen(){}
Nen* Nen::Tao_Nen()
{
	Nen* Mat_Dat = new Nen(); Mat_Dat->init();
	Mat_Dat->autorelease();
	return Mat_Dat;
}

bool Nen::init()
{
	PhysicsBody* Body_Nen = PhysicsBody::createBox(Size(Config::screenSize.width - 20, 2));
	Body_Nen->setGravityEnable(false);
	Body_Nen->setDynamic(false);
	Body_Nen->setCollisionBitmask(1);
	Body_Nen->setContactTestBitmask(1);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE); this->setPhysicsBody(Body_Nen); this->setTag(0);
	return false;
}