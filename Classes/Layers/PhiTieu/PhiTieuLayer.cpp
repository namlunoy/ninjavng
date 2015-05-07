#include "PhiTieuLayer.h"
#include "Scenes/PhiTieuScene.h"

PhiTieuLayer* PhiTieuLayer::instance = NULL;
PhiTieuLayer::PhiTieuLayer() {
	PhiTieuLayer::instance = this;
}
PhiTieuLayer::~PhiTieuLayer() {
}

void PhiTieuLayer::matMau()
{
	if(mang > 0)
	{
		mang--;
		_hudLayer->matMau();
	}

	if(mang == 0)
	{
		gameOver();
	}
}

bool PhiTieuLayer::init() {
	mang = 3;



	//-------  Background ----------
	//Thực hiện : Hiển thị, Thêm body
	_background = Sprite::create("cong_background.jpg");
	_background->setPosition(Config::centerPoint);
	theScale = Config::getScale(_background);
	_background->setScale(theScale);
	this->addChild(_background, -1);

	//--------  Các đường bao --------
	this->addChild(BoundWall::createWall(WallType::UP, Config::screenSize));
	this->addChild(BoundWall::createWall(WallType::DOWN, Config::screenSize));
	this->addChild(BoundWall::createWall(WallType::LEFT, Config::screenSize));
	this->addChild(BoundWall::createWall(WallType::RIGHT, Config::screenSize));

	//-----------  Thêm cái đích để cán vào ------------
	Node* Target = Node::create();
	PhysicsBody* _targetBody = PhysicsBody::createBox(Size(5, 700),PhysicsMaterial(1, 0, 0));
	_targetBody->setTag(Tags::TARGET);
	_targetBody->setDynamic(false);
	_targetBody->setContactTestBitmask(true);
	_targetBody->setCollisionBitmask(true);
	Target->setPhysicsBody(_targetBody);
	Target->setPosition(10, 100);
	this->addChild(Target);

	//---------- ninja  -----------
	ninja = Ninja::create("Ninja2.png");
	ninja->setPosition(Vec2(100, 100));
	ninja->setOriginalPosition(Vec2(100, 100));
	ninja->runAnimation_DungYen();
	this->addChild(ninja);

	//Thực hiện sinh các quân địch
	Enemy_Jump* e = Enemy_Jump::create(1);
	this->addChild(e);

	//---------------  Các trái tim -------------------
	generator = new Generator(this);
	this->addChild(generator);
	generator->Generate(PhiTieuScene::GetLevel());

	return true;
}

void PhiTieuLayer::setPhysicWorld(PhysicsWorld* physicsWorld) {
	_physicWorld = physicsWorld;
}

void PhiTieuLayer::Jump() {
	ninja->jump();
}

void PhiTieuLayer::PhongTieu(Vec2 dest) {
	//ninja->fire(ninja->getPosition(),dest);
	Vec2 src = ninja->getPosition();
	ninja->fire(src,dest);

}

void PhiTieuLayer::setHUDLayer(PhiTieuHUDLayer* p) {
	_hudLayer = p;
}

void PhiTieuLayer::gameOver() {
	ninja->isAlive = false;
	generator->stop();
	_hudLayer->gameOver();
}
