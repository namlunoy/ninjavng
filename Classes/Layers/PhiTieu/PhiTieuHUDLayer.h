#ifndef _PhiTieuHUDLayer_
#define _PhiTieuHUDLayer_

#include "cocos2d.h"
#include "ui/CocosGUI.h"

#include "Utility/Config.h"
#include "Utility/XHelper.h"

#include "Scenes/HelloWorldScene.h"
#include "PhiTieuLayer.h"
USING_NS_CC;
using namespace ui;

class PhiTieuLayer;

class PhiTieuHUDLayer : public Layer
{
private:
	Button* bt_jump;
	Vector<Sprite*> hearts;
	Sprite* _power;
	PhiTieuLayer* _phiTieuLayer;
	Label* txt_score;
	int score;
public:
	//------  Các hàm khởi tạo -------
	static PhiTieuHUDLayer* Instance;
	PhiTieuHUDLayer();
	~PhiTieuHUDLayer();
	CREATE_FUNC(PhiTieuHUDLayer);
	bool init();
	void setPhiTieuLayer(PhiTieuLayer* p);

	bool touch_PhongTieu(Touch* t, Event* e);
	void click_Jump(Ref* sender, TouchEventType touchType);
	void matMau();
	void updatePower();
	void gameOver();
	void tangDiem();
};
#endif
