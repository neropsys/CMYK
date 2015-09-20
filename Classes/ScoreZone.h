#include "SquareSprite.h"
#include "cocos2d.h"
class ScoreZone : public SquareSprite{
public:
	ScoreZone();
	~ScoreZone();
protected:
	void addEvents()override;


};