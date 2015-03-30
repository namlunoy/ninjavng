#include "Cong_PhiTieuLayer.h"


Cong_PhiTieuLayer::Cong_PhiTieuLayer() { }
Cong_PhiTieuLayer::~Cong_PhiTieuLayer(){ }


bool Cong_PhiTieuLayer::init()
{
	if (!Layer::init())
		return false;

	Cong_Shuriken* s = new Cong_Shuriken(Vec2(0, 0));
	this->addChild(s);

	return true;
}