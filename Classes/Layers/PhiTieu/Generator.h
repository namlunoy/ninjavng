#ifndef _Generator_
#define _Generator_

#include "cocos2d.h"
#include <iostream>
USING_NS_CC;

class Generator
{
private:
	Layer* _layer;
public:
	Generator(Layer* layer);
	~Generator();
};

#endif