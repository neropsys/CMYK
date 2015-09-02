#pragma once
#include "cocos2d.h"
#include "SquareSprite.h"
#include <string>
#define VISIBLENBUTTONSIZE 100 //width & height of CMYK button on the screen

class Button : SquareSprite{
public:
	Button(const std::string& name, const cocos2d::Color3B& color, const cocos2d::Vec2& anchor);
	cocos2d::Sprite* getSprite();
	void resetPos();
	void easeResetPos();
	~Button();
	cocos2d::Vec2 getSpritePos();
	std::string getName();
private:
	cocos2d::Vec2 initPos;
	std::string name;
	Button();
	Button(const Button&);
	void doActionReset();

};