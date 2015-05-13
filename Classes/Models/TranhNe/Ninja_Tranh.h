#ifndef _Ninja_Tranh_
#define _Ninja_Tranh_
#include "cocos2d.h"
#include "Utility/Config.h"
USING_NS_CC;
using namespace std;
class Ninja_Tranh : public Node
{
public:
	static Ninja_Tranh* Tao_Ninja_Tranh(string _File_Name);
	Ninja_Tranh();
	~Ninja_Tranh();
	bool init(string _File_Name);
	void Di_Chuyen(float Dich_X, float Dich_Y);
	void Nhay(float Dich_X, float  Dich_Y);
	Sprite* _Sprite;
	PhysicsBody* Body_Ninja;
	int So_Mang;
};
#endif