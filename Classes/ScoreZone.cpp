#include "ScoreZone.h"

USING_NS_CC;

ScoreZone::~ScoreZone(){
}
ScoreZone::ScoreZone() :SquareSprite(){
	this->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->setName("ScoreZone");
	this->addEvents();
}
void ScoreZone::addEvents(){
	//TODO:
	//additional feature may be added later
}
//Button("ScoreZone", Color3B::WHITE, Vec2(visibleSize.width / 2, visibleSize.height / 2))