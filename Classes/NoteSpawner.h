#pragma once

#include "cocos2d.h"
#include "SquareSprite.h"
#include"cocos2d\cocos\base\CCVector.h"
//temp include for random note generation
#include <stdlib.h>
#include <time.h>


#include <deque>
typedef enum {
	Clockwise,
	AntiClockwise,
	NoSpin
}ApproachPattern;
class Note : public SquareSprite{
public:
	//this constructor will be mainly used
	Note(const cocos2d::Color3B& color, const ApproachPattern& pattern, const float& closingSpeed, const float& nextNoteTime);
	const float getnextNoteTime();

	//Temporary method & constructor for random generation
	void runAction(const ApproachPattern& pattern, const float& closingSpeed, const float& nextNoteTime);
	Note(const cocos2d::Color3B& color);
	const bool isActionFinished();
	~Note();
private:
	ApproachPattern m_pattern;
	float m_closingSpeed;
	float m_nextNoteTime;
	bool actionEnded;
	void actionFinished();
	cocos2d::Spawn* action;
	cocos2d::Sequence* actionSequence;
	Note();
};
class TempNoteSpawner{
public:
	cocos2d::Vector<Note*> m_notes;
	TempNoteSpawner();
	~TempNoteSpawner();	
	void tempNoteGenerator();
};