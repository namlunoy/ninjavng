﻿#ifndef _NINJA_
#define _NINJA_

#include "cocos2d.h"
#include <sstream>
#include <iostream>

USING_NS_CC;
using namespace std;

class Ninja : public Node
{
private: 
	//-----------------------  dùng chung ---------------------
	Sprite* _sprite;
	bool init(string fileName);
	//-------------------- Công -------------------------


	//--------------------- Đăng ------------------------


	//--------------------------------------------------
public:
	Ninja();
	~Ninja();
	static Ninja* create(string fileName);
	//-------------------- Công -------------------------
	//Công: Hàm chạy animation
	//name: tên file (ko có đuôi),vd: ninja_dungyen
	//count: số frames
	//time: thời gian giữa các frame
	//repeat: có lặp lại hay không
	void runAnimation( string name, int count, float time, bool isRepeat);
	
	//--------------------- Đăng ------------------------


	//---------------------------------------------------
};

#endif