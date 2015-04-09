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

	// Ask director the window size.
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	// Create the score label.
	__pScoreLabel = LabelTTF::create("Score: 0", "Arial", 30);

	// Position the label on the right side of the screen.
	__pScoreLabel->setPosition(ccp(winSize.width - 100, winSize.height - 20));

	// Add the label as a child to this layer.
	this->addChild(__pScoreLabel, 1);

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
