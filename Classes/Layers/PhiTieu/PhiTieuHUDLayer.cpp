#include "PhiTieuHUDLayer.h"

PhiTieuHUDLayer::PhiTieuHUDLayer() {
}
PhiTieuHUDLayer::~PhiTieuHUDLayer() {
}

bool PhiTieuHUDLayer::init() {
	if (!Layer::init())
		return false;

//------------------ Button jump  ---------------------
	bt_jump = Button::create("bt_jump_1.png", "bt_jump_2.png", "bt_jump_2.png");
	bt_jump->setAnchorPoint(Vec2(0, 0));
	bt_jump->setPosition(Vec2(0, 0));
	bt_jump->setScale(0.5f);
	bt_jump->addTouchEventListener(this,
			toucheventselector(PhiTieuHUDLayer::click_Jump));
	this->addChild(bt_jump);

	//-----------  touch event ------------
	auto _touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(
			PhiTieuHUDLayer::touch_PhongTieu, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener,
			this);

	return true;
}

bool PhiTieuHUDLayer::touch_PhongTieu(Touch* t, Event* e) {
	_phiTieuLayer->PhongTieu(t->getLocation());
	return true;
}

void PhiTieuHUDLayer::click_Jump(Ref* sender, TouchEventType touchType) {
	//Thực hiện nhảy
	if (touchType == TouchEventType::TOUCH_EVENT_BEGAN) {
		_phiTieuLayer->Jump();
	}
}

void PhiTieuHUDLayer::setPhiTieuLayer(PhiTieuLayer* layer) {
	_phiTieuLayer = layer;
}
