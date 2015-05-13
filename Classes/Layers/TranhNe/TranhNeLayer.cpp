#include "Layers/TranhNe/TranhNeLayer.h"
#include "SimpleAudioEngine.h"
#include "Models/TranhNe/Ninja_Tranh.h"
#include "Models/TranhNe/VatRoi.h"
#include "Models/TranhNe/Giun_Dat.h"
#include "Models/TranhNe/Nen.h"
#include "Scenes/HelloWorldScene.h"

USING_NS_CC;
using namespace std;

TranhNeLayer::TranhNeLayer(){}
TranhNeLayer::~TranhNeLayer(){}

bool TranhNeLayer::init()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Tranh_Ne/Am_Thanh/Old Stump.mp3", true);
	Size winSize = Config::screenSize;

	auto Anh_Nen = Sprite::create("Tranh_Ne/Nen/Nen.jpg");
	Anh_Nen->setScaleY(0.96f);
	Anh_Nen->setPosition(0, winSize.height);
	Anh_Nen->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	this->addChild(Anh_Nen);

	auto backButton = Button::create("Tranh_Ne/Chuc_Nang/Huy.png", "Tranh_Ne/Chuc_Nang/Huy.png", "Tranh_Ne/Chuc_Nang/Huy.png");
	backButton->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	backButton->setScale(0.1f);
	backButton->setPosition(Vec2(0, winSize.height));
	backButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
			Director::getInstance()->replaceScene(HelloWorld::createScene());
			break;
		default:
			break;
		}
	});
	this->addChild(backButton);

	Ninja_Ne = Ninja_Tranh::Tao_Ninja_Tranh("Tranh_Ne/Ninja.png");
	Ninja_Ne->setPosition(winSize.width / 2, 120 + Ninja_Ne->getContentSize().height);
	this->addChild(Ninja_Ne);

	srand(time(0)); Load_VR(); Load_Giun();

	for (int i = 0; i < 3; i++)
	{
		Mat_Dat = Nen::Tao_Nen();
		if (i != 0)
		{
			Mat_Dat->setRotation(90);
			if (i == 1)
			{
				Mat_Dat->setPosition(2, winSize.height / 2);
			}
			else
			{
				Mat_Dat->setPosition(winSize.width - 2, winSize.height / 2);
			}
		}
		else
		{
			Mat_Dat->setPosition(winSize.width / 2, 70);
		}
		this->addChild(Mat_Dat);
	}

	auto btnTrai = Button::create("Tranh_Ne/Chuc_Nang/Trai.png", "Tranh_Ne/Chuc_Nang/Trai.png", "Tranh_Ne/Chuc_Nang/Trai.png");
	btnTrai->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	btnTrai->setScale(0.1f);
	btnTrai->setPosition(Vec2(0, 0));
	btnTrai->addTouchEventListener([&](Ref* sender, Widget::TouchEventType Type_Trai)
	{
		switch (Type_Trai)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Ninja_Ne->Di_Chuyen(-8, 0);
			break;
		default:
			break;
		}
	});
	this->addChild(btnTrai);

	auto btnPhai = Button::create("Tranh_Ne/Chuc_Nang/Phai.png", "Tranh_Ne/Chuc_Nang/Phai.png", "Tranh_Ne/Chuc_Nang/Phai.png");
	btnPhai->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	btnPhai->setScale(0.1f);
	btnPhai->setPosition(Vec2(winSize.width - btnPhai->getContentSize().width*btnPhai->getScale(), 0));
	btnPhai->addTouchEventListener([&](Ref* sender, Widget::TouchEventType Type_Phai)
	{
		switch (Type_Phai)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Ninja_Ne->Di_Chuyen(8, 0);
			break;
		default:
			break;
		}
	});
	this->addChild(btnPhai);

	auto btnNhay = Button::create("Tranh_Ne/Chuc_Nang/Len.png", "Tranh_Ne/Chuc_Nang/Len.png", "Tranh_Ne/Chuc_Nang/Len.png");
	btnNhay->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	btnNhay->setScale(0.1f);
	btnNhay->setPosition(Vec2((btnNhay->getContentSize().width*btnNhay->getScale()) * 2, 0));
	btnNhay->addTouchEventListener([&](Ref* sender, Widget::TouchEventType Type_Nhay)
	{
		switch (Type_Nhay)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Ninja_Ne->Nhay(Ninja_Ne->getPositionX(), Ninja_Ne->getPositionY());
			break;
		default:
			break;
		}
	});
	this->addChild(btnNhay);

	int So_Mang = 10;
	int Goc = btnNhay->getContentSize().width*btnNhay->getScale() * 3;
	int Tam_VR = rand() % 2; char Ten[24]; //int Tam_VR = random(0, 1); mien gia tri [0,1]
	sprintf(Ten, "Tranh_Ne/Mang/%d.png", Tam_VR); int Dem_Mang = -1;
	for (int i = 0; i < So_Mang; i++)
	{
		Sprite* Anh_Mang = Sprite::create(Ten);
		Anh_Mang->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		Anh_Mang->setScale(0.48f);
		Anh_Mang->setPosition(Vec2(Goc, 0));
		if (Tam_VR == 0)
		{
			Goc = Goc + 40;
		}
		else
		{
			Goc = Goc + 50;
		}
		Anh_Mang->setTag(Dem_Mang); Dem_Mang--; this->addChild(Anh_Mang);
	}

	auto Lang_Nghe = EventListenerPhysicsContact::create();//lang nghe cac tuong tac Vat Ly xay ra
	Lang_Nghe->onContactBegin = CC_CALLBACK_1(TranhNeLayer::onContactBegin, this);//ghi de 2 ham onContactbegin
	_eventDispatcher->addEventListenerWithSceneGraphPriority(Lang_Nghe, this);

	//Back button
	this->setKeypadEnabled(true);
	this->setKeyboardEnabled(true);

	return true;
}

void TranhNeLayer::Load_VR()
{
	int Tam_VR, Tam_STT, Vi_Tri_X = 80, Khoang_Cach = 150; char Ten[24];
	int Tag_DoAn = 3, Tag_VuKhi = 8, Tag_DoDung = 13;
	for (int i = 0; i < 5; i++)
	{
		Tam_VR = rand() % 3;
		if (Tam_VR == 0)//Do an
		{
			Tam_STT = rand() % 8; sprintf(Ten, "Tranh_Ne/Do_An/%d.png", Tam_STT);
			vatRoi = VatRoi::Tao_VatRoi(Ten); vatRoi->setTag(Tag_DoAn); Tag_DoAn++;
		}
		if (Tam_VR == 1)//Vu khi
		{
			Tam_STT = rand() % 7; sprintf(Ten, "Tranh_Ne/Vu_Khi/%d.png", Tam_STT);
			vatRoi = VatRoi::Tao_VatRoi(Ten); vatRoi->setTag(Tag_VuKhi); Tag_VuKhi++;
		}
		if (Tam_VR == 2)//Do dung
		{
			Tam_STT = rand() % 5; sprintf(Ten, "Tranh_Ne/Do_Dung/%d.png", Tam_STT);
			vatRoi = VatRoi::Tao_VatRoi(Ten); vatRoi->setTag(Tag_DoDung); Tag_DoDung++;
		}
		vatRoi->setPosition(Vi_Tri_X + i *Khoang_Cach, Config::screenSize.height - 40);
		this->addChild(vatRoi);
		vatRoi->Roi(1);
		log("Load_VR()");
	}
}

void TranhNeLayer::Load_Giun()
{
	int Tam_VR, Tam_STT; char Ten[24];
	Tam_VR = rand() % 2; Tam_STT = rand() % 6;
	sprintf(Ten, "Tranh_Ne/Quai_Vat/%d.png", Tam_STT);
	Con_Giun = Giun_Dat::Tao_Giun_Dat(Ten);
	if (Tam_VR == 0)//Ben trai
	{
		Con_Giun->setPosition(50, Ninja_Ne->getPositionY());
		this->addChild(Con_Giun); Con_Giun->Quet_Dat(10);
	}
	else//Ben phai
	{
		Con_Giun->setPosition(Config::screenSize.width - 50, Ninja_Ne->getPositionY());
		this->addChild(Con_Giun); Con_Giun->Quet_Dat(-10);
	}
	log("Load_Giun()");
}

bool TranhNeLayer::onContactBegin(PhysicsContact &contact)
{
	auto obj_A = contact.getShapeA()->getBody()->getNode(); int Tag_A = obj_A->getTag();
	auto obj_B = contact.getShapeB()->getBody()->getNode(); int Tag_B = obj_B->getTag();
	if (Tag_A == 1)
	{
		if (Tag_B >= 2)
		{
			this->removeChildByTag(Tag_B,true);
			this->removeChildByTag(-(Ninja_Ne->So_Mang),true);
			if (Ninja_Ne->So_Mang > 0)
			{
				Ninja_Ne->So_Mang--;
			}
			else
			{
				this->removeChildByTag(Tag_A,true);
				this->stopAllActions();
			}
			if (Tag_B >= 3){ vatRoi->So_VR--; }
		}
	}
	else
	{
		if ((Tag_A >= 2) && (Tag_B == 1))
		{
			this->removeChildByTag(Tag_A,true);
			this->removeChildByTag(-(Ninja_Ne->So_Mang),true);
			if (Ninja_Ne->So_Mang > 0)
			{
				Ninja_Ne->So_Mang--;
			}
			else
			{
				this->removeChildByTag(Tag_B,true);
				this->stopAllActions();
			}
			if (Tag_A >= 3){ vatRoi->So_VR--; }
		}
		else
		{
			if (Tag_A == 0)
			{
				if (Tag_B == 2)
				{
					this->removeChildByTag(Tag_B,true);
				}
				else
				{
					if (Tag_B >= 3)
					{
						for (int i = 0; i < vatRoi->So_VR; i++)
						{
							this->removeChildByTag(Tag_B, true);
						}
						Load_VR(); Load_Giun();
					}
				}
			}
		}
	}
	log("Va_Cham(TranhNeLayer)");
	return false;
}

void TranhNeLayer::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
	{
		auto scene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene, Color3B::WHITE));
	}
}