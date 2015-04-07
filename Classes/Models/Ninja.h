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

	//Các thao tác với animation thường thao tác với nó
	//Còn những cái action khác có thể làm với this luôn
	Sprite* _sprite;

	bool init(string fileName);

	//Công: Hàm chạy animation, phải nạp file plist bằng phương thức addPlistFile trước
	//name: tên file (ko có đuôi),vd: ninja_dungyen
	//count: số frames
	//time: thời gian giữa các frame
	//repeat: có lặp lại hay không
	void runAnimation(string name, int count, float time, bool isRepeat);

	//-------------------- Công -------------------------


	//--------------------- Đăng ------------------------

	
	//--------------------------------------------------
public:
	Ninja();
	~Ninja();
	static Ninja* create(string fileName);
	//-------------------- Công -------------------------
	//Các animation
	void runAnimation_DungYen();
	void runAnimation_Nhay();
	void jump();

	void removeAllActions()
	{
		_sprite->getActionManager()->removeAllActionsFromTarget(this->_sprite);
	}

	//--------------------- Đăng ------------------------
	PhysicsBody *bodyNinja;
	Ninja(Layer *layer);
	bool isJumping;
	bool isAlive;
	void jumpAction();
	//---------------------------------------------------
};

#endif
