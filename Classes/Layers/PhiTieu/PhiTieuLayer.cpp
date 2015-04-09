#include "PhiTieuLayer.h"

PhiTieuLayer::PhiTieuLayer() { }
PhiTieuLayer::~PhiTieuLayer(){ }


bool PhiTieuLayer::init()
{

	//-------  Background ----------
	//Thực hiện : Hiển thị, Thêm body
	_background = Sprite::create("cong_background.jpg");
	_background->setPosition(Config::centerPoint);
	theScale = Config::getScale(_background);
	_background->setScale(theScale);
	this->addChild(_background, -1);

	//-------  The Ground -----------
	Node* _ground = Node::create();
	_ground->setTag(Tags::GROUND);
	auto _groundBody = PhysicsBody::createBox(Size(Config::screenSize.width, 70),PhysicsMaterial(1.0f, 0.0f, 0.0f));
	_groundBody->setGravityEnable(false);
	_groundBody->setDynamic(false);
	_ground->setPhysicsBody(_groundBody);
	_ground->setPosition(Vec2(Config::screenSize.width/2, 0));
	this->addChild(_ground);


	//---------- ninja  -----------
	ninja = Ninja::create("Ninja2.png");
	ninja->setPosition(Vec2(100,100));
	ninja->setOriginalPosition(Vec2(100,100));
	ninja->runAnimation_DungYen();
	this->addChild(ninja);



	return true;
}



void PhiTieuLayer::setPhysicWorld(PhysicsWorld* physicsWorld)
{
	_physicWorld = physicsWorld;
}

void PhiTieuLayer::Jump() {
	ninja->jump();
}

void PhiTieuLayer::PhongTieu(Vec2 dest) {
	//Tính toán hướng của phi tiêu
	Vec2 huong = (dest - ninja->getPosition());
	huong.normalize();

	//thực hiện phóng
	auto su = Shuriken::createSuriken();
	su->setPosition(ninja->getPosition());
	su->phong(huong);
	this->addChild(su);
}
