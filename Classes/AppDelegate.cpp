#include "AppDelegate.h"
#include "Scenes/HelloWorldScene.h"
#include "Scenes/JumpScene.h"
#include "Scenes/Start_Scene.h"
#include "Scenes/BanTao_Scence.h"
#include "Utility/Config.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    Config::screenSize = director->getVisibleSize();

    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		//Chinh kich thuoc tuong ung dien thoai
		//720 x 1280
		glview->setFrameSize(800, 480);
#endif
        director->setOpenGLView(glview);
		glview->setDesignResolutionSize(800, 480, ResolutionPolicy::FIXED_HEIGHT);
    }

    // turn on display FPS
    //director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 180);

    auto scene = HelloWorld::createScene();
    //auto scene = Start_Scene::createStartScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
	
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
