#pragma once

#include "cocos2d.h"
#include "Button.h"
#include <string>
class ActionButton{
public:
	static ActionButton* Init();
	void addButtons(cocos2d::Layer* layer, const int& zPos);
	cocos2d::Sprite* getSpriteByName(const std::string&);
	Button* getButtonByName(const std::string&);
	void resetAllButton();
	~ActionButton();
private:
	ActionButton();
	static ActionButton* buttons;
	static Button* cyan;
	static Button* magenta;
	static Button* yellow;
	static Button* key;
};