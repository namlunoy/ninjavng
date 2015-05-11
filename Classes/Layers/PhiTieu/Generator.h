﻿#ifndef _Generator_
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
	int MAX;
	std::vector<Enemy*> enemies;

	void SinhLevel_1();
	void SinhLevel_2();
	void SinhLevel_3();
	void SinhLevel_4();
	void SinhLevel_5();
public:
	Generator(PhiTieuLayer* l);
	~Generator();
	void Generate(int);



	void sinhJump();
	void sinhRun();
	//xxx
	void stop();
};

#endif
