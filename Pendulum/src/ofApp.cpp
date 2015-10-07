#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    
    pos0 = ofPoint(512, 300);
    pos = ofPoint(600,200);
    velocity = ofPoint(100,0);
}

//--------------------------------------------------------------
void ofApp::update(){

    // Constants
    float dt = 1.0 / 60.0;
    float mass = 0.1;
    float rubberLen = 200.0;
    float k = 0.5;
    ofPoint g(0.0, 9.8);
    
    // Compute Hooke's force
    ofPoint delta = pos - pos0;
    float len = delta.length();
    float hookeValue = k * (len - rubberLen);
    delta.normalize();
    ofPoint hookeForce = delta * (-hookeValue);
    
    // Update velocity and pos
    ofPoint force = hookeForce + g;     // Resulted force
    ofPoint a = force / mass;           // Second Newton's law
    velocity += a * dt;                 // Euler method
    pos += velocity *dt;                // Euler method
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255, 255, 255);
    
    ofSetColor(0, 0, 255);
    ofLine(pos0.x, pos0.y, pos.x, pos.y);
    
    ofSetColor(255, 0, 0);
    ofFill();
    ofCircle(pos.x, pos.y, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
