#include "JumpLayer.h"
#include "cocos2d.h"
#include "Models/Jump/Ninja_D.h"
#include "Utility/Config.h"
#include "Utility/Definition.h"
#include "Models/Jump/Pillar.h"
#include "Models/Jump/Spring.h"
#include "Models/Jump/ScoreNode.h"
#include <iostream>
#include <list>
USING_NS_CC;

JumpLayer::~JumpLayer(){}
JumpLayer::JumpLayer()
{
	firstSpawnPoint = Point(100, 0);
	firstPillar = listPillar.begin();
}

bool JumpLayer::init()
{
	if (!Layer::init()) return false;

	//Tạo tường xung quanh
	Node * wall = Node::create();
	wall->setPosition(Point(1, 240));
	PhysicsBody * wallBody = PhysicsBody::createEdgeBox(Size(1, 480));
	wallBody->setDynamic(false);
	wallBody->setCollisionBitmask(true);
	wallBody->setContactTestBitmask(true);
	wallBody->setTag(WALL_COLLISION);
	wall->setPhysicsBody(wallBody);
	this->addChild(wall);

	//Ground
	Node * ground = Node::create();
	ground->setPosition(Point(400, 1));
	PhysicsBody * groundBody = PhysicsBody::createBox(Size(800, 1));
	groundBody->setDynamic(false);
	groundBody->setCollisionBitmask(true);
	groundBody->setTag(GROUND_COLLISION);
	groundBody->setContactTestBitmask(true);
	ground->setPhysicsBody(groundBody);
	this->addChild(ground, 0);

	//Pillar
	pillar = Pillar::createPillar();
	pillar->setPosition(100, 0);
	this->addChild(pillar);
	listPillar.push_front(pillar);
	firstPillar = listPillar.begin();

	//Ninja
	ninja = Ninja_D::createNinja();
	ninja->setPosition(100, 216);
	this->addChild(ninja);

	//Score
	Sprite * circle = Sprite::create("circle.png");
	circle->setPosition(Point(Config::screenSize.width / 2, Config::screenSize.height / 2 + 180));
	circle->setOpacity(200);
	circle->setScale(0.5);

	scoreText = Label::create("0", "fonts/Marker Felt.ttf", 85 ,Size::ZERO, TextHAlignment::CENTER, TextVAlignment::CENTER);
	scoreText->setPosition(circle->getContentSize().width/2, circle->getContentSize().height/2);
	scoreText->setColor(Color3B::BLACK);
	scoreText->setOpacity(200);

	circle->addChild(scoreText);
	this->addChild(circle);


	return true;
}

void JumpLayer::UpdatePillar()
{
	if ((1200 - (*firstPillar)->getPositionX()) > DISTANCE_SPAWN_MAX)
	{
		float randomX = cocos2d::random(DISTANCE_SPAWN_MIN, DISTANCE_SPAWN_MAX);
		SpawnPillarWithPos(Point((*firstPillar)->getPositionX() + randomX, CCRANDOM_0_1() * 175));
	}
	firstPillar = listPillar.begin();
}

void JumpLayer::SpawnPillar()
{
	Point pos = Point(Config::screenSize.width, CCRANDOM_0_1() * 175);
	Pillar *p = Pillar::createPillar();	
	p->setPosition(pos);
	this->addChild(p);
	listPillar.push_front(p);
}

void JumpLayer::SpawnPillarWithPos(Point pos)
{
	Pillar *p = Pillar::createPillar();
	p->setPosition(pos);

	ScoreNode * scorenode = ScoreNode::createScoreNode();
	scorenode->setPosition(Point(0, 175));
	p->addChild(scorenode);

	this->addChild(p);
	listPillar.push_front(p);
}

void JumpLayer::MovePillar(float duration)
{
	for (std::list<Pillar*>::iterator it = listPillar.begin(); it != listPillar.end(); ++it)
	{
		(*it)->MovePillar(duration);
	}
}

void JumpLayer::StopPillar()
{
	for (std::list<Pillar*>::iterator it = listPillar.begin(); it != listPillar.end(); ++it)
	{
		(*it)->StopPillar();
	}
}