#include "BanTao_HudLayer.h"

USING_NS_CC;

BanTao_HudLayer::BanTao_HudLayer() :
__pScoreLabel(NULL)
{
}

bool BanTao_HudLayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	__pScoreLabel = LabelTTF::create("Score: 0", "Arial", 30);
	__pScoreLabel->setPosition(ccp(winSize.width - 100, winSize.height - 20));
	/*this->addChild(__pScoreLabel, 1);*/

	return true;
}

/**
* Set the new score label value.
*/
void BanTao_HudLayer::updateScore(int score)
{
	const int labelLength = 100;
	char scoreLabelText[labelLength];
	snprintf(scoreLabelText, labelLength, "Score: %d", score);
	__pScoreLabel->setString(scoreLabelText);
}
