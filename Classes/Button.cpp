#include "Button.h"
USING_NS_CC;
using namespace std;
Button::Button():SquareSprite(){}
Button::~Button(){}
Button* Button::create(const cocos2d::Color3B& color, const cocos2d::Vec2& position){
	Button* button = new Button();
	SquareSprite* buttonSprite = button->sprite;
	buttonSprite->setColor(color);
	if (position == Vec2(0, 0)){
		if (color == Color3B(0, 255, 255)){
			buttonSprite->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
			buttonSprite->setPosition(0, button->visibleSize.height);//cyan
		}
		else if (color == Color3B::MAGENTA){
			buttonSprite->setAnchorPoint(Vec2::ANCHOR_TOP_RIGHT);
			buttonSprite->setPosition(button->visibleSize.width, button->visibleSize.height);//magenta
		}
		else if (color == Color3B::YELLOW){
			buttonSprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
			buttonSprite->setPosition(0, 0);//yellow
		}
		else{
			buttonSprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
			buttonSprite->setPosition(button->visibleSize.width, 0);//black
		}
		button->addEvents();
	}
	else{
		button->sprite->setPosition(position);
	}
	button->initPos = buttonSprite->getPosition();
	return button;
}
void Button::resetProperty(){
	this->setAnchorPoint(initAnchor);
	this->setPosition(initPos);
}
void Button::addEvents(SquareSprite* sprite){
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = [&](Touch* touch, Event* event){
		Vec2 position = touch->getLocation();
		Rect rect = sprite->getBoundingBox();
		if (rect.containsPoint(position)){
			sprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
			return true;
		}
		return false;
	};
	listener->onTouchMoved = [=](Touch* touch, Event* event){
		sprite->setPosition(sprite->getPosition() + touch->getDelta());
	};
	listener->onTouchEnded = [&](Touch* touch, Event* event){
		sprite->resetProperty();
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, BUTTON_LISTENER_PRIORITY);
}