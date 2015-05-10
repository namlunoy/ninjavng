#ifndef _BACKGROUND_
#define _BACKGROUND_
#include "cocos2d.h"

class Background : public cocos2d::Layer
{
public:
	Background();
	Background(int i);
	~Background();
	//Sprite * background;
	static Background * createBackground(int i);
	bool init();
	CREATE_FUNC(Background);
};

#endif