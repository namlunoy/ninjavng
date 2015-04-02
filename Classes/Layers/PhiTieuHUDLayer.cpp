#include "PhiTieuHUDLayer.h"


PhiTieuHUDLayer::PhiTieuHUDLayer(){}
PhiTieuHUDLayer::~PhiTieuHUDLayer(){}

bool PhiTieuHUDLayer::init()
{
	if (!Layer::init())
		return false;
	//Lấy thông số scale
	theScale = Config::getScale("cong_background.jpg");

	this->setContentSize(Size(1360, 768));
	this->setScale(theScale);



	//Khởi tạo Button jump
	bt_jump = Button::create("bt_jump_1.png", "bt_jump_2.png", "bt_jump_2.png");
	bt_jump->setPosition(Vec2(0,0));
//	bt_jump->setScale(theScale);
	this->addChild(bt_jump);
	//log("Content size: %f", bt_jump->getBoundingBox().size.height);
	XHelper::Log(bt_jump, "Button");


	int a = 1;
	return true;
}
