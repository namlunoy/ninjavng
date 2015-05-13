#ifndef _BANTAO_LAYER_
#define _BANTAO_LAYER_
#include "Utility/XHelper.h"
#include "cocos2d.h"
#include "Utility/Config.h"
#include "Models/BanSung/BanTao_Target.h"


USING_NS_CC;

class BanTao_Layer : public Layer
{
public:
	BanTao_Layer();
	~BanTao_Layer();
	bool init();
	CREATE_FUNC(BanTao_Layer);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void onStart(float speed);
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event, BanTao_Target *target);

	void commentPut(string name);
	void appleSprite();
	void headSprite();
	void checkLive();

	void restart();


private:
	
	void updateScore();
};
#endif




//////////////////////////////////////////////////////////////////////////
//comment: 10
//apple: 11
//btn start: 12
//target 13
//kid :15
//paticle: 14


