#include "cocos2d.h"
#include "Giun_Dat.h"
#include "Utility/Config.h"
using namespace std;
Giun_Dat::Giun_Dat(){}
Giun_Dat::~Giun_Dat(){}

Giun_Dat* Giun_Dat::Tao_Giun_Dat(string _File_Name)
{
	Giun_Dat* Con_Giun = new Giun_Dat();
	Con_Giun->init(_File_Name);
	Con_Giun->autorelease();
	return Con_Giun;
}

bool Giun_Dat::init(string _File_Name)
{
	_Sprite = Sprite::create(_File_Name);
	_Sprite->setScale(0.48f, 0.48f);
	this->addChild(_Sprite);
	Body_Giun = PhysicsBody::createBox(_Sprite->getBoundingBox().size);
	Body_Giun->setDynamic(true);
	Body_Giun->setGravityEnable(false);
	Body_Giun->setContactTestBitmask(1);
	Body_Giun->setCollisionBitmask(1);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setPhysicsBody(Body_Giun); this->setTag(2);
	return true;
}

void Giun_Dat::Quet_Dat(float Dich_X)
{
	auto Toi_Dich = MoveBy::create(0.1f, Vec2(Dich_X, 0));
	this->runAction(RepeatForever::create(Toi_Dich));
	log("Quet_Dat()");
}
