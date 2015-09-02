#include "ScoreZone.h"

USING_NS_CC;

ScoreZone* ScoreZone::scoreSquare = nullptr;
ScoreZone::ScoreZone(){}
ScoreZone::~ScoreZone(){
	sprite->release();
}
ScoreZone::ScoreZone(const float& setScale) : SquareSprite(){
	sprite->setScale(setScale);
}
ScoreZone* ScoreZone::Init(const float& setScale){
	if (!scoreSquare){
		scoreSquare = new ScoreZone(setScale);
	}
	return scoreSquare;
}
Sprite* ScoreZone::getSprite(){
	return sprite;
}