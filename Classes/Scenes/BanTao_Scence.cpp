#include "BanTao_Scence.h"

BanTao_Scence::BanTao_Scence(){}
BanTao_Scence::~BanTao_Scence(){}

bool BanTao_Scence::init()
{
	if (!Scene::init())
		return false;

	banTaoLayer = BanTao_Layer::create();
	this->addChild(banTaoLayer);

	banTaoHudLayer = BanTao_HudLayer::create();
	this->addChild(banTaoHudLayer,1);

	banTaoLayer->setHudLayer(banTaoHudLayer);



	return true;
}