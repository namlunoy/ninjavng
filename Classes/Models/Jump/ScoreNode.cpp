#include "ScoreNode.h"
#include "Utility/Config.h"
#include "Utility/Definition.h"

//int score = 0;
ScoreNode::ScoreNode()
{
	node = Node::create();
	this->addChild(node);
	body = PhysicsBody::createBox(Size(30, (Config::screenSize.height * 2) ), PhysicsMaterial(1, 0, 1));
	body->setDynamic(false);
	body->setCollisionBitmask(0x02);
	//body->setTag(SCORE_COLLISION);
	body->setContactTestBitmask(true);
	body->setCategoryBitmask(0x01);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setPhysicsBody(body);
}

ScoreNode::~ScoreNode()
{

}

bool ScoreNode::init()
{
	if (!Node::init())
		return false;

	return true;
}

ScoreNode* ScoreNode::createScoreNode()
{
	ScoreNode* scoreNode = new ScoreNode();
	scoreNode->init();
	scoreNode->autorelease();
	return scoreNode;
}