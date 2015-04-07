#ifndef _GAMEPLAY_LAYER_
#define _GAMEPLAY_LAYER_
#include "cocos2d.h"

class GamePlayLayer : public cocos2d::Layer
{
public:
	GamePlayLayer();
	~GamePlayLayer();
	bool init();
	//CREATE_FUNC(GamePlayLayer);
private:
	void start();
	void update();
	/*void removeAndClean(Node *node);*/

};

#endif //_GAMEPLAY_LAYER_