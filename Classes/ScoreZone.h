#include "SquareSprite.h"
#include "cocos2d.h"
class ScoreZone : public SquareSprite{
public:
	static ScoreZone* Init(const float& setScale);
	cocos2d::Sprite* getSprite();
	~ScoreZone();
private:
	static ScoreZone* scoreSquare;
	ScoreZone(const float& setScale);
	ScoreZone();

};