#include "NoteSpawner.h"
USING_NS_CC;
Note::Note(const Color3B& color):SquareSprite(color), actionEnded(false){
	sprite->setScale(20.f);
}

Note::Note(){}

Note::Note(const cocos2d::Color3B& color, 
		   const ApproachPattern& pattern,
		   const float& closingSpeed,
		   const float& nextNoteTime)
		   :SquareSprite(color),
		   actionEnded(false),
		   m_closingSpeed(closingSpeed),
		   m_nextNoteTime(nextNoteTime),
		   m_pattern(pattern)
{
	//this->addChild(sprite);
	
}


void Note::runAction(){
	auto setInvisble = Hide::create();
	auto setVisible = Show::create();
	auto actionEndCallback = CallFunc::create([this](){
		this->actionFinished();
	});
	
	RotateBy* rotation = nullptr;

	switch (m_pattern)
	{
	case Clockwise:
		rotation = RotateBy::create(m_closingSpeed, 180);
		break;
	case AntiClockwise:
		rotation = RotateBy::create(m_closingSpeed, -180);
		break;
	case NoSpin:
		break;
	}

	if (rotation == nullptr)
	{
		action = Spawn::create(ScaleTo::create(m_closingSpeed, 1), NULL);
	}
	else
	{
		action = Spawn::create(RotateBy::create(m_closingSpeed, 180)
			, ScaleTo::create(m_closingSpeed, 1), NULL);
	}

	actionSequence = Sequence::create(setVisible, action, setInvisble, actionEndCallback, NULL);
	Node::runAction(actionSequence);

}
const bool Note::isActionFinished(){
	return actionEnded;
}
void Note::actionFinished(){
	actionEnded = true;
}
Sprite** Note::getSpriteReference(){
	return &sprite;
}
Sprite* Note::getSprite(){
	return sprite;
}
void Note::setVisible(bool visible){
	Node::setVisible(visible);
}
bool Note::isVisible() const{
	return sprite->isVisible();
}
const float Note::getnextNoteTime(){
	return m_nextNoteTime;
}
void Note::setScale(float scale){
	sprite->setScale(scale);
}
float Note::getScale() const{
	return sprite->getScale();
}
Note::~Note(){
	action->release();
	actionSequence->release();
	sprite->release();

}
TempNoteSpawner::TempNoteSpawner(){
}

void TempNoteSpawner::tempNoteGenerator(){
	
	
	for (int i = 0; i < 30; i++)
	{
		srand(time(nullptr));
		Color3B color;
		int colorType = rand() % 4 + 1;
		int actionType = rand() % 3 + 1;
		float closingSpeed = rand() % 2 + 1;
		float nextNoteTime = rand() % 2 + 1;
		ApproachPattern pattern;
		log("random color value : %d", colorType);
		log("random action value : %d", actionType);

		switch (colorType)
		{
		case 1:
			color = Color3B::BLACK;
			break;
		case 2:
			color = Color3B::MAGENTA;
			break;
		case 3:
			color = Color3B::YELLOW;
			break;
		case 4:
			color = Color3B(0, 255, 255);//Cyan
			break;
		}
		switch (actionType)
		{
		case 1:
			pattern = ApproachPattern::AntiClockwise;
			break;
		case 2:
			pattern = ApproachPattern::Clockwise;
			break;
		case 3:
			pattern = ApproachPattern::NoSpin;
			break;
		}

		m_notes.pushBack(new Note(color, pattern, closingSpeed, nextNoteTime));
	}

}