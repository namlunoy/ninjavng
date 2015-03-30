#ifndef _NINJA_
#define _NINJA_

#include "cocos2d.h"
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

	
	//--------------------- Đăng ------------------------
	bool isJumping = false;
	void jumpAction();
	//---------------------------------------------------
};

#endif