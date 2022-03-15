#include "ofApp.h"
#include "ofmath.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetBackgroundAuto(false);
    loadGuitar();
    loadSaxophone();
    
    tempo = 1000;
    autoPlay = false;
    currTime = ofGetSystemTimeMillis();
    
    ofSetCircleResolution(100);
    //ofSetDepthTest(true);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0, 50);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight()); //makeitfade
    
    ofSetColor(255);
    if (autoPlay){
        if (ofGetSystemTimeMillis() > currTime + tempo){
            int num = ofRandom(totalVoices);
            voices[num].play();
            currTime = ofGetSystemTimeMillis();
            cout << "sounds play" << num << endl;
        }
    }
    
    ofDrawBitmapString("Play with it by pressing keys '1-9' \nAuto play press 'a‘\nGet full screen view press 'f'\nSwitch between guitar & saxophone by pressing 'g' and 's'",20 ,30);
    
    ofColor lineColor;
    int barWidth = 2000;
    int length = 50;
    float bandsToGet = 512;
    float width = (float)(5 * 128) / bandsToGet;
    float* val = ofSoundGetSpectrum(bandsToGet);
    float time = ofGetElapsedTimef();
    
    for (int i = 0; i < bandsToGet; i++){
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotateRad(360.0/bandsToGet * i);
        
        lineColor.setHsb(255/bandsToGet * i, 200, 255);
        ofSetColor(lineColor);
        
        ofDrawRectangle(0, -barWidth/2, val[i] * length, barWidth/2);
        
        ofPopMatrix();
    }
    
    for (int i = 0; i < bandsToGet; i++){
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotateRad(360.0/bandsToGet * i);
        
        ofSetColor(255 * sin(i * 0.1 + time),
                   255 * sin(i * 0.2 + time),
                   255 * sin(i * 0.3 + time));
        
        ofDrawCircle(ofGetHeight()/2 + 300 * cos(i + time), 384, val[i] * length * cos(i + time) * 2);
        ofDrawCircle(512, ofGetHeight()/2 + 300 * sin(i + time), val[i] * length * sin(i + time) * 0.5);
        
        ofPopMatrix();
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key){
        case 'a':
            autoPlay = !autoPlay;
            break;
            
        case '1':
            voices[1].play();
            break;
        case '2':
            voices[2].play();
            break;
        case '3':
            voices[3].play();
            break;
        case '4':
            voices[4].play();
            break;
        case '5':
            voices[5].play();
            break;
        case '6':
            voices[6].play();
            break;
        case '7':
            voices[7].play();
            break;
        case '8':
            voices[8].play();
            break;
        case '9':
            voices[9].play();
            break;
        case 'p':
            voices[10].play();
            break;
        case 'f':
            ofToggleFullscreen();
            break;
        case 'g':
            loadGuitar();
            break;
        case 's':
            loadSaxophone();
            break;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

void ofApp::loadGuitar(){
    totalVoices = 10;
    voices.clear();
    for (int i = 0; i < totalVoices; i++){
        ofSoundPlayer voice;
        string path = "guitar/guitar-0" + ofToString(i+1) + ".wav";
        cout << "..." << path << endl;
        voice.load(path);
        voice.setMultiPlay(true);
        voices.push_back(voice);
    }
}

void ofApp::loadSaxophone(){
    totalVoices = 10;
    voices.clear();
    for (int i = 0; i < totalVoices; i++){
        ofSoundPlayer voice;
        string path = "Saxophone/Saxophone-0" + ofToString(i+1) + ".wav";
        cout << "..." << path << endl;
        voice.load(path);
        voice.setMultiPlay(true);
        voices.push_back(voice);
    }
}
