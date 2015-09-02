#include "ActionButtons.h"
USING_NS_CC;


ActionButton::ActionButton(){}
ActionButton* ActionButton::Init(){
	if (!buttons){
		buttons = new ActionButton();
		buttons->cyan = new Button(Color3B(0, 255, 255), Vec2::ANCHOR_TOP_LEFT);
		buttons->magenta = new Button(Color3B::MAGENTA, Vec2::ANCHOR_TOP_RIGHT);
		buttons->yellow = new Button(Color3B::YELLOW, Vec2::ANCHOR_BOTTOM_LEFT);
		buttons->key = new Button(Color3B::BLACK, Vec2::ANCHOR_BOTTOM_RIGHT);
	}
	return buttons;
}

void ActionButton::addButtons(Layer* layer){
	layer->addChild(cyan->getSprite());
	layer->addChild(magenta->getSprite());
	layer->addChild(yellow->getSprite());
	layer->addChild(key->getSprite());
}