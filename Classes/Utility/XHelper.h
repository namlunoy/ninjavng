#ifndef _XHelper_
#define _XHelper_

#include "cocos2d.h"
#include <iostream>

USING_NS_CC;
using namespace std;

enum WallType
{
	UP,DOWN,LEFT,RIGHT
};

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
	static bool checkShoot(Vec2 tamApple, float bkApple, Vec2 tamTarget)

	{
		float d = sqrt(pow((tamApple.x - tamTarget.x), 2) + pow((tamApple.y - tamTarget.y), 2));
		if (d <= bkApple) return true;
		else
			return false;
	}


};

#endif
