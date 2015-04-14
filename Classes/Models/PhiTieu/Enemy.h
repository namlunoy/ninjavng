#ifndef _Enemy_
#define _Enemy_

#include "cocos2d.h"

USING_NS_CC;


enum EnemyType
{
	RunOnly,
	RunAndJump,
	FlyOnly
};

class Enemy : public Node
{
protected:
	Enemy();
	//Các thuộc tính
protected:
	float _speed;
	int _health;
	EnemyType _type;
	//Các component
protected:
	Sprite* _sprite;
	PhysicsBody* _body;
	Action* _action;

public:
	virtual void setup() = 0;
	
	~Enemy();
};
#endif
