#ifndef _PHITIEU_LAYER_
#define _PHITIEU_LAYER_

#include "cocos2d.h"
#include "Utility/Config.h"
#include "Models/Shuriken.h"
#include "Models/Ninja.h"

USING_NS_CC;

class PhiTieuLayer : public Layer
{
private:
	Sprite* _background;
public:
	Ninja* ninja;
	PhiTieuLayer();
	~PhiTieuLayer();
	bool init();
	//Chỉ số scale lấy theo background
	float theScale;
	
	CREATE_FUNC(PhiTieuLayer);


	bool touchScreen(Touch* t, Event* e);


	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);

};
#endif

