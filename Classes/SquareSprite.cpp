#include "SquareSprite.h"
#include "Variable.h"
USING_NS_CC;


SquareSprite::SquareSprite() :visibleSize(Director::getInstance()->getVisibleSize()){
	sprite->createWithSpriteFrameName("White_square_small_opaque.png");
	sprite->setScale(SQUARE_SCALE);
}
SquareSprite::~SquareSprite(){}
void SquareSprite::initOptions(){}