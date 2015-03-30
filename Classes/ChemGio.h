/*
 * PhiTieu.h
 *
 *  Created on: Mar 23, 2015
 *      Author: Dang
 */

#ifndef CHEMGIO_H_
#define CHEMGIO_H_

#include "cocos2d.h"

USING_NS_CC;


class ChemGio : public cocos2d::Layer {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(ChemGio);
};

#endif /* PHITIEU_H_ */
