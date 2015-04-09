#ifndef _PhiTieuHUDLayer_
#define _PhiTieuHUDLayer_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Utility/Config.h"
#include "Utility/XHelper.h"
#include "PhiTieuLayer.h"
#include "Scenes/HelloWorldScene.h"

USING_NS_CC;
using namespace ui;

class PhiTieuHUDLayer : public Layer
{
private:
	Button* bt_jump;
	PhiTieuLayer* _phiTieuLayer;

public:
	//------  Các hàm khởi tạo -------
	PhiTieuHUDLayer();
	~PhiTieuHUDLayer();
	CREATE_FUNC(PhiTieuHUDLayer);
	bool init();
	void setPhiTieuLayer(PhiTieuLayer* layer);



	bool touch_PhongTieu(Touch* t, Event* e);
	void click_Jump(Ref* sender, TouchEventType touchType);
};
#endif
