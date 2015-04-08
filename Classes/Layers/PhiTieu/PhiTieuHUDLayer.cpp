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
	//	this->setScale(theScale);



	//Khởi tạo Button jump
	bt_jump = Button::create("bt_jump_1.png", "bt_jump_2.png", "bt_jump_2.png");
	bt_jump->setAnchorPoint(Vec2(0, 0));
	bt_jump->setPosition(Vec2(0, 0));
	bt_jump->setScale(theScale);
	bt_jump->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
		{
			log("click_Jump");
			_phiTieuLayer->ninja->jump();
		}
		}
	});
	this->addChild(bt_jump);

	//touch event : Phongs tieeu
	auto _touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(PhiTieuHUDLayer::click_PhongTieu, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);


	return true;
}



void PhiTieuHUDLayer::setPhiTieuLayer(PhiTieuLayer* layer)
{
	_phiTieuLayer = layer;
}
bool PhiTieuHUDLayer::click_PhongTieu(Touch* t, Event* e)
{
	log("click_PhongTieu");
	_phiTieuLayer->PhongTieu(t->getLocation());
	return true;
}

void PhiTieuHUDLayer::click_Jump(Ref* pSender, ui::Widget::TouchEventType eEventType)
{



}