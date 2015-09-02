#pragma once

#include <cocos2d.h>
#include <ui\UISlider.h>
//To do
using namespace cocos2d::ui;
class TrackLengthSlider{
private:
	static TrackLengthSlider* trackLengthSlider;
	static Slider* lengthSlider;
	TrackLengthSlider();
	static float sliderValue;
	void changeSliderValue();
public:
	static TrackLengthSlider* Init(float musicLength);
	float returnLength();


};
