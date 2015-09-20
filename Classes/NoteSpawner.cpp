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
		   m_color(color),
		   actionEnded(false),
		   m_closingSpeed(closingSpeed),
		   m_nextNoteTime(nextNoteTime),
		   m_pattern(pattern)
{
	//this->addChild(sprite);
	
}


void Note::runAction(){
	auto setInvisible = Hide::create();
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
		action = Spawn::create(ScaleTo::create(m_closingSpeed, SQUARE_SCALE), NULL);
	}
	else
	{
		action = Spawn::create(rotation, ScaleTo::create(m_closingSpeed, SQUARE_SCALE), NULL);
	}
	actionSequence = Sequence::create(setVisible, action, setInvisible, actionEndCallback, NULL);
	sprite->runAction(actionSequence);

}
const bool Note::isActionFinished(){
	return actionEnded;
}
void Note::actionFinished(){
	actionEnded = true;
}
const Color3B Note::getColor(){
	return m_color;
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
TempNoteSpawner::~TempNoteSpawner(){
	m_notes.clear();
}
void TempNoteSpawner::tempNoteGenerator(){
	
	
	for (int i = 0; i < 30; i++)
	{
		srand(time(nullptr));
		Color3B color;
		int colorType = RandomHelper::random_int(1, 4);
		int actionType = RandomHelper::random_int(1, 3);
		float closingSpeed = RandomHelper::random_real(1.f, 2.f);
		float nextNoteTime = RandomHelper::random_real(2.f, 3.f);
		ApproachPattern pattern;

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
		Note* newNote = new Note(color, pattern, closingSpeed, nextNoteTime);
		newNote->getSprite()->retain();
		m_notes.pushBack(newNote);
	}
}