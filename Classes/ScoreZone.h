#include "SquareSprite.h"
#include "cocos2d.h"
class ScoreZone : public SquareSprite{
public:
	static ScoreZone* Init();
	cocos2d::Sprite* getSprite();
	~ScoreZone();
private:
	static ScoreZone* scoreSquare;
	ScoreZone();

};