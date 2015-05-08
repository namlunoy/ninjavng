#include "TranhNeLayer.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
TranhNeLayer::TranhNeLayer() {}
TranhNeLayer::~TranhNeLayer() {}

bool TranhNeLayer::init()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Old Stump.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Old Stump.mp3", true);
	Size winSize = Config::screenSize;//Director::getInstance()->getWinSize();

	auto backButton = Button::create("Tranh_Ne/Chuc_Nang/Huy.png", "Tranh_Ne/Chuc_Nang/Huy.png", "Tranh_Ne/Chuc_Nang/Huy.png");
	backButton->setAnchorPoint(Vec2(0, 0));
	backButton->setScale(0.1f, 0.1f);
	backButton->setPosition(Vec2(0, winSize.height - backButton->getContentSize().height / 10));
	backButton->addTouchEventListener(
		[&](Ref* sender, Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
		{
			break;
		}
		case ui::Widget::TouchEventType::ENDED:
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
			Director::getInstance()->replaceScene(HelloWorld::createScene());
			break;
		}
		default:
			break;
		}
	});
	this->addChild(backButton, 1);

	auto Anh_Nen = Sprite::create("Tranh_Ne/Nen/Nen.jpg");
	Anh_Nen->setScaleY(0.96f);
	Anh_Nen->setPosition(Vec2(0,winSize.height));
	Anh_Nen->setAnchorPoint(Vec2(0, 1));
	this->addChild(Anh_Nen);

	auto btnTrai = Button::create("Tranh_Ne/Chuc_Nang/Trai.png", "Tranh_Ne/Chuc_Nang/Trai.png", "Tranh_Ne/Chuc_Nang/Trai.png");
	btnTrai->setAnchorPoint(Vec2(0.5f, 0.5f));
	btnTrai->setScale(0.1f, 0.1f);
	btnTrai->setPosition(Vec2(btnTrai->getContentSize().width*0.1f/2, btnTrai->getContentSize().height*0.1f/2));
	btnTrai->addTouchEventListener([&](Ref* sender, Widget::TouchEventType Type)
	{
		switch (Type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
		{
			Director::getInstance()->replaceScene(HelloWorld::createScene()); break;
		}
		default:
			break;
		}
	});

	auto Day_Body = PhysicsBody::createBox(Size(winSize.width * 2, 64));
	Day_Body->setContactTestBitmask(true);
	Day_Body->setDynamic(false);
	btnTrai->setPhysicsBody(Day_Body); btnTrai->setTag(0);
	this->addChild(btnTrai);

	auto btnPhai = Button::create("Tranh_Ne/Chuc_Nang/Phai.png", "Tranh_Ne/Chuc_Nang/Phai.png", "Tranh_Ne/Chuc_Nang/Phai.png");
	btnPhai->setAnchorPoint(Vec2(0, 0));
	btnPhai->setScale(0.1f, 0.1f);
	btnPhai->setPosition(Vec2(winSize.width - btnPhai->getContentSize().width / 10, 0));
	btnPhai->addTouchEventListener([&](Ref* sender, Widget::TouchEventType Type)
	{
		switch (Type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
		{
			Director::getInstance()->replaceScene(HelloWorld::createScene()); break;
		}
		default:
			break;
		}
	});
	this->addChild(btnPhai);

	auto btnNhay = Button::create("Tranh_Ne/Chuc_Nang/Len.png", "Tranh_Ne/Chuc_Nang/Len.png", "Tranh_Ne/Chuc_Nang/Len.png");
	btnNhay->setAnchorPoint(Vec2(0, 0));
	btnNhay->setScale(0.1f, 0.1f);
	btnNhay->setPosition(Vec2((btnNhay->getContentSize().width / 10)*2, 0));
	btnNhay->addTouchEventListener([&](Ref* sender, Widget::TouchEventType Type)
	{
		switch (Type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
		{
			Director::getInstance()->replaceScene(HelloWorld::createScene()); break;
		}
		default:
			break;
		}
	});
	this->addChild(btnNhay);

	int Goc = btnNhay->getContentSize().width / 10 * 4;
	Sprite* Anh_Mang;
	for (int i = 0; i < 3; i++)
	{
		Anh_Mang = Sprite::create("Tranh_Ne/Mang/xx.png");
		Anh_Mang->setAnchorPoint(Vec2(0, 0));
		Anh_Mang->setScale(0.48f, 0.48f);
		Anh_Mang->setPosition(Vec2(Goc, 0));
		Goc = Goc + 40;

		this->addChild(Anh_Mang);
	}

	Sprite *Nen_Mau = Sprite::create("Tranh_Ne/Mang/Test.png");
	Nen_Mau->setAnchorPoint(Vec2(0, 0));
	Nen_Mau->setScale(1.5f, 0.2f);//200,26.6
	Nen_Mau->setPosition(100,100);
	this->addChild(Nen_Mau);

	for (int i = 0; i < 5; i++)
	{
		Sprite* Muc_Mau = Sprite::create("Tranh_Ne/Mang/Test.png");
		Muc_Mau->setAnchorPoint(Vec2(0, 0));
		Muc_Mau->setScale(0.2f,0.2f);// (0.3f, 0.2f);
		Muc_Mau->setColor(Color3B(255, 0, 0));
		Muc_Mau->setPosition(Vec2(0,0));// (i*(Muc_Mau->getContentSize().width*0.3f), 0));
		Nen_Mau->addChild(Muc_Mau);
	}

	return true;
}

