﻿#ifndef _XHelper_
#define _XHelper_

#include "cocos2d.h"
#include <iostream>

USING_NS_CC;
using namespace std;

class XHelper
{
public:
	XHelper();
	~XHelper();

	//Hàm chạy animation
	//name: tên file (ko có đuôi),vd: ninja_dungyen
	//count: số frames
	//time: thời gian giữa các frame
	//repeat: có lặp lại hay không
	static void runAnimation(string name, int count, float time, bool isRepeat,Sprite* sprite);

	//Hiển thị thông tin của node trên log! Position, BoundingBox, Anchor,...
	static void Log(Node* node,string tag);

};

#endif