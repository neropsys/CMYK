#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ActionButtons.h"
#include "NoteSpawner.h"
#include "SimpleAudioEngine.h"
#include "ScoreZone.h"
#include "Variable.h"
#include <string>

//debug include
#include <fstream>

class HelloWorld : public cocos2d::LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	virtual void onEnter();
	virtual void onExit();

	void inputTiming(float f);
	void launchNotes(float nextNote);
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void musicStarter(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
private:
	static ActionButton* actionButton;
	bool isNoteVisible;
	bool attempted;
	static ScoreZone* scoreZone;
	TempNoteSpawner* noteSpawner;
	static int currentNote;
	int score;
	int timeCounter;
	cocos2d::Color3B touchedSpriteColor;
	cocos2d::LabelTTF* timeCounterLabel;
	cocos2d::LabelTTF* scoreCounterLabel;
	cocos2d::Size visibleSize;
	void resetButton(cocos2d::Sprite* target);
	cocos2d::Vector<Note*>::iterator noteIterator;

	//recording file
	std::fstream fs;
};

#endif // __HELLOWORLD_SCENE_H__
