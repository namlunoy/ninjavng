#ifndef _BACKGROUND_
#define _BACKGROUND_
#include "cocos2d.h"

class Background : public cocos2d::Layer
{
public:
	Background();
	~Background();
	bool init();
	CREATE_FUNC(Background);
};

#endif //_BACKGROUND_