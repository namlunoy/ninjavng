/*
 * Lớp này có thể coi là controller đề quản lý các đối tượng chính tham gia vào trong game
 *
 *
 */
#ifndef _PHITIEU_LAYER_
#define _PHITIEU_LAYER_

#include "cocos2d.h"
#include "Utility/Config.h"
#include "Models/PhiTieu/Shuriken.h"
#include "Models/PhiTieu/Ninja.h"

#include "Utility/Tags.h"

USING_NS_CC;

class PhiTieuLayer : public Layer
{
private:
	Sprite* _background;
	PhysicsWorld* _physicWorld;
private:
	Ninja* ninja;

public:
	//----- Các phương thức khởi tạo -------
	PhiTieuLayer();
	~PhiTieuLayer();
	CREATE_FUNC(PhiTieuLayer);
	bool init();

	//------  Các phương thức chính ------
	void setPhysicWorld(PhysicsWorld* physicsWorld);
	void Jump();
	void PhongTieu(Vec2 dest);

	//---------------- Ngoài lề --------------
	float theScale;
};
#endif

