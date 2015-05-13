#ifndef _VatRoi_
#define _VatRoi_

#include "cocos2d.h"
#include <iostream>
#include "Utility/Config.h"

USING_NS_CC;
using namespace std;

class VatRoi : public Node
{
public:
	static VatRoi* Tao_VatRoi(std::string File_Name);
	VatRoi();
	~VatRoi();
	bool init(string File_Name);
	void Roi(float Dich_Y);
	Sprite* _Sprite;
	PhysicsBody* Body_VR;
	int So_VR;
};

#endif
