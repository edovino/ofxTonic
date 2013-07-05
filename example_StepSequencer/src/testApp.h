#pragma once

#include "ofMain.h"
#include "Tonic.h"

using namespace Tonic;

struct ParameterSlider{
  ControlParameter param;
  bool isActive;
  ParameterSlider(ControlParameter paramArg)
    :param(paramArg),
    isActive(false){}
};

// Extend ControlChangeSubscriber so we can subscribe to events generated by the Tonic synth
class testApp : public ofBaseApp{

  Synth synth;
  vector<ParameterSlider> sliders;
  ofRectangle sliderArea;

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void audioRequested (float * output, int bufferSize, int nChannels);
  
    // implement the valueChanged from ControlChangeSubscriber
    void valueChanged(string, TonicFloat);
    
		
};