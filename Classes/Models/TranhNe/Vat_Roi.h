#ifndef _Vat_Roi_
#define _Vat_Roi_
#include "cocos2d.h"
#include "Utility/Config.h"
USING_NS_CC;
using namespace std;
class Vat_Roi : public Node
{
public:
	static Vat_Roi* Tao_Vat_Roi(string _File_Name);
	Vat_Roi();
	~Vat_Roi();
	bool init(string _File_Name);
	void Roi(float Dich_Y);
	Sprite* _Sprite;
	PhysicsBody* Body_VR;
	int So_VR;
};
#endif