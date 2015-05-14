#ifndef _Generator_
#define _Generator_

#include "cocos2d.h"
#include "PhiTieuLayer.h"
#include "Models/PhiTieu/Enemy.h"
#include "Models/PhiTieu/Enemy_Jump.h"
#include "Models/PhiTieu/Enemy_Run.h"
#include "PhiTieuLayer.h"

#include <iostream>
#include <vector>
USING_NS_CC;

class PhiTieuLayer;

class Generator : public Node
{
private:
	PhiTieuLayer* layer;
	bool isGenerate;
	int counter;
	Vector<Enemy*> enemies;

public:
	static Generator* Instance;
	Generator(PhiTieuLayer* l);
	~Generator();
	void Generate(int);


	void sinhJump();
	void sinhRun();
	void sinhHeart();
	void gameOver();
	
};

#endif
