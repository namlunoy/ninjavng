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

JumpLayer::~JumpLayer()
{

}

JumpLayer::JumpLayer()
{
	firstSpawnPoint = Point(100, 0);
	firstPillar = listPillar.begin();
}

bool JumpLayer::init()
{
	if (!Layer::init()) return false;

	//Tạo tường
	Node * wall = Node::create();
	wall->setPosition(Point(1, 240));
	PhysicsBody * wallBody = PhysicsBody::createBox(Size(1, 480));
	wallBody->setDynamic(false);
	wallBody->setCollisionBitmask(true);
	wallBody->setContactTestBitmask(true);
	wallBody->setTag(WALL_COLLISION);
	wallBody->setCategoryBitmask(0x03);
	wall->setPhysicsBody(wallBody);
	wall->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->addChild(wall);

	//Ground
	Node * ground = Node::create();
	ground->setPosition(Point(400, 1));
	PhysicsBody * groundBody = PhysicsBody::createBox(Size(800, 20));
	groundBody->setDynamic(false);
	groundBody->setCollisionBitmask(true);
	groundBody->setTag(GROUND_COLLISION);
	groundBody->setContactTestBitmask(true);
	ground->setPhysicsBody(groundBody);
	ground->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->addChild(ground, 0);

	//Pillar
	pillar = Pillar::createPillar();
	pillar->setPosition(100, 0);
	pillar->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->addChild(pillar);
	listPillar.push_front(pillar);
	firstPillar = listPillar.begin();

	//Ninja
	ninja = Ninja_D::createNinja();
	ninja->setPosition(100, 216);
	ninja->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->addChild(ninja);

	//Score
	Sprite * circle = Sprite::create("circle.png");
	circle->setPosition(Point(Config::screenSize.width / 2, Config::screenSize.height / 2 + 180));
	circle->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	circle->setOpacity(200);
	circle->setScale(0.5);

	scoreText = Label::create("0", "fonts/Vnhatban.TTF", 85 ,Size::ZERO, TextHAlignment::CENTER, TextVAlignment::CENTER);
	scoreText->setPosition(circle->getContentSize().width/2, circle->getContentSize().height/2);
	scoreText->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	scoreText->setColor(Color3B::BLACK);
	scoreText->setOpacity(200);

	circle->addChild(scoreText);
	this->addChild(circle);


	return true;
}

void JumpLayer::SetPhysicsWorld(PhysicsWorld *world)
{
	this->physicsWorld = world;
}

void JumpLayer::UpdatePillar()
{
	firstPillar = listPillar.begin();
	if ((1200 - (*firstPillar)->getPositionX()) > DISTANCE_SPAWN_MAX)
	{
		float randomX = cocos2d::random(DISTANCE_SPAWN_MIN, DISTANCE_SPAWN_MAX);
		SpawnPillarWithPos(Point((*firstPillar)->getPositionX() + randomX, CCRANDOM_0_1() * 175));
	} 
}

void JumpLayer::SpawnPillarWithPos(Point pos)
{
	//Pillar
	Pillar *p = Pillar::createPillar();
	p->setPosition(pos);
	p->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	//xScore
	ScoreNode * scorenode = ScoreNode::createScoreNode();
	scorenode->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	scorenode->setPosition(Point(0, 575));
	p->addChild(scorenode);

	//Score
	Node * nodeDiem = Node::create();
	PhysicsBody * bodyNodeDiem = PhysicsBody::createBox(Size(28.5, 1), PhysicsMaterial(1.0f, 0.0f, 1.0f));
	bodyNodeDiem->setDynamic(false);
	bodyNodeDiem->setCollisionBitmask(true);
	bodyNodeDiem->setContactTestBitmask(true);
	bodyNodeDiem->setTag(SCORE_COLLISION);
	nodeDiem->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	nodeDiem->setPhysicsBody(bodyNodeDiem);
	nodeDiem->setPosition(Point(0,175.5));
	p->addChild(nodeDiem);

	//Addchild
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
