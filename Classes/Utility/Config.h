#ifndef _CONFIG_
#define _CONFIG_

#include "cocos2d.h"
#include <cmath>
#include <iostream>
#include <cmath>

USING_NS_CC;
using namespace std;

class Config {
private:
	static int getLow() {
		return 70;
	}
	static int getMiddle() {
		return screenSize.height / 2;
	}
	static int getHigh() {
		return screenSize.height - 50;
	}
public:
	Config();
	~Config();

	static float getScaleSize()
	{
		return min(screenSize.height/480,screenSize.width/800);
	}

	static Size screenSize;
	static Vec2 centerPoint;
	///Hàm này để scale lại background cho phù hợp với màn hình
	static float getScale(Node* p);

	///Lấy theo tên file background
	static float getScale(string backgroundFileName);

	static Vec2 getSpawnStart_low() {
		return Vec2(screenSize.width, getLow());
	}
	static Vec2 getSpawnStart_midle() {
		return Vec2(screenSize.width, getMiddle());
	}
	static Vec2 getSpawnStart_high() {
		return Vec2(screenSize.width, getHigh());
	}
	static Vec2 getSpawnEnd_low() {
		return Vec2(0,getLow());
	}
	static Vec2 getSpawnEnd_midle(){
		return Vec2(0,getMiddle());
	}
	static Vec2 getSpawnEnd_high(){
		return Vec2(0,getHigh());
	}

};

#endif
