#ifndef _APPLE_
#define _APPLE_

#include "cocos2d.h"
#include <iostream>

USING_NS_CC;
using namespace std;

class BanTao_Apple : public Node
{

private:
	Sprite* _sprite;

public:

	BanTao_Apple();
	~BanTao_Apple();
	bool init(string fileName);
	static BanTao_Apple* create(string fileName);
	
	void setScaleApple(float scale);
	void setPotionApple(Vec2 potision);
	
};
#endif