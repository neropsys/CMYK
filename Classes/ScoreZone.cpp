#include "ScoreZone.h"

USING_NS_CC;

ScoreZone::~ScoreZone(){
}
ScoreZone::ScoreZone() :SquareSprite(){
	this->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->setName("ScoreZone");
	this->addEvents();
}
ScoreZone* ScoreZone::create(){
	ScoreZone* scoreZone = new ScoreZone();
	scoreZone->sprite->setPosition(scoreZone->visibleSize.width / 2, scoreZone->visibleSize.height / 2);
	scoreZone->sprite->setName("ScoreZone");
	scoreZone->addEvents();
}
void ScoreZone::addEvents(){
	//TODO:
	//additional feature may be added later
}
//Button("ScoreZone", Color3B::WHITE, Vec2(visibleSize.width / 2, visibleSize.height / 2))