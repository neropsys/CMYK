#include "HelloWorldScene.h"
USING_NS_CC;
using namespace std;
using namespace CocosDenshion;
ActionButton* HelloWorld::actionButton = nullptr;
ScoreZone* HelloWorld::scoreZone = nullptr;
int HelloWorld::currentNote = 0;


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance

//temporary scene for testing.
bool HelloWorld::init()
{
	//for recording the scale of notes on player input
	fs.open("average_Scale_Value.txt", ios::app);
	if (fs.fail()) return false;

    //////////////////////////////
    // 1. super init first
    if (!LayerColor::initWithColor(Color4B::GRAY)) //::init() )
    {
        return false;
    }
    visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("07-daft_punk-one_more_time.mp3");

	score = 0;
	timeCounter = MUSIC_START_TIME;

	this->schedule(schedule_selector(HelloWorld::musicStarter), 1.f);
	this->schedule(schedule_selector(HelloWorld::inputTiming));

	actionButton = ActionButton::Init();
	actionButton->addButtons(this, 3);

	scoreCounterLabel = LabelTTF::create(to_string(score), "Arial", 50);
	scoreCounterLabel->setPosition(visibleSize.width / 2, visibleSize.height / 7);
	scoreCounterLabel->scheduleUpdate();
	this->addChild(scoreCounterLabel, 4);

	timeCounterLabel = LabelTTF::create(to_string(timeCounter), "Arial", 50);
	timeCounterLabel->setPosition(visibleSize.width / 2, visibleSize.height / 5);
	timeCounterLabel->scheduleUpdate();
	this->addChild(timeCounterLabel, 4);

	noteSpawner = new TempNoteSpawner();
	noteSpawner->tempNoteGenerator();
	noteIterator = noteSpawner->m_notes.begin();
	

	scoreZone = ScoreZone::Init();

	scoreZone->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(scoreZone->getSprite(), 2);

	
    return true;
}
void HelloWorld::onEnter(){
	Layer::onEnter();
	
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(false);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = [](Touch* touch, Event* event){
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setPosition(target->getPosition() + touch->getDelta());
	};
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), actionButton->getSpriteByName("cyan"));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), actionButton->getSpriteByName("magenta"));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), actionButton->getSpriteByName("yellow"));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), actionButton->getSpriteByName("key"));



}
void HelloWorld::onExit(){
	_eventDispatcher->removeAllEventListeners();


	//remove on release
	fs.close();

	Layer::onExit();
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event){

	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	Point locationInNode = target->convertToNodeSpace(touch->getLocation());

	
	//log("touch coord x : %f, y : %f", touch->getLocation().x, touch->getLocation().y);

	Size s = target->getContentSize();

	Rect rect = Rect(0, 0, s.width, s.height);
	if (rect.containsPoint(locationInNode)){

		if (touch->getLocation().x < (s.width * 0.5) && touch->getLocation().y < (s.height * 0.5)){
			touchedSpriteColor = Color3B::YELLOW;
			target->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		}
		else if (touch->getLocation().x >(s.width * 0.5) && touch->getLocation().y < (s.height * 0.5)){
			touchedSpriteColor = Color3B::BLACK;
			target->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		}
		else if (touch->getLocation().x >(s.width * 0.5) && touch->getLocation().y >(s.height * 0.5)){
			touchedSpriteColor = Color3B::MAGENTA;
			target->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		}
		else{
			touchedSpriteColor = Color3B::Color3B(0, 255, 255);//Cyan
			target->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		}
		target->setPosition(Vec2(touch->getLocation().x, touch->getLocation().y));
		return true;
	}

	return false;

}
void HelloWorld::onTouchEnded(Touch* touch, Event* event){
	//detection balance test code
	log("note scale : %f", (*noteIterator)->getScale());
	fs << (*noteIterator)->getScale() << endl;
	
	auto button = static_cast<Sprite*>(event->getCurrentTarget());

	Size s = button->getContentSize();


	// distance between note detector and cmyk button
	int eventDistance = (int) button->getPosition().getDistanceSq(scoreZone->getPosition());
	log("event distance : %d", eventDistance);
	if (NOTEDETECTOR_AND_CMYKBUTTON_DISTANCE_THRESHOLD_MIN < eventDistance &&
		eventDistance < NOTEDETECTOR_AND_CMYKBUTTON_DISTANCE_THRESHOLD_MAX &&
		(*noteIterator)->isVisible() &&
		(*noteIterator)->getScale() >= SQUARE_SCALE &&
		(*noteIterator)->getScale() <= SQUARE_SCALE + 1 &&
		(*noteIterator)->isActionFinished() == false &&
		touchedSpriteColor == (*noteIterator)->getColor()){
		score += 10;
		attempted = true;
	}
	else score = 0;
	scoreCounterLabel->setString(to_string(score));



	resetButton(button);

}
void HelloWorld::resetButton(Sprite* target){
	if (target == actionButton->getSpriteByName("cyan"))
	{
		target->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
		actionButton->getButtonByName("cyan")->resetPos();
	}
	else if (target == actionButton->getSpriteByName("magenta"))
	{
		target->setAnchorPoint(Vec2::ANCHOR_TOP_RIGHT);
		actionButton->getButtonByName("magenta")->resetPos();
	}
	else if (target == actionButton->getSpriteByName("yellow"))
	{
		target->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
		actionButton->getButtonByName("yellow")->resetPos();
	}
	else{
		target->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
		actionButton->getButtonByName("key")->resetPos();
	}
	actionButton->resetAllButton();
}
void HelloWorld::musicStarter(float dt){
	timeCounter -= 1;
	timeCounterLabel->setString(to_string(timeCounter));
	if (timeCounter == 0){
		SimpleAudioEngine::getInstance()->playBackgroundMusic("07-daft_punk-one_more_time.mp3", false);
		this->removeChild(timeCounterLabel);
		this->unschedule(schedule_selector(HelloWorld::musicStarter));
		launchNotes(0);
	}
}
void HelloWorld::launchNotes(float nextNote){
	log("Next note time : %f", nextNote);
	this->addChild((*noteIterator)->getSprite(), 0);
	(*noteIterator)->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	(*noteIterator)->setScale(20.f);
	attempted = false;	
	
	(*noteIterator)->runAction();

}
void HelloWorld::inputTiming(float f){//called every frame
	if ((*noteIterator)->isActionFinished() == true && attempted == false)
	{
		score = 0;
		scoreCounterLabel->setString(to_string(score));
	}
	//cleanup when note is gone
	if ((*noteIterator)->isActionFinished() == true)
	{
		this->removeChild((*noteIterator)->getSprite());
		(*noteIterator)->getSprite()->autorelease();
		this->unschedule(schedule_selector(HelloWorld::launchNotes));
		if (noteIterator != noteSpawner->m_notes.end())
		{
		noteIterator++;
		this->schedule(schedule_selector(HelloWorld::launchNotes), (*noteIterator)->getnextNoteTime());
		}
	}
	
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
