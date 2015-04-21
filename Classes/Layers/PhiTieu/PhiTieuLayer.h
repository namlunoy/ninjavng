/*
 * Lớp này có thể coi là controller đề quản lý các đối tượng chính tham gia vào trong game
 *
 *
 */
#ifndef _PHITIEU_LAYER_
#define _PHITIEU_LAYER_

#include "cocos2d.h"

#include "Utility/Config.h"
#include "Utility/Tags.h"

#include "Models/PhiTieu/Shuriken.h"
#include "Models/PhiTieu/Ninja.h"
#include "Models/PhiTieu/BoundWall.h"
#include "Models/PhiTieu/Enemy_Run.h"
#include "Models/PhiTieu/Enemy_Jump.h"

#include "PhiTieuHUDLayer.h"
#include "Generator.h"


USING_NS_CC;

class PhiTieuHUDLayer;
class Generator;

class PhiTieuLayer : public Layer
{
private:
	Sprite* _background;
	PhysicsWorld* _physicWorld;
	PhiTieuHUDLayer* _hudLayer;
private:
	Ninja* ninja;
	int mang;
public:
	//----- Các phương thức khởi tạo -------
	PhiTieuLayer();
	~PhiTieuLayer();
	CREATE_FUNC(PhiTieuLayer);
	bool init();
	void setHUDLayer(PhiTieuHUDLayer* p);
	static PhiTieuLayer* instance;

	//------  Các phương thức chính ------
	void setPhysicWorld(PhysicsWorld* physicsWorld);
	void Jump();
	void PhongTieu(Vec2 dest);
	void matMau();

	//---------------- Ngoài lề --------------
	float theScale;
};
#endif

