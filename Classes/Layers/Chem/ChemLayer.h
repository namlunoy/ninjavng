/*
 * ChemLayer.h
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#ifndef LAYERS_CHEM_CHEMLAYER_H_
#define LAYERS_CHEM_CHEMLAYER_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Scenes/HelloWorldScene.h"

USING_NS_CC;
using namespace ui;

class ChemLayer : public Layer {
private:
	Button* bt_jump;

public:
	CREATE_FUNC(ChemLayer);
	bool init();

	void addTarget();  
	void gameLogic(float dt);
	void spriteMoveFinished(cocos2d::Node* sender);
	ChemLayer();
	~ChemLayer();//virtual 
	void click_Jump(Ref* sender, TouchEventType touchType);
	Sprite* player;
	Sprite* katana;
	Node* ninja;
	bool touch_Kiem(Touch* t, Event* e);
	//bat su kien va cham dan va quai
	bool onContactBegin(const PhysicsContact& contact);
	void removeNinja();
	void updateNinja();
	void headSprite();
	void restart();

	
private:
	void updateScore();
};

#endif /* LAYERS_CHEM_CHEMLAYER_H_ */
