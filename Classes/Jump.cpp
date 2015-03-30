#include "Jump.h"
#include "ui/CocosGUI.h"

using namespace ui;

Scene* Jump::createScene()
{
	CCLOG("Tao scene!");
	Scene* scene = Scene::create();
	auto layer = Jump::create();
	scene->addChild(layer);
	return scene;
}

bool Jump::init()
{
	CCLOG("init()");
	if (!Layer::init())
		return false; 
	Size screenSize = Director::getInstance()->getVisibleSize();
	//Background
	auto background = Sprite::create("Background.jpg");
	background->setAnchorPoint(Vec2(0.5, 0.5));
	background->setScale(0.5);
	background->setPosition(screenSize.width / 2, screenSize.height / 2);
	this->addChild(background, 0);

	//Ninja
	float height = 100;
	auto ninjaSprite = Sprite::create("Ninja2.png");
	ninjaSprite->setPosition(screenSize.width / 2, screenSize.height / 2);
	this->addChild(ninjaSprite);

	//Touch
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(Jump::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(Jump::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	
	return true;
}

void Jump::jump(Sprite *sprite, float height)
{
	Vec2 currentPos = sprite->getPosition();
	auto jump = JumpTo::create(2, Vec2(currentPos), height, 1);
	sprite->runAction(jump);
}

bool Jump::onTouchBegan(Touch *touch, Event *unused_event)
{
	return true;
}

void Jump::onTouchMoved(Touch *touch, Event *unused_event)
{

}

void Jump::onTouchEnded(Touch *touch, Event *unused_event)
{
	this->jump(ninjaSprite, height);
}