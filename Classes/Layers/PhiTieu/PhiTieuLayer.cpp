#include "PhiTieuLayer.h"
#include "Scenes/PhiTieuScene.h"
#include "SimpleAudioEngine.h"
#include "Scenes/HelloWorldScene.h"

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



	//Back button
	this->setKeypadEnabled(true);
	this->setKeyboardEnabled(true);

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
	_targetBody->setDynamic(true);
	_targetBody->setGravityEnable(false);
	_targetBody->setContactTestBitmask(true);
	_targetBody->setCollisionBitmask(true);
	Target->setPhysicsBody(_targetBody);
	Target->setPosition(20, Config::screenSize.height/2);
	this->addChild(Target);

	//---------- ninja  -----------
	ninja = Ninja::create("Ninja2.png");
	ninja->setPosition(Vec2(100, 100));
	ninja->setOriginalPosition(Vec2(100, 100));
	ninja->runAnimation_DungYen();
	this->addChild(ninja);

	//Thực hiện sinh các quân địch
	Enemy_Jump* e = Enemy_Jump::create();
	this->addChild(e);

	//---------------  Các trái tim -------------------
	generator = new Generator(this);
	this->addChild(generator);
	generator->Generate(PhiTieuScene::GetLevel());
//	this->setScale(Config::getScaleSize());
	return true;
}

void PhiTieuLayer::setPhysicWorld(PhysicsWorld* physicsWorld) {
	_physicWorld = physicsWorld;
}

void PhiTieuLayer::Jump() {
	if (ninja->isAlive)
		ninja->jump();
}

void PhiTieuLayer::PhongTieu(Vec2 dest) {
	//ninja->fire(ninja->getPosition(),dest);
	if (ninja->isAlive)
	{
		Vec2 src = ninja->getPosition();
		ninja->fire(src, dest);
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound_PhiTieu/Shuriken.mp3");
	}
}

void PhiTieuLayer::setHUDLayer(PhiTieuHUDLayer* p) {
	_hudLayer = p;
}

void PhiTieuLayer::gameOver() {
	ninja->isAlive = false;
	generator->gameOver();
	_hudLayer->gameOver();
	ninja->setVisible(false);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound_PhiTieu/GameOverSound.mp3");
}


void PhiTieuLayer::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
	{
		auto scene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene, Color3B::WHITE));
	}
}

