#include "BanSung.h"
#include "ui/CocosGUI.h"
#include <sstream>
#include <iostream>

USING_NS_CC;
using namespace ui;
using namespace std;

Scene* BanSung::createScene()
{
    auto scene = Scene::create();
    auto layer = BanSung::create();
    scene->addChild(layer);
    return scene;
}
BanSung::BanSung()
{
	
}

BanSung::~BanSung()
{
	
}

bool BanSung::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	stringstream ss;
	ss << visibleSize.width << "x" << visibleSize.height;
	char ssss[100];
	sprintf(ssss, "%d x %d", visibleSize.width, visibleSize.height);
	CCLOG(ssss);
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(BanSung::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

   
	

	////kid animation
	//animation
	//B1: Nạp file .plist vào SpriteFrameCache
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("kidstart.plist");
	//B2: Tạo đối tượng SpriteBatchNode (đối tượng thực hiện animation)
	auto spriteSheet = SpriteBatchNode::create("kidstart.png");
	spriteSheet->setScale(1.2);
	spriteSheet->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(spriteSheet);

	//B3: tạo animation: 1 là chuỗi các SpriteFrame, thứ hai là thời gian giữa các frame.
	Vector<SpriteFrame*> animFrames(2);
	char str[50] = { 0 };
	for (int i = 4; i <= 5; i++)
	{
		sprintf(str, "kid%d.png", i);
		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
		animFrames.pushBack(frame);
	}
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.5f);
	//B4: Chuyển Animation vào action Animate
	Sprite* spriteAnimate = Sprite::createWithSpriteFrameName("kid4.png");
	spriteAnimate->runAction(RepeatForever::create(Animate::create(animation)));
	spriteSheet->addChild(spriteAnimate, 2);
	spriteSheet->setTag(11);

	//comment
	auto comment = Sprite::create("comment1.png");
	comment->setPosition(Vec2(650, 500));
	comment->setScale(1);
	this->addChild(comment, 0);
	comment->setTag(10);


	auto apple = Sprite::create("apple.png");
	apple->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 155));
	apple->setScale(0.5);
	this->addChild(apple, 0);

	
	
    
	//set background
	auto bgImage = Sprite::create("bg.jpg");   
	// position the sprite on the center of the screen 
	bgImage->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));   
	// add background image at z-position = -1, bottom of all // the z-position value is relative to parent 
	this->addChild(bgImage, -1);       
	// calculate the scaling factor to fill the screen size float 
	float rX = visibleSize.width / bgImage->getContentSize().width;
	float rY = visibleSize.height / bgImage->getContentSize().height;      
	// set the scaling factor to the background image
	bgImage->setScaleX(rX); 
	bgImage->setScaleY(rY); 

	auto baloon = Sprite::create("baloon3.png");
	baloon->setPosition(Vec2(200,100));
	baloon->setScale(0.05);
	auto moveTo = MoveTo::create(20, Vec2(200, 1000));
	baloon->runAction(moveTo);
	this->addChild(baloon, 0);

	
	//button start
	auto button = Button::create("Start2.png", "Start1.png", "Start2.png");
	button->setTag(12); // i made this up

	//button->setTitleText("Button");
	button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			std::cout << "Button 1 clicked" << std::endl;
			//this->removeChild(button);

			onStart();
			break;
		default:
			break;
		}
	});
	button->setPosition(Point(500, 100));
	button->setScale(0.4);
	this->addChild(button);
	
    return true;
}


void BanSung::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void BanSung:: onStart()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	//remove button
	this->removeChildByTag(10);
	this->removeChildByTag(11);
	this->removeChildByTag(12);
	

	//B1: Nạp file .plist vào SpriteFrameCache
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("per.plist");
	//B2: Tạo đối tượng SpriteBatchNode (đối tượng thực hiện animation)
	auto spriteSheet = SpriteBatchNode::create("per.png");
	spriteSheet->setScale(1.2);
	spriteSheet->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(spriteSheet);

	//B3: tạo animation: 1 là chuỗi các SpriteFrame, thứ hai là thời gian giữa các frame.
	Vector<SpriteFrame*> animFrames(2);
	char str[50] = { 0 };
	for (int i = 1; i <= 2; i++)
	{
		sprintf(str, "kid%d.png", i);
		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
		animFrames.pushBack(frame);
	}
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.5f);
	//B4: Chuyển Animation vào action Animate
	Sprite* spriteAnimate = Sprite::createWithSpriteFrameName("kid1.png");
	spriteAnimate->runAction(RepeatForever::create(Animate::create(animation)));
	spriteSheet->addChild(spriteAnimate, 2);


	auto target = Sprite::create("target2.png");
	//target->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 155));
	target->setPosition(Vec2(400, 100));

	target->setScale(0.1);

	auto moveTo1 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x - 80, visibleSize.height / 2 + origin.y - 80 + 155));
	auto moveTo2 = MoveTo::create(1, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 155));
	auto moveTo3 = MoveTo::create(1, Vec2(visibleSize.width / 2 + 80, visibleSize.height / 2 + origin.y + -80 + 155));


	//target->runAction(moveTo1);
	auto delay = DelayTime::create(0);
	target->runAction(CCRepeatForever::create(Sequence::create(moveTo1, moveTo2, moveTo3, nullptr)));
	this->addChild(target, 0);
}