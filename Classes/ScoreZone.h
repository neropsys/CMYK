#pragma once

#include "SquareSprite.h"
#include "cocos2d.h"
class ScoreZone : public SquareSprite{
public:
	static ScoreZone* create();
	ScoreZone();
	~ScoreZone();
protected:
	void addEvents()override;


};