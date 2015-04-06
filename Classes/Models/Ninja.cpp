#include "Ninja.h"
#include "Utility/Definition.h"
#include "Utility/Config.h"

Ninja::Ninja(){}
Ninja::~Ninja(){}

Ninja* Ninja::create(string fileName)
{
	Ninja* ninja = new Ninja();
	if (ninja && ninja->init(fileName))
		ninja->autorelease();
	else CC_SAFE_DELETE(ninja);
	return ninja;
}

bool Ninja::init(string fileName)
{
	if (!Node::init())
		return false;

	//Khởi tạo sprite chính
	_sprite = Sprite::create(fileName);
	_sprite->setPosition(0, 0);
	this->addChild(_sprite);

	//Thêm body
	_body = PhysicsBody::createBox(Size(_sprite->getBoundingBox().size.width, _sprite->getBoundingBox().size.height),
		PhysicsMaterial(1.0f, 0.0f, 0.0f));
	this->setPhysicsBody(_body);

	return true;
}

void Ninja::runAnimation(string name, int count, float time, bool isRepeat)
{
	XHelper::runAnimation(name, count, time, true, this->_sprite);
}

//-------------------- Công -------------------------
void Ninja::addPlistFile(string fileName)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(fileName);
}

void Ninja::runAnimation_DungYen()
{
	runAnimation("DungYen", 2, 0.5f, true);
}

void Ninja::runAnimation_Nhay()
{
	//runAnimation("ninja_nhay", 2, 0.5f, true);
}


//--------------------- Đăng ------------------------
Ninja::Ninja(Layer* layer)
{
	auto ninja = Sprite::create("Ninja2.png");
	ninja->setPosition(100,200);
	bodyNinja = PhysicsBody::createBox(Size(50,50), PhysicsMaterial(1.0f,0.0f,0.0f));
//	bodyNinja->setCollisionBitmask(NINJA_COLLISION);
//	bodyNinja->setContactTestBitmask(true);
	//bodyNinja->setDynamic(false);
	ninja->setPhysicsBody(bodyNinja);
	layer->addChild(ninja);
}

void Ninja::jumpAction()
{
	/*auto jump = JumpTo::create(1.5, Vec2(800,640), 50, 1);
	this->runAction(jump);*/
	bodyNinja->applyForce(Vect(0, 2000));
	this->isJumping = true;
	CCLOG("___%d", this->isJumping);
}

