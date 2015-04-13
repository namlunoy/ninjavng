#include "Pillar.h"
#include "Utility/Definition.h"
#include "Utility/Config.h"
#include "cocos2d.h"
#include "stdint.h"

#pragma region Constructor
Pillar::Pillar()
{

}

Pillar::Pillar(Sprite *pillar, float heightRandom, Point position, PhysicsBody *bodyPillar)
{
	this->pillar = pillar;
	this->heightRandom = heightRandom;
	this->position = position;
	this->bodyPillar = bodyPillar;
}
#pragma endregion

#pragma  region Get-Set
void Pillar::SetPillar(Sprite *sprite)
{
	this->pillar = sprite;
}

Sprite* Pillar::GetPillar()
{
	return pillar;
}

void Pillar::SetHeightRandom(float height)
{
	this->heightRandom = height;
}

float Pillar::GetHeightRandom()
{
	return heightRandom;
}

void Pillar::SetPosition(Point position)
{
	this->position = position;
}

Point Pillar::GetPosition()
{
	return position;
}

void Pillar::SetPhysicsBody(PhysicsBody *physicsBody)
{
	this->bodyPillar = physicsBody;
}

PhysicsBody* Pillar::GetPhysicsBody()
{
	return bodyPillar;
}
#pragma  endregion

#pragma region Method
void Pillar::SpawnPillar(Layer *layer)
{
	layer->addChild(this);
}
//void Pillar::SpawnPillar(Layer *layer, Point spawnPosition, int order)
//{
//	auto pillar = Sprite::create("building.png");
//	if (order == 1)
//	{
//		pillar->setPosition(Point(spawnPosition));
//	}
//	else if (order == 2)
//	{
//		auto randomHeight = CCRANDOM_0_1()*pillar->getContentSize().height / 2;
//		spawnPosition.y = randomHeight;
//		pillar->setPosition(Point(spawnPosition));
//	}
//	auto bodyPillar = PhysicsBody::createEdgeBox(pillar->getContentSize(), PhysicsMaterial(1.0f, 0.0f, 1.0f));
//	bodyPillar->setDynamic(false);
//	pillar->setPhysicsBody(bodyPillar);
//	layer->addChild(pillar);
//}
void Pillar::MovePillar()
{
	auto movePillar = MoveBy::create(Config::screenSize.width*0.005, Vec2(- Config::screenSize.width - 200, 0));
	this->runAction(movePillar);
}

void Pillar::StopPillar()
{
	this->stopAllActions();
}
#pragma endregion 