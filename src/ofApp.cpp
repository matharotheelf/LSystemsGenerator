#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    configurationGui.setup();
    configurationGui.add(lsystemGuiGroup.setup());

    lsystemGuiGroup.add(lSystemLabel.setup("LSystem Settings", ""));
    lsystemGuiGroup.add(presetLabel.setup("Preset", ""));
    lsystemGuiGroup.add(presetDropdown.setup("Preset"));
    presetDropdown.add("A preset");
    presetDropdown.add("B preset");
    
    lsystemGuiGroup.add(iterationsLabel.setup("Iterations", ""));
    lsystemGuiGroup.add(iterationsDropdown.setup("Iterations"));
    iterationsDropdown.add(1);
    iterationsDropdown.add(2);
    iterationsDropdown.add(3);
    iterationsDropdown.add(4);
    iterationsDropdown.add(5);

    lsystemGuiGroup.add(stochaticLabel.setup("Stochastic", ""));
    lsystemGuiGroup.add(stochasticToggle.setup(false));
    
    configurationGui.add(rulesGuiGroup.setup());
    
    rulesGuiGroup.add(rulesLabel.setup("Rules" , ""));
    rulesGuiGroup.add(firstRulelabel.setup("F", ""));
    rulesGuiGroup.add(firstRuleField.setup("F=>", "FF"));
    
    rulesGuiGroup.add(secondRulelabel.setup("X", ""));
    rulesGuiGroup.add(secondRuleField.setup("X=>", "XX[X]"));
    
    rulesGuiGroup.add(thirdRulelabel.setup("G", ""));
    rulesGuiGroup.add(thirdRuleField.setup("G=>", "GGG"));
    
    rulesGuiGroup.add(fourthRulelabel.setup("H", ""));
    rulesGuiGroup.add(fourthRuleField.setup("H=>", "HH"));
    
    configurationGui.add(visualGuiGroup.setup());
    
    visualGuiGroup.add(visualLabel.setup("Visual Settings", ""));
    
    visualGuiGroup.add(angleLabel.setup("Angle", ""));
    visualGuiGroup.add(angleField.setup(30.0));
    
    visualGuiGroup.add(rulesLabel.setup("Rules" , ""));
    
    visualGuiGroup.add(variablesLabel.setup("Variables", ""));
    visualGuiGroup.add(firstVariablelabel.setup("F", ""));
    visualGuiGroup.add(firstVariableLengthField.setup(100));
    visualGuiGroup.add(firstVariableColourField.setup(ofColor(0, 0, 0)));
    
    visualGuiGroup.add(secondVariablelabel.setup("X", ""));
    visualGuiGroup.add(secondVariableLengthField.setup(100));
    visualGuiGroup.add(secondVariableColourField.setup(ofColor(0, 0, 0)));
    
    visualGuiGroup.add(thirdVariablelabel.setup("G", ""));
    visualGuiGroup.add(thirdVariableLengthField.setup(100));
    visualGuiGroup.add(thirdVariableColourField.setup(ofColor(0, 0, 0)));
    
    visualGuiGroup.add(fourthVariablelabel.setup("H", ""));
    visualGuiGroup.add(fourthVariableLengthField.setup(100));
    visualGuiGroup.add(fourthVariableColourField.setup(ofColor(0, 0, 0)));

    
//    lSystem.DefineRule('F', "FF+[+F-F-F]-[-F+F+F]");
//    lSystem.GenerateSentence();
//    lSystem.GenerateSentence();
//    lSystem.GenerateSentence();
//    lSystem.GenerateSentence();
//    lSystem.GenerateSentence();
//    lSystem.GenerateSentence();
//    lSystem.GenerateSentence();
//    ofLog() << lSystem.getLastSentence()->sentence;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    configurationGui.draw();
//    ofTranslate(512, 768);
//    Turtle* turtle = new Turtle(lSystem.getLastSentence(), -3, 25);
//    turtle->Render();
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
