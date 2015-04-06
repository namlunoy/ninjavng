#include "PhiTieuLayer.h"
#include "Utility/Tags.h"

PhiTieuLayer::PhiTieuLayer() { }
PhiTieuLayer::~PhiTieuLayer(){ }


bool PhiTieuLayer::init()
{

	//Hiển thị background
	_background = Sprite::create("cong_background.jpg");
	_background->setPosition(Config::centerPoint);
	theScale = Config::getScale(_background);
	_background->setScale(theScale);
	this->addChild(_background, -1);

	//Thêm các body background
	//Body nền đất
	Node* b = Node::create();
	b->setTag(Tags::GROUND);


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
	log("Key with keycode %d pressed", keyCode);
}

void PhiTieuLayer::setPhysicWorld(PhysicsWorld* physicsWorld)
{
	_physicWorld = physicsWorld;
}

