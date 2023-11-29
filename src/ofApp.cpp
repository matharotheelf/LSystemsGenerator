#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    lSystem.DefineRule('F', "FF+[+F-F-F]-[-F+F+F]");
    lSystem.GenerateSentence();
    lSystem.GenerateSentence();
    lSystem.GenerateSentence();
    lSystem.GenerateSentence();
    lSystem.GenerateSentence();
    lSystem.GenerateSentence();
    lSystem.GenerateSentence();
    ofLog() << lSystem.getLastSentence()->sentence;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(512, 768);
    Turtle* turtle = new Turtle(lSystem.getLastSentence(), -3, 25);
    turtle->Render();
}

//--------------------------------------------------------------
void ofApp::exit(){

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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
