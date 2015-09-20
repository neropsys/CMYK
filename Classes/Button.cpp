#include "Button.h"
USING_NS_CC;
using namespace std;
Button::Button(){}

Button::Button(const string& buttonName, const Color3B& color, const cocos2d::Vec2& position = 0)
{
	this->setColor(color);
	this->setName(buttonName);
	if (position == 0){
		if (color == Color3B(0,255, 255)){
			this->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
			this->setPosition(0, visibleSize.height);//cyan
		}
		else if (color == Color3B::MAGENTA){
			this->setAnchorPoint(Vec2::ANCHOR_TOP_RIGHT);
			this->setPosition(visibleSize.width, visibleSize.height);//magenta
		}
		else if (color == Color3B::YELLOW){
			this->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
			this->setPosition(0, 0);//yellow
		}
		else{
			this->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
			this->setPosition(visibleSize.width, 0);//black
		}
		this->addEvents();
	}
	else{
		this->setPosition(position);
	}
	initPos = this->getPosition();
}
Button::~Button(){}
void Button::resetProperty(){
	this->setAnchorPoint(initAnchor);
	this->setPosition(initPos);
}
void Button::addEvents(){
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = [&](Touch* touch, Event* event){
		Vec2 position = touch->getLocation();
		Rect rect = this->getBoundingBox();
		if (rect.containsPoint(position)){
			this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
			return true;
		}
		return false;
	};
	listener->onTouchMoved = [=](Touch* touch, Event* event){
		this->setPosition(this->getPosition() + touch->getDelta());
	};
	listener->onTouchEnded = [&](Touch* touch, Event* event){
		this->resetProperty();
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, BUTTON_LISTENER_PRIORITY);
}