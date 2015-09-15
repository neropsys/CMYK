#include "MainScene.h"
using namespace cocos2d;

Scene* MainScene::createScene()
{
	auto scene = Scene::create();

	auto layer = MainScene::create();
	scene->addChild(layer);

	return scene; 

}
void MainScene::onEnter(){
	Layer::onEnter();

}

bool MainScene::init(){
	if (!LayerColor::initWithColor(Color4B::WHITE)){
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();

	auto logo = Sprite::create("CMYK_logo.png");
	logo->setAnchorPoint(Vec2(0.5, 0.5));
	logo->setScale(0.5);
	logo->runAction(RepeatForever::create(RotateBy::create(5, 360)));
	this->addChild(logo);
	logo->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	return true;
}

void MainScene::onExit(){
	_eventDispatcher->removeAllEventListeners();

	Layer::onExit();
}