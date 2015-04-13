#include "BoundWall.h"
#include "Utility/Tags.h"

BoundWall* BoundWall::createWall(WallType type, Size size)
{
	BoundWall* wall = new BoundWall(type, size);
	wall->autorelease();
	return wall;
}

BoundWall::BoundWall(WallType type, Size screenSize)
{
	PhysicsBody* body;
	switch (type)
	{
	case UP:
		this->setAnchorPoint(Vec2(0.5f, 0));
		this->setPosition(Vec2(screenSize.width / 2, screenSize.height));
		body = PhysicsBody::createBox(Size(screenSize.width,5), PhysicsMaterial(1, 0, 0));
		break;
	case DOWN:
		this->setAnchorPoint(Vec2(0.5f, 1));
		this->setPosition(Vec2(screenSize.width / 2, 0));
		body = PhysicsBody::createBox(Size(screenSize.width, 5), PhysicsMaterial(1, 0, 0));
		break;
	case LEFT:
		this->setAnchorPoint(Vec2(1, 0.5f));
		this->setPosition(Vec2(0, screenSize.height / 2));
		body = PhysicsBody::createBox(Size(5, screenSize.height), PhysicsMaterial(1, 0, 0));
		break;
	case RIGHT:
		this->setAnchorPoint(Vec2(0, 0.5f));
		this->setPosition(Vec2(screenSize.width, screenSize.height / 2));
		body = PhysicsBody::createBox(Size(5, screenSize.height), PhysicsMaterial(1, 0, 0));
		break;
	default:
		break;
	}
	
	body->setGravityEnable(false);
	body->setDynamic(false);
	body->setTag(Tags::GROUND);
	body->setCollisionBitmask(Tags::GROUND);
	body->setContactTestBitmask(true);
	this->setPhysicsBody(body);
}


BoundWall::~BoundWall()
{
}
