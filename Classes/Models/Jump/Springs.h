#ifndef _SPRINGS_
#define _SPRINGS_
#include "cocos2d.h"
USING_NS_CC;
 
class Springs: public Sprite
{
public:
	Sprite *spring;
	Springs(Sprite *spring);


};

#endif// _SPRINGS_
