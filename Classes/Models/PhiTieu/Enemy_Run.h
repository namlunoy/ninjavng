#ifndef _Enemy_Run_
#define _Enemy_Run_

#include "cocos2d.h"

#include "Enemy.h"
#include "Utility/Config.h"
#include "Utility/XHelper.h"

USING_NS_CC;

class Enemy_Run : public Enemy
{

public:
	static Enemy_Run*  create();
	void setupAction() override;
	Enemy_Run();
	~Enemy_Run();
};

#endif
