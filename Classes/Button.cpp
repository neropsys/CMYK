#include "Button.h"
USING_NS_CC;
using namespace std;
Button::Button(){}

Button::Button(const string& name, const Color3B& color, const Vec2& anchor):SquareSprite(color){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	sprite->setAnchorPoint(anchor);
	sprite->setName(name);
	this->name = name;
	if (anchor == Vec2::ANCHOR_TOP_LEFT)
		sprite->setPosition(0, visibleSize.height);
	else if (anchor == Vec2::ANCHOR_TOP_RIGHT)
		sprite->setPosition(visibleSize.width, visibleSize.height);
	else if (anchor == Vec2::ANCHOR_BOTTOM_LEFT)
		sprite->setPosition(0, 0);
	else if (anchor == Vec2::ANCHOR_BOTTOM_RIGHT)
		sprite->setPosition(visibleSize.width, 0);
	else
		sprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	initPos = sprite->getPosition();
}
string Button::getName(){
	return name;
}
Vec2 Button::getSpritePos(){
	return sprite->getPosition();
}
void Button::easeResetPos(){
	auto move = MoveTo::create(0.5f, initPos);
	auto ease_out = EaseOut::create(move, 4.f);
	sprite->runAction(ease_out);
	
}
Button::~Button(){
	sprite->release();
	log("button destructor called");
}
Sprite* Button::getSprite(){
	return sprite;
}
void Button::resetPos(){
	sprite->setPosition(initPos);
}