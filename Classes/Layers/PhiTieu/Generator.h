#ifndef _Generator_
#define _Generator_

#include "cocos2d.h"
#include "PhiTieuLayer.h"
#include "Models/PhiTieu/Enemy_Jump.h"
#include "Models/PhiTieu/Enemy_Run.h"
#include "PhiTieuLayer.h"

#include <iostream>
USING_NS_CC;

class PhiTieuLayer;

class Generator : public Node
{
private:
	PhiTieuLayer* layer;
public:
	Generator(PhiTieuLayer* l);

	~Generator();

	void sinhJump();

	void sinhRun();

	void Generate();
};

#endif
