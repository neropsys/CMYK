#include "ScoreZone.h"

USING_NS_CC;

ScoreZone* ScoreZone::scoreSquare = nullptr;
ScoreZone::~ScoreZone(){
	sprite->release();
}
ScoreZone::ScoreZone() : SquareSprite(){
}
ScoreZone* ScoreZone::Init(){
	if (!scoreSquare){
		scoreSquare = new ScoreZone();
	}
	return scoreSquare;
}
Sprite* ScoreZone::getSprite(){
	return sprite;
}