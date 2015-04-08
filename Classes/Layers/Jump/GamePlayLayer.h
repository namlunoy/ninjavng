#ifndef _GAMEPLAY_LAYER_
#define _GAMEPLAY_LAYER_
#include "cocos2d.h"
#include "Models/Jump/Ninja_D.h"
#include "Models/Jump/Pillar.h"
#include "Layers/Jump/JumpLayer.h"

class GamePlayLayer : public cocos2d::Layer
{
public:
	GamePlayLayer();
	~GamePlayLayer();
	bool init();
	//CREATE_FUNC(GamePlayLayer);
	Ninja_D *ninja;
	Pillar *pillar;
	virtual void update();

	//Xử lý Touch
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);

};

#endif //_GAMEPLAY_LAYER_