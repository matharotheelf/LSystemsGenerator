#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    configurationGui.setup("Configuration");
    configurationGui.add(generateLSystemButton.setup("Generate L-System"));

    configurationGui.add(lsystemGuiGroup.setup("L-System Settings"));

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
    
    configurationGui.add(rulesGuiGroup.setup("Rules"));
    
    rulesGuiGroup.add(firstRuleField.setup("F=>", "FF"));
    rulesGuiGroup.add(secondRuleField.setup("X=>", "XX[X]"));
    rulesGuiGroup.add(thirdRuleField.setup("G=>", "GGG"));
    rulesGuiGroup.add(fourthRuleField.setup("H=>", "HH"));
    rulesGuiGroup.add(axiomlabel.setup("Axiom", ""));
    rulesGuiGroup.add(axiomField.setup("Axiom", "F"));
    
    configurationGui.add(visualGuiGroup.setup("VIsual Settings"));
    
    visualGuiGroup.add(angleLabel.setup("Angle", ""));
    visualGuiGroup.add(angleField.setup(30.0));
    
    visualGuiGroup.add(variablesLabel.setup("Variables", ""));
    visualGuiGroup.add(firstVariableLabel.setup("F", ""));
    visualGuiGroup.add(firstVariableLengthField.setup("Line Length", 100));
    visualGuiGroup.add(firstVariableColourFieldLabel.setup("Line Colour", ""));
    visualGuiGroup.add(firstVariableColourField.setup(ofColor(0, 0, 0)));
    
    visualGuiGroup.add(secondVariableLabel.setup("X", ""));
    visualGuiGroup.add(secondVariableLengthField.setup("Line Length", 100));
    visualGuiGroup.add(secondVariableColourFieldLabel.setup("Line Colour", ""));
    visualGuiGroup.add(secondVariableColourField.setup( ofColor(0, 0, 0)));
    
    visualGuiGroup.add(thirdVariableLabel.setup("G", ""));
    visualGuiGroup.add(thirdVariableLengthField.setup("Line Length", 100));
    visualGuiGroup.add(thirdVariableColourFieldLabel.setup("Line Colour", ""));
    visualGuiGroup.add(thirdVariableColourField.setup(ofColor(0, 0, 0)));
    
    visualGuiGroup.add(fourthVariableLabel.setup("H", ""));
    visualGuiGroup.add(fourthVariableLengthField.setup("Line Length", 100));
    visualGuiGroup.add(fourthVariableColourFieldLabel.setup("Line Colour", ""));
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
