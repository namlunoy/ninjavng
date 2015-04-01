#ifndef _HELPER_
#define _HELPER_

#include "cocos2d.h"
#include <iostream>

USING_NS_CC;
using namespace std;

class Helper
{
public:
	Helper();
	~Helper();

	//Hàm chạy animation
	//name: tên file (ko có đuôi),vd: ninja_dungyen
	//count: số frames
	//time: thời gian giữa các frame
	//repeat: có lặp lại hay không
	static void runAnimation(string name, int count, float time, bool isRepeat,Sprite* sprite);


};

#endif
