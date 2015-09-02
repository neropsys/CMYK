#pragma once
#include "cocos2d.h"
class SquareSprite abstract : public cocos2d::Node {
public:
	virtual cocos2d::Sprite* getSprite() abstract;
	void setPosition(float x, float y) override;
protected:
	cocos2d::Sprite* sprite;
	SquareSprite();
	SquareSprite(const cocos2d::Color3B& color);
	virtual ~SquareSprite();
};
