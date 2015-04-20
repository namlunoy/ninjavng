/*
 * Enemy_Jump.h
 *
 *  Created on: Apr 20, 2015
 *      Author: conghoang
 */

#ifndef MODELS_PHITIEU_ENEMY_JUMP_H_
#define MODELS_PHITIEU_ENEMY_JUMP_H_

#include "Enemy.h"
#include "Utility/Config.h"
#include "Utility/XHelper.h"

USING_NS_CC;

class Enemy_Jump : public Enemy {
public:
	Enemy_Jump();
	virtual ~Enemy_Jump();

	static Enemy_Jump*  create(int level);
	void setupAction() override;

};

#endif /* MODELS_PHITIEU_ENEMY_JUMP_H_ */
