#ifndef _TARGET_
#define _TARGET_

#include "cocos2d.h"
#include <iostream>

USING_NS_CC;
using namespace std;

class BanTao_Target : public Node
{

private:
	Sprite* _sprite;

public:

	BanTao_Target();
	~BanTao_Target();
	bool init(string fileName);
	static BanTao_Target* create(string fileName, float speed);

	bool isMove;
	void moveAction(float speed);
};
#endif