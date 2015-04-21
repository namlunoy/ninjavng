/*
 * ChemLayer.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#include "ChemLayer.h"
#include"SimpleAudioEngine.h"

USING_NS_CC;

ChemLayer::ChemLayer() {
}
ChemLayer::~ChemLayer() {
}

bool ChemLayer::init() {

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
	this->addChild(backButton,1);


	//auto label = LabelTTF::create("Chem","Arial",30);
	//label->setPosition(Vec2(100,100));
	//this->addChild(label);

	// Lấy kích thước màn hình
	Size winSize = Director::getInstance()->getWinSize(); 

	//background
	auto background = Sprite::create("cong_background.jpg");
	background->setPosition(Vec2(winSize.width/2, winSize.height/2));
	background->setScale(0.6f);
	this->addChild(background,0);

	// Tạo 1 Sprite, nhân vật của chúng ta 
	player = Sprite::create("Ninja2.png");  

	// Đặt lên màn hình 
	player->setPosition(Vec2(100,60));

	//Tạo 1 bộ khung body vật lý dạng hình hộp
	auto playerBody= PhysicsBody::createBox(player->getBoundingBox().size);

	//Đặt cờ = 1, để kiểm tra đối tượng khi va chạm sau này
	player->setTag(1);

	//Lệnh này ko hiểu lắm nhưng thực sự ko thể thiếu, bỏ đi sẽ ko có gì xuất hiện khi va chạm
	playerBody->setContactTestBitmask(0x1);

	//Đặt bộ khung vật lý vào nhân vật
	player->setPhysicsBody(playerBody);

	// Thêm vào layer nằm trong Scene game
	this->addChild(player,1);

	// Gọi tới hàm gameLogic , hàm này có nhiệm vụ tạo ra đám quái với thời gian 1 giây 1 quái
	this->schedule( schedule_selector(ChemLayer::gameLogic), 1.0 );

	//-----------------  Touch event ------------
	auto _touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(
		ChemLayer::touch_Kiem, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener,
		this);

	//them am thanh cho game
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("background-music-aac.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("background-music-aac.wav",true); // True = lặp lại vô hạn
	return true;
}

void ChemLayer::gameLogic(float dt)
{
	this->addTarget();
}

bool ChemLayer::touch_Kiem(Touch* t, Event* e) {
	//tao sprite kiem
	katana = Sprite::create("katana.png");  
	katana->setScale(0.1f);
	//dat len man hinh
	katana->setPosition(Vec2(100+player->getContentSize().width,60+player->getContentSize().height/3));
	//tao body cho kiem
	auto katanaBody=PhysicsBody::createBox(katana->getBoundingBox().size);
	katana->setTag(1);
	katanaBody->setAngularVelocity(-30);
	katanaBody->setContactTestBitmask(0x1);
	//dat khung vat ly vao kiem
	katana->setPhysicsBody(katanaBody);
	this->addChild(katana,1);
	return true;
}

// Hàm này tạo ra Quái và di chuyển chúng nè
void ChemLayer::addTarget()
{
	auto target = Sprite::create("HaiLua.png");
	target->setScale(0.1f);
	Size winSize = Director::getInstance()->getWinSize();
	// Đoạn này tính toán vùng xuất hiện quái sao cho ko bị khuất quái vào viền màn hình

	int minY = target->getContentSize().height/2;
	int maxY = winSize.height
		-  target->getContentSize().height/2;
	int rangeY = maxY - minY;
	int actualY = ( rand() % rangeY ) + minY;

	// Đặt quái vào khoảng vị trí trên actualY (random)
	target->setPosition(Point(winSize.width + (target->getContentSize().width/2),60));
	// Giải thích giống phần Nhân vật	
	auto targetBody = PhysicsBody::createBox(target->getBoundingBox().size);
	target->setTag(2);
	targetBody->setContactTestBitmask(0x1);
	target->setPhysicsBody(targetBody);
	this->addChild(target,1);

	//Tính toán tốc độ di chuyển của quái
	int minDuration = (int)2.0;
	int maxDuration = (int)4.0;
	int rangeDuration = maxDuration - minDuration;
	int actualDuration = ( rand() % rangeDuration )
		+ minDuration;
	// Di chuyển quái với 1 tốc độ nằm trong khoảng actualDuration , từ điềm xuất hiện tới điểm Point(0,y)

	auto actionMove =  MoveTo::create( (float)actualDuration, Point(0 - target->getContentSize().width/2, 60) );

	// Kết thúc việc di chuyển của quái khi đã tới điểm cuối
	auto actionMoveDone =   CallFuncN::create(CC_CALLBACK_1(ChemLayer::spriteMoveFinished,this));

	// Chạy 2 Action trên 1 cách tuần tự = lệnh Sequence sau
	target->runAction( Sequence::create(actionMove, actionMoveDone, NULL) );
}

void ChemLayer::spriteMoveFinished(Node* sender)
{
	// Hàm này có mỗi công việc là loại bỏ Target ( đang là Sprite) ra khỏi layer của game
	// Ép kiểu Contrỏ Sprite của 1 Node*
	auto sprite = (Sprite *)sender;
	this->removeChild(sprite, true);    
}