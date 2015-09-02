#include "Button.h"
USING_NS_CC;

Button::Button(){}

Button::Button(const Color3B& color, const Vec2& anchor){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	sprite = Sprite::create("White_square_small.png");
	sprite->setColor(color);
	sprite->setAnchorPoint(anchor);
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
}
Sprite* Button::getSprite(){
	return sprite;
}
