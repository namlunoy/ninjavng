#include "cocos2d.h"
#include "Vat_Roi.h"
#include "Utility/Config.h"
using namespace std;
Vat_Roi::Vat_Roi(){}
Vat_Roi::~Vat_Roi(){}

Vat_Roi* Vat_Roi::Tao_Vat_Roi(string _File_Name)
{
	Vat_Roi* Vu_Khi = new Vat_Roi();
	Vu_Khi->init(_File_Name);
	Vu_Khi->autorelease();
	return Vu_Khi;
}

bool Vat_Roi::init(string _File_Name)
{
	_Sprite = Sprite::create(_File_Name); So_VR = 5;
	_Sprite->setScale(0.48f, 0.48f);
	this->addChild(_Sprite);
	Body_VR = PhysicsBody::createBox(_Sprite->getBoundingBox().size);
	Body_VR->setDynamic(true);
	Body_VR->setGravityEnable(false);
	Body_VR->setCollisionBitmask(1);
	Body_VR->setContactTestBitmask(1);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setPhysicsBody(Body_VR);
	return false;
}

void Vat_Roi::Roi(float Dich_Y)
{
	auto Toi_Dich = MoveBy::create(0.1f, Vec2(0, -Dich_Y));
	this->runAction(RepeatForever::create(Toi_Dich));
	log("Roi()");
}
