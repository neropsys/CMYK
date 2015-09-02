#include "Button.h"
USING_NS_CC;
using namespace std;
Button::Button(){}

Button::Button(const string& name, const Color3B& color, const Vec2& anchor):SquareSprite(color){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	sprite->setAnchorPoint(anchor);
	sprite->setName(name);
	sprite->setScale(2.f);
	this->name = name;
	if (anchor == Vec2::ANCHOR_TOP_LEFT)
		sprite->setPosition(visibleSize.width - VISIBLENBUTTONSIZE, VISIBLENBUTTONSIZE);
	else if (anchor == Vec2::ANCHOR_TOP_RIGHT)
		sprite->setPosition(VISIBLENBUTTONSIZE, VISIBLENBUTTONSIZE);
	else if (anchor == Vec2::ANCHOR_BOTTOM_LEFT)
		sprite->setPosition(visibleSize.width - VISIBLENBUTTONSIZE, visibleSize.height - VISIBLENBUTTONSIZE);
	else if (anchor == Vec2::ANCHOR_BOTTOM_RIGHT)
		sprite->setPosition(VISIBLENBUTTONSIZE, visibleSize.height - VISIBLENBUTTONSIZE);
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