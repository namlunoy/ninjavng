#ifndef _Enemy_
#define _Enemy_

#include "cocos2d.h"
#include "Utility/Tags.h"
#include "Utility/XHelper.h"
#include <iostream>

USING_NS_CC;


enum EnemyType
{
	Run,
	RunAndJump,
	Fly
};

class Enemy : public Node
{
protected:
	Enemy();
//---------- Các thuộc tính ----------
protected:
	int _level;
	std::string _fileName;
	float _speed;
	int _health;
	EnemyType _type;

//---------- Các component  ----------
protected:
	Sprite* _sprite;
	PhysicsBody* _body;
	Action* _action;


public:
	//Các lớp con gọi hàm setup, và phải implement setAction
	//Thực hiện setup các thuộc tính chung chung
	virtual void setup(int level,std::string fileName, EnemyType type);
	//Mỗi cái phải viết 1 cái action riêng
	virtual void setupAction() = 0;

	~Enemy();
};
#endif
