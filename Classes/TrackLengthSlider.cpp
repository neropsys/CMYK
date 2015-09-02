#include "TrackLengthSlider.h"

USING_NS_CC;
using namespace ui;

Slider* TrackLengthSlider::lengthSlider = nullptr;
float TrackLengthSlider::sliderValue = 0;
TrackLengthSlider* TrackLengthSlider::trackLengthSlider = nullptr;

TrackLengthSlider::TrackLengthSlider(){}

TrackLengthSlider* TrackLengthSlider::Init(float musicLength){
	if (!trackLengthSlider){
		trackLengthSlider = new TrackLengthSlider();

		trackLengthSlider->lengthSlider = Slider::create();
		trackLengthSlider->lengthSlider->loadBarTexture("Slider/sliderTrack.png");
		trackLengthSlider->lengthSlider->loadSlidBallTextures("Slider/potentiometerButton.png", "Slider/potentiometerButton.png", "");
		trackLengthSlider->lengthSlider->loadProgressBarTexture("Slider/sliderProgress.png");
	}
	return trackLengthSlider;
	//lengthSlider->adde
}
void TrackLengthSlider::changeSliderValue(){

}
float TrackLengthSlider::returnLength(){
	return sliderValue;
}