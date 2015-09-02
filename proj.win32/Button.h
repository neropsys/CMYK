#pragma once
#include "cocos2d.h"

class Button{
public:
	Button(const cocos2d::Color3B& color, const cocos2d::Vec2& anchor);
	cocos2d::Sprite* getSprite();
	//void SetPosition(const )
private:
	cocos2d::Sprite* sprite;
	Button();
	Button(const Button&);

};