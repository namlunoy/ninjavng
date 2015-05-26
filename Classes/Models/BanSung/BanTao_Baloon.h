#ifndef _BALOON_
#define _BALOON_

#include "cocos2d.h"
#include <iostream>

USING_NS_CC;
using namespace std;

class BanTao_Baloon : public Node
{

private:
	Sprite* _sprite;

public:

	BanTao_Baloon();
	~BanTao_Baloon();
	bool init(string fileName);
	static BanTao_Baloon* create(string fileName);
	void boom();
};
#endif