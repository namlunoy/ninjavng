#ifndef GAMEOVERSCENEH_
#define GAMEOVERSCENEH_

#include "cocos2d.h"
USING_NS_CC;

class GameOverLayer : public cocos2d::LayerColor
{
public:
GameOverLayer():_label(NULL) {};
virtual ~GameOverLayer();
virtual bool init();

CREATE_FUNC(GameOverLayer);

void gameOverDone();

CC_SYNTHESIZE_READONLY(cocos2d::LabelTTF*, _label, Label); //tạo ra 1 biến _label có kiểu LabelTTF* thông qua 1 phương thức của lớp Label

};

class GameOverScene : public cocos2d::Scene
{
public:
GameOverScene():_layer(NULL) {};
~GameOverScene();
virtual bool init();
CREATE_FUNC(GameOverScene);

CC_SYNTHESIZE_READONLY(GameOverLayer*, _layer, Layer); //tạo ra 1 biến _layer có kiểu GameOverLayer* thông qua 1 phương thức của lớp Layer

};

#endif // GAMEOVERSCENEH_