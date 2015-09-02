#include "ActionButtons.h"
USING_NS_CC;
using namespace std;
ActionButton* ActionButton::buttons = nullptr;
Button* ActionButton::cyan = nullptr;
Button* ActionButton::magenta = nullptr;
Button* ActionButton::yellow = nullptr;
Button* ActionButton::key = nullptr;
ActionButton::ActionButton(){}
ActionButton* ActionButton::Init(){
	if (!buttons){
		buttons = new ActionButton();
		buttons->cyan = new Button("cyan", Color3B(0, 255, 255), Vec2::ANCHOR_BOTTOM_RIGHT);
		buttons->magenta = new Button("magenta", Color3B::MAGENTA, Vec2::ANCHOR_BOTTOM_LEFT);
		buttons->yellow = new Button("yellow", Color3B::YELLOW, Vec2::ANCHOR_TOP_RIGHT);
		buttons->key = new Button("key", Color3B::BLACK, Vec2::ANCHOR_TOP_LEFT);
	}
	return buttons;
}
Sprite* ActionButton::getSpriteByName(const std::string& name){
	if (buttons->cyan->getName() == name){
		return buttons->cyan->getSprite();
	}
	else if (buttons->magenta->getName() == name){
		return buttons->magenta->getSprite();
	}
	else if (buttons->yellow->getName() == name){
		return buttons->yellow->getSprite();
	}
	else if(buttons->key->getName() == name){
		return buttons->key->getSprite();
	}
	else return nullptr;
}
void ActionButton::resetAllButton(){
	buttons->cyan->resetPos();
	buttons->magenta->resetPos();
	buttons->yellow->resetPos();
	buttons->key->resetPos();
}
Button* ActionButton::getButtonByName(const std::string& name){
	if (buttons->cyan->getName() == name)
		return buttons->cyan;
	else if (buttons->magenta->getName() == name)
		return buttons->magenta;
	else if (buttons->yellow->getName() == name)
		return buttons->yellow;
	else if (buttons->key->getName() == name)
		return buttons->key;
	else return nullptr;
}
ActionButton::~ActionButton(){
	delete cyan;
	delete magenta;
	delete yellow;
	delete key;

	cyan = nullptr;
	magenta = nullptr;
	yellow = nullptr;
	key = nullptr;
}
void ActionButton::addButtons(Layer* layer, const int& zPos){
	layer->addChild(cyan->getSprite(), zPos);
	layer->addChild(magenta->getSprite(), zPos);
	layer->addChild(yellow->getSprite(), zPos);
	layer->addChild(key->getSprite(), zPos);
}