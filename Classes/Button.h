#pragma once
#include "cocos2d.h"
#include "SquareSprite.h"
#include "Variable.h"
#include <string>

class Button : public SquareSprite{
public:
	static Button* create(const cocos2d::Color3B& color, const cocos2d::Vec2& position = cocos2d::Vec2(0, 0));
	~Button();
	void resetProperty();
private:
	void addEvents(SquareSprite*) override;
	cocos2d::Vec2 initPos;
	cocos2d::Vec2 initAnchor;
	Button();
	Button(const Button&);

};