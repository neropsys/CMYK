#pragma once
#include "cocos2d.h"
class SquareSprite : public cocos2d::Sprite {
protected:
	SquareSprite();
	SquareSprite* sprite;
	virtual ~SquareSprite();
	virtual void addEvents()=0;
	virtual void initOptions();
	cocos2d::Size visibleSize;
};
