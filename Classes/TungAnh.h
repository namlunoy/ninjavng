/*
 * PhiTieu.h
 *
 *  Created on: Mar 23, 2015
 *      Author: Dang
 */

#ifndef TUNGANH_H_
#define TUNGANH_H_

#include "cocos2d.h"

USING_NS_CC;


class TungAnh : public cocos2d::Layer {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TungAnh);
};

#endif /* PHITIEU_H_ */
