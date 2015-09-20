#pragma once
#include "cocos2d.h"
#include "SquareSprite.h"
#include "Variable.h"
#include <string>

class Button : SquareSprite{
public:
	Button(const std::string& name, const cocos2d::Color3B& color, const cocos2d::Vec2& position = 0);
	~Button();
	void resetProperty();
private:
	void touchEvent(cocos2d::Touch* touch, cocos2d::Vec2 point) override;
	void addEvents() override;
	cocos2d::Vec2 initPos;
	cocos2d::Vec2 initAnchor;
	Button();
	Button(const Button&);

};