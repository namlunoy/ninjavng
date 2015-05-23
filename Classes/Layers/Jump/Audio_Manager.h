#ifndef _Audio_Manager_
#define _Audio_Manager_
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

class Audio_Manager : public Layer
{
public:
	Audio_Manager();
	~Audio_Manager();
	bool init();
	static Audio_Manager * createAudioLayer();
};

#endif