#include "Start_Layer.h"
#include "Utility/Config.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Scenes/JumpScene.h"
#include "Models/Jump/Ninja_D.h"
#include "Models/Jump/Pillar.h"
using namespace ui;
USING_NS_CC;

Start_Layer::Start_Layer()
{
}

Start_Layer::~Start_Layer()
{
}

bool Start_Layer::init()
{
	if (!Layer::init()) return false;

	//Back button
	this->setKeypadEnabled(true);
	this->setKeyboardEnabled(true);

	//Background
	auto background = Sprite::create("Bamboo/Background_bamboo_2.png");
	background->setPosition(Config::centerPoint);
	background->setScale(Config::getScale(background));
	this->addChild(background, 0);

	//Nền mờ
	Sprite * opacity = Sprite::create("opacity.png");
	opacity->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	opacity->setScale(Config::getScale(opacity));
	opacity->setPosition(Config::centerPoint);
	opacity->setOpacity(100);
	this->addChild(opacity, 1);

	//Name
	Label * name_Game = Label::create("NINJA BAMBOO", "fonts/Vnhatban.TTF", 50, Size::ZERO, TextHAlignment::CENTER, TextVAlignment::CENTER);
	name_Game->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	name_Game->setPosition(Point(Config::screenSize.width / 2, Config::screenSize.height * 5 / 6));
	name_Game->setColor(Color3B::WHITE);
	this->addChild(name_Game, 2);

	//Start Button
	Button * play_Button = Button::create("play.png");
	play_Button->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	play_Button->setPosition(Point(Config::screenSize.width / 2, Config::screenSize.height * 4 / 6));
	play_Button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(TransitionFade::create(0.5, JumpScene::createPhysicScene(), Color3B::WHITE));
			//this->Hide_Start_Layer();
			break;
		default:
			break;
		}
	});
	this->addChild(play_Button, 2);

	//Pillar
	Pillar * pillar = Pillar::createPillar();
	pillar->setPosition(Config::screenSize.width / 2, 0);
	pillar->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->addChild(pillar, 2);

	//Ninja
	Ninja_D * ninja = Ninja_D::createNinja();
	ninja->setPosition(Point(Config::screenSize.width / 2, 176));
	ninja->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->addChild(ninja, 2);

	return true;
}

Start_Layer * Start_Layer::createStartLayer()
{
	Start_Layer * layer = new Start_Layer();
	layer->init();
	layer->autorelease();
	return layer;
}

void Start_Layer::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
	{
		Director::getInstance()->end();
	}
}