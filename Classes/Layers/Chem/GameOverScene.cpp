#include "GameOverScene.h"
#include "ChemLayer.h"

USING_NS_CC;

bool GameOverScene::init()
{
    if( Scene::init() )
    {
        this->_layer = GameOverLayer::create();
        this->_layer->retain();
        this->addChild(_layer);
        return true;
    }
    else
    {
        return false;
    }
}

GameOverScene::~GameOverScene()
{
    if (_layer)
    {
        _layer->release();
        _layer = NULL;
    }
}


bool GameOverLayer::init()
{
    if ( LayerColor::initWithColor(Color4B(255,255,255,255)) )
    {
        Size winSize = Director::getInstance()->getWinSize();
		
        this->_label = LabelTTF::create("","Artial", 32);
        _label->retain();
        _label->setColor(Color3B (0, 0, 0));		
        _label->setPosition(Point(winSize.width/2, winSize.height/2));
        this->addChild(_label,1);				
		//this->runAction( Sequence::create(
								//DelayTime::create(3),
								//CallFuncN::create(CC_CALLBACK_1(GameOverLayer::gameOverDone,this)), 
								//NULL) );
								
								this->runAction( Sequence::create(
                                DelayTime::create(3),
                                CallFunc::create(this, 
                                callfunc_selector(GameOverLayer::gameOverDone)),
                                NULL)); // Gọi hàm game OverDone

        return true;
    }
    else
    {
        return false;
    }
	

}

void GameOverLayer::gameOverDone()
{
    Director::getInstance()->replaceScene(HelloWorld::createScene()); // Tạo 1 Game Scene mới
}

GameOverLayer::~GameOverLayer()
{
    if (_label)
    {
        _label->release();
        _label = NULL;
    }
}
