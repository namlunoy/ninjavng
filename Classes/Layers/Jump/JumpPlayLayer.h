#ifndef _JUMPPLAY_LAYER_
#define _JUMPPLAY_LAYER_
#include "cocos2d.h"
#include "Models/Jump/Ninja_D.h"
#include "Models/Jump/Pillar.h"
#include "Layers/Jump/JumpLayer.h"
USING_NS_CC;

class JumpPlayLayer : public Layer
{
private:
	JumpLayer *jumpLayer;
public:
	JumpPlayLayer();
	~JumpPlayLayer();
	bool init();
	CREATE_FUNC(JumpPlayLayer);
	void SetJumpLayer(JumpLayer *jumplayer);

	//Xử lý Touch
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	
	//Count
	float timeTouch;
	bool tinh;
	float Clamp(float a);

	//Xử lý va chạm
	bool onContactBegin(PhysicsContact &contact);

	//Schedule
	void MovePillar(float dt);
	void update(float delta);

	//Score + GameOver
	int score;
	/*UserDefault * def;
	int highScoreUser;*/
	Label* xScore;
	void ShowXScore(int diem);
	void RemoveXScore();
	void ShowScoreBoard(int diem);
};

#endif