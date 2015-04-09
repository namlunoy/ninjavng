#ifndef _BANTAO_HUDLAYER_
#define _BANTAO_HUDLAYER_
#include "cocos2d.h"
#include "Utility/Config.h"


/**
* The layer displays the current score.
*/
class BanTao_HudLayer : public cocos2d::CCLayer
{
public:
	BanTao_HudLayer();
	bool init();
	void updateScore(int score);

	// implement the "static node()" method manually
	CREATE_FUNC(BanTao_HudLayer);

private:
	/**
	* This label is used to show the current score.
	*/
	cocos2d::CCLabelTTF* __pScoreLabel;
};

#endif /* HUDLAYER_H_ */

