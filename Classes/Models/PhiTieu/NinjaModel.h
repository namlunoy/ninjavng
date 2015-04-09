#ifndef _NINJA_MODEL_
#define _NINJA_MODEL_

#include "cocos2d.h"
#include <iostream>

USING_NS_CC;
using namespace std;

/*
Lớp này chứa thông tin của thằng ninja
*/
class NinjaModel
{
public:
	//khối lượng
	float mass;
	//tỷ khối
	float density;
	//tỷ lệ phản hồi
	float restitution;
	//Lực ma sát
	float friction;
	//lực để nhảy
	float force_Y;

public:
	void setPhysic(float mass, float density, float restitution, float friction);
	NinjaModel();
	~NinjaModel();
};
#endif


