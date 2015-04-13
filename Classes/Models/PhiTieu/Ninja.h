#ifndef _NINJA_
#define _NINJA_

#include "cocos2d.h"
#include "NinjaModel.h"
#include "Utility/XHelper.h"
#include <sstream>
#include <iostream>

USING_NS_CC;
using namespace std;

class Ninja : public Node
{
private:
	//-----------------------  dùng chung ---------------------
	NinjaModel _ninjaModel;
	PhysicsBody* _body;
	Sprite* _sprite;
	bool init(string fileName);
	void runAnimation(string name, int count, float time, bool isRepeat);
	Vec2 originalPosition;
	int jumpCount;

private:
	void resetJumpCount();
public:
	Ninja();
	~Ninja();
	static Ninja* create(string fileName);
	void setOriginalPosition(Vec2);
	void runAnimation_DungYen();
	void runAnimation_Nhay();
	void jump();

	bool onContactBegin(PhysicsContact& contact);
};

#endif
