#pragma once

#ifndef _OF_APP
#define _OF_APP

#include "ofMain.h"
#include "ofxLibsndFileRecorder.h"
#define NUM_CHANNELS 1
#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
    void keyPressed(int key);
    void audioReceived(float * input, int bufferSize, int nChannels);
    bool recording;
    ofxLibsndFileRecorder audioRecorder;
};

#endif