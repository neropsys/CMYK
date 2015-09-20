#include "SquareSprite.h"
#include "Variable.h"
USING_NS_CC;


SquareSprite::SquareSprite() :visibleSize(Director::getInstance()->getVisibleSize()){
	this->create("White_square_small_opaque.png");
	this->setScale(SQUARE_SCALE);
}
SquareSprite::~SquareSprite(){}
void SquareSprite::touchEvent(Touch* touch, Vec2 point){}