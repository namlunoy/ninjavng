/*
 * PhiTieu.h
 *
 *  Created on: Mar 23, 2015
 *      Author: Dang
 */

#ifndef PHITIEU_H_
#define PHITIEU_H_

#include "cocos2d.h"

USING_NS_CC;


class PhiTieu : public cocos2d::Layer {
private:
	Size screenSize;
	Sprite* shuriken;
	Label* _log;
public:

	static Scene* createScene();
	virtual bool init();
	bool touch(Touch* t,Event* e);
	CREATE_FUNC(PhiTieu);

};

#endif /* PHITIEU_H_ */
