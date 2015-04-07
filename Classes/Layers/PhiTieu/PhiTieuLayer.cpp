#include "PhiTieuLayer.h"
#include "Utility/Tags.h"

PhiTieuLayer::PhiTieuLayer() { }
PhiTieuLayer::~PhiTieuLayer(){ }


bool PhiTieuLayer::init()
{
	this->scheduleUpdate();

	//Hiển thị background
	_background = Sprite::create("cong_background.jpg");
	_background->setPosition(Config::centerPoint);
	theScale = Config::getScale(_background);
	_background->setScale(theScale);
	this->addChild(_background, -1);

	//Thêm các body background
	//Body nền đất
	Node* _ground = Node::create();
	_ground->setTag(Tags::GROUND);

	auto _groundBody = PhysicsBody::createBox(Size(Config::screenSize.width, 70),PhysicsMaterial(1.0f, 0.0f, 0.0f));
	_groundBody->setGravityEnable(false);
	_groundBody->setDynamic(false);

	_ground->setPhysicsBody(_groundBody);
	_ground->setPosition(Vec2(Config::screenSize.width/2, 0));
	this->addChild(_ground);


	//Theem ninja
	ninja = Ninja::create("Ninja2.png");
	ninja->setPosition(Vec2(100,100));
	ninja->runAnimation_DungYen();
	this->addChild(ninja);
	
//
//
	//Sự kiện key board
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(PhiTieuLayer::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
//
//
//	//Thêm button nhảy
//	log("TEst thử");

	return true;
}

void PhiTieuLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	ninja->jump();
}

void PhiTieuLayer::setPhysicWorld(PhysicsWorld* physicsWorld)
{
	_physicWorld = physicsWorld;
}

void PhiTieuLayer::update(float dt)
{
	
}

