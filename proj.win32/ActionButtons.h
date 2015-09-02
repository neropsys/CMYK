#pragma once

#include "cocos2d.h"
#include "Button.h"

class ActionButton{
public:
	static ActionButton* Init();
	void addButtons(cocos2d::Layer* layer);
private:
	ActionButton();
	static ActionButton* buttons;
	static Button* cyan;
	static Button* magenta;
	static Button* yellow;
	static Button* key;
	static cocos2d::Layer* layer;
};