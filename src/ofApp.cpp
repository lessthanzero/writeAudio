#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    recording=false;
    ofSoundStreamSetup(0,NUM_CHANNELS,this, SAMPLE_RATE,BUFFER_SIZE,4);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255,255, 255);
    ofSetColor(20,20,20);
    ofDrawBitmapString("PRESS a to start recording",20,20);
    ofDrawBitmapString("PRESS s to stop recording",20,40);
    
    if ( recording ){
        ofSetCircleResolution(50);
        ofDrawBitmapString("RECORDING = TRUE",20,80);
        ofSetColor(255,0,0);
        ofCircle(400,160,150);
    } else {
        ofDrawBitmapString("RECORDING = FALSE",20,80);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    static int audioCount=0;
    
    if ( key=='a' && !recording ) {
        cout<<"Start recording\n";
        string pt=ofToString(audioCount,0)+".wav";
        
        cout << pt<<"----\n";
        audioRecorder.setup(pt, 10000, SAMPLE_RATE, NUM_CHANNELS); //ADDS ARGUMENTS
        audioRecorder.setFormat(SF_FORMAT_WAV | SF_FORMAT_PCM_16);
        recording=true;
        audioCount++;
    }
    
    if ( key=='s' && recording ){
        cout<<"Stop recording\n";
        recording=false;
        audioRecorder.finalize();
    }
    
}

//--------------------------------------------------------------
void ofApp::audioReceived(float * input, int bufferSize, int nChannels){
    if(recording) {
        audioRecorder.addSamples(input,bufferSize*nChannels);
    }
}