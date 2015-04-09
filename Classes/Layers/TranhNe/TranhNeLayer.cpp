/*
 * TranhNeLayer.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#include "TranhNeLayer.h"

TranhNeLayer::TranhNeLayer() {
}
TranhNeLayer::~TranhNeLayer() {
}

bool TranhNeLayer::init()
{
	//Back Button
	auto backButton = Button::create("back_button-1.png", "back_button-1.png",
			"back_button - 1.png");
	backButton->setAnchorPoint(Vec2(0, 0));
	backButton->setScale(0.3f, 0.5f);
	backButton->setPosition(
			Point(0,
					Config::screenSize.height
							- backButton->getContentSize().height / 2));
	backButton->addTouchEventListener(
			[&](Ref* sender, Widget::TouchEventType type) {
				switch (type)
				{
					case ui::Widget::TouchEventType::BEGAN:
					break;
					case ui::Widget::TouchEventType::ENDED:
					//auto helloScene = HelloWorld::createScene();
					Director::getInstance()->replaceScene(HelloWorld::createScene());
					break;
					default:
					break;
				}
			});
	this->addChild(backButton);


	auto label = LabelTTF::create("Tranh Ne","Arial",30);
	label->setPosition(Vec2(100,100));
	this->addChild(label);
	return true;
}

