#pragma once
#include "cocos2d.h"
class SquareSprite : public cocos2d::Sprite {
protected:
	SquareSprite();
	virtual ~SquareSprite();
	virtual void addEvents()=0;
	virtual void touchEvent(cocos2d::Touch* touch, cocos2d::Vec2 point);
	cocos2d::Size visibleSize;
};
