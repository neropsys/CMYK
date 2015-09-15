#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "MainScene.h"
USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

Resource AppDelegate::smallResource = { cocos2d::CCSizeMake(480, 320), "iphone" };
Resource AppDelegate::mediumResource = { cocos2d::CCSizeMake(1024, 768), "ipad" };
Resource AppDelegate::largeResource = { cocos2d::CCSizeMake(2048, 1536), "ipadhd" };
Resource AppDelegate::resource_16_9 = { cocos2d::CCSizeMake(1920, 1080), "qhd" };
CCSize AppDelegate::designResolutionSize = cocos2d::CCSizeMake(1280, 720);
//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
		glview->setFrameSize(designResolutionSize.width, designResolutionSize.height);
        director->setOpenGLView(glview);

		glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);
    }


	CCSize frameSize = glview->getFrameSize();

	/*if (frameSize.height < resource_16_9.size.height){
		director->setContentScaleFactor(largeResource.size.height / designResolutionSize.height);
	}*/


    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    register_all_packages();

    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();
	//Todo:
	//http://www.cocos2d-x.org/wiki/Multi_resolution_support
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
