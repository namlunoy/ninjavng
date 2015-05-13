#ifndef _Giun_Dat_
#define _Giun_Dat_
#include "cocos2d.h"
#include "Utility/Config.h"
USING_NS_CC;
using namespace std;
class Giun_Dat : public Node
{
public:
	static Giun_Dat* Tao_Giun_Dat(string _File_Name);
	Giun_Dat();
	~Giun_Dat();
	bool init(string _File_Name);
	void Quet_Dat(float Dich_X);
	Sprite* _Sprite;
	PhysicsBody* Body_Giun;
};
#endif