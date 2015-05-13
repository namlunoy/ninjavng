#include "cocos2d.h"
#include "Ninja_Tranh.h"
#include "Utility/Config.h"
using namespace std;
Ninja_Tranh::Ninja_Tranh(){}
Ninja_Tranh::~Ninja_Tranh(){}

Ninja_Tranh* Ninja_Tranh::Tao_Ninja_Tranh(string _File_Name)
{
	Ninja_Tranh* Ninja = new Ninja_Tranh();
	Ninja->init(_File_Name);
	Ninja->autorelease();
	return Ninja;
}

bool Ninja_Tranh::init(string _File_Name)
{
	So_Mang = 10;
	_Sprite = Sprite::create(_File_Name);
	_Sprite->setScale(0.1f, 0.1f);
	this->addChild(_Sprite);
	Body_Ninja = PhysicsBody::createBox(_Sprite->getBoundingBox().size);
	Body_Ninja->setGravityEnable(false);
	Body_Ninja->setDynamic(true);
	Body_Ninja->setCollisionBitmask(1);
	Body_Ninja->setContactTestBitmask(1);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE); this->setTag(1);
	this->setPhysicsBody(Body_Ninja);
	return false;
}

void Ninja_Tranh::Di_Chuyen(float Dich_X, float Dich_Y)
{
	auto Toi_Dich = MoveBy::create(0, Vec2(Dich_X, Dich_Y));
	this->runAction(Toi_Dich);
	log("Di_Chuyen()");
}

void Ninja_Tranh::Nhay(float Dich_X, float Dich_Y)
{
	auto Nhay_Dich = JumpTo::create(1, Vec2(Dich_X, Dich_Y), 100, 1);
	this->runAction(Nhay_Dich);
	log("Nhay()");
}