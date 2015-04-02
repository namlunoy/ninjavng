#ifndef _CONFIG_
#define _CONFIG_

#include "cocos2d.h"
#include <cmath>
#include <iostream>

USING_NS_CC;
using namespace std;


class Config
{
public:
	static Size screenSize;
	static Vec2 centerPoint;
	//Hàm này để scale lại background cho phù hợp với màn hình
	static float getScale(Node* p);

	//Lấy theo tên file background
	static float getScale(string backgroundFileName);
	Config();
	~Config();
};

#endif