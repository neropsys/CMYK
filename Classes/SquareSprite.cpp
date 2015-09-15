#include "SquareSprite.h"
USING_NS_CC;


SquareSprite::SquareSprite() : sprite(Sprite::create("White_square_small_opaque.png")){
	sprite->setScale(3);
}
SquareSprite::~SquareSprite(){
	log("SquareSprite destructor called");
}
SquareSprite::SquareSprite(const Color3B& color) : SquareSprite(){
	sprite->setColor(color);

}
void SquareSprite::setPosition(float x, float y){
	Node::setPosition(x, y);
	sprite->setPosition(x, y);
}