#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    
    void loadGuitar();
    void loadSaxophone();
    
    vector<ofSoundPlayer> voices;
    ofSoundPlayer voice1, voice2, voice3, voice4, voice5, voice6, voice7, voice8, voice9, voice10;
    bool autoPlay;
    float tempo, currTime;
    int totalVoices;
};
