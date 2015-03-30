#ifndef __BANSUNG_SCENE_H__
#define __BANSUNG_SCENE_H__

#include "cocos2d.h"

class BanSung : public cocos2d::Layer
{
public:
  
    static cocos2d::Scene* createScene();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(BanSung);
	void onStart();

public:

	BanSung(); // Hàm tạo
	~BanSung(); // Hàm hủy
};

#endif // __HELLOWORLD_SCENE_H__
