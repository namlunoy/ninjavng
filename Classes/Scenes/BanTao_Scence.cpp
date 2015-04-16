#include "BanTao_Scence.h"

BanTao_Scence::BanTao_Scence(){}
BanTao_Scence::~BanTao_Scence(){}

bool BanTao_Scence::init()
{
	if (!Scene::init())
		return false;

	banTaoLayer = BanTao_Layer::create();
	this->addChild(banTaoLayer);

	return true;
}