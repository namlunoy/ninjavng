#include "ScoreNode.h"
#include "Utility/Definition.h"

ScoreNode::ScoreNode()
{
	node = Node::create();
	this->addChild(node);
	body = PhysicsBody::createBox(Size(50, 2), PhysicsMaterial(1, 0, 1));
	body->setDynamic(false);
	body->setCollisionBitmask(SCORE_COLLISION);
	body->setContactTestBitmask(true);
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