#ifndef _SCORE_
#define _SCORE_
#include "cocos2d.h"
USING_NS_CC;

class ScoreNode : public Node
{
public:
	ScoreNode();
	~ScoreNode();
	//int score;
	Node * node;
	PhysicsBody * body;
	bool init();
	static ScoreNode * createScoreNode();
};

#endif //_SCORE_