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
	bt_jump->setPosition(Vec2(0,0));
	bt_jump->setScale(theScale);
	this->addChild(bt_jump);


	//touch event
	auto _touchListener = EventListenerTouchOneByOne::create();

	_touchListener->onTouchBegan = CC_CALLBACK_2(PhiTieuHUDLayer::touchScreen, this);
	_touchListener->onTouchEnded = CC_CALLBACK_2(PhiTieuHUDLayer::touchScreen_end, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
	return true;
}

bool PhiTieuHUDLayer::touchScreen(Touch* t, Event* e)
{
	log("%f - %f", t->getLocation().x, t->getLocation().y);
	_phiTieuLayer->ninja->jump();
	return true;
}
void PhiTieuHUDLayer::touchScreen_end(Touch* t, Event* e)
{
	log("end");
	_phiTieuLayer->ninja->getPhysicsBody()->resetForces();
//	return true;
}

void PhiTieuHUDLayer::setPhiTieuLayer(PhiTieuLayer* layer)
{
	_phiTieuLayer = layer;
}