#ifndef _PhiTieuHUDLayer_
#define _PhiTieuHUDLayer_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Utility/Config.h"
#include "Utility/XHelper.h"
#include "PhiTieuLayer.h"

USING_NS_CC;
using namespace ui;

class PhiTieuHUDLayer : public Layer
{
private:
	Button* bt_jump;
	PhiTieuLayer* _phiTieuLayer;

public:
	PhiTieuHUDLayer();
	~PhiTieuHUDLayer();
	void setPhiTieuLayer(PhiTieuLayer* layer);
	bool init();
	float theScale;
	CREATE_FUNC(PhiTieuHUDLayer);

	bool touchScreen(Touch* t, Event* e);
	void touchScreen_end(Touch* t, Event* e);
};
#endif
