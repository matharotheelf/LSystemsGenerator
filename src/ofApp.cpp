#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    configurationGui.setup("Configuration");
    
    configurationGui.add(generateLSystemButton.setup("Generate L-System"));
    generateLSystemButton.addListener(this, &ofApp::generateLSystemButtonPressed);

    configurationGui.add(lsystemGuiGroup.setup("L-System Settings"));

    lsystemGuiGroup.add(presetLabel.setup("Preset", ""));
    lsystemGuiGroup.add(presetDropdown.setup("Preset"));
    presetDropdown.add("A preset");
    presetDropdown.add("B preset");
    
    lsystemGuiGroup.add(iterationsLabel.setup("Iterations", ""));
    lsystemGuiGroup.add(iterationsField.setup(5));
    iterationsField.setMax(10);
    iterationsField.setMin(1);

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
    visualGuiGroup.add(angleField.setup(30));
    
    visualGuiGroup.add(variablesLabel.setup("Variables", ""));
    visualGuiGroup.add(firstVariableLabel.setup("F", ""));
    visualGuiGroup.add(firstVariableLengthField.setup("Line Length", 100));
    visualGuiGroup.add(firstVariableColourFieldLabel.setup("Line Colour", ""));
    visualGuiGroup.add(firstVariableColourField.set(ofColor(0, 0, 0)));
    
    visualGuiGroup.add(secondVariableLabel.setup("X", ""));
    visualGuiGroup.add(secondVariableLengthField.setup("Line Length", 100));
    visualGuiGroup.add(secondVariableColourFieldLabel.setup("Line Colour", ""));
    visualGuiGroup.add(secondVariableColourField.set(ofColor(0, 0, 0)));
    
    visualGuiGroup.add(thirdVariableLabel.setup("G", ""));
    visualGuiGroup.add(thirdVariableLengthField.setup("Line Length", 100));
    visualGuiGroup.add(thirdVariableColourFieldLabel.setup("Line Colour", ""));
    visualGuiGroup.add(thirdVariableColourField.set(ofColor(0, 0, 0)));
    
    visualGuiGroup.add(fourthVariableLabel.setup("H", ""));
    visualGuiGroup.add(fourthVariableLengthField.setup("Line Length", 100));
    visualGuiGroup.add(fourthVariableColourFieldLabel.setup("Line Colour", ""));
    visualGuiGroup.add(fourthVariableColourField.set(ofColor(0, 0, 0)));
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(turtle != NULL) {
        turtle->Render(scaleFactor, lineWeight);
    }
    
    configurationGui.draw();
}

void ofApp::generateLSystemButtonPressed(){
    configurationGui.minimize();
    
    string axiom = axiomField.getParameter().cast<string>();
    float angle = angleField.getParameter().cast<int>();
    int iterations = iterationsField.getParameter().cast<int>();
    
    lSystem = new LSystem(axiom, iterations);
    
    string firstRule = firstRuleField.getParameter().cast<string>();
    string secondRule = secondRuleField.getParameter().cast<string>();
    string thirdRule = thirdRuleField.getParameter().cast<string>();
    string fourthRule = fourthRuleField.getParameter().cast<string>();
    
    if(!firstRule.empty()){
        lSystem->DefineRule('F', firstRule);
    }
    
    if(!secondRule.empty()){
        lSystem->DefineRule('X', secondRule);
    }
    
    if(!thirdRule.empty()){
        lSystem->DefineRule('G', thirdRule);
    }
    
    if(!fourthRule.empty()){
        lSystem->DefineRule('H', fourthRule);
    }
    
    int firstVariableLength = firstVariableLengthField.getParameter().cast<int>();
    int secondVariableLength = secondVariableLengthField.getParameter().cast<int>();
    int thirdVariableLength = thirdVariableLengthField.getParameter().cast<int>();
    int fourthVariableLength = fourthVariableLengthField.getParameter().cast<int>();
    
    ofColor firstVariableColour = firstVariableColourField.cast<ofColor>();
    ofColor secondVariableColour = secondVariableColourField.cast<ofColor>();
    ofColor thirdVariableColour = firstVariableColourField.cast<ofColor>();
    ofColor fourthVariableColour = secondVariableColourField.cast<ofColor>();
    
    map<char, RenderConfig *> renderConfigs;
    
    renderConfigs['F'] = new RenderConfig(-firstVariableLength, firstVariableColour);
    renderConfigs['X'] = new RenderConfig(-secondVariableLength, secondVariableColour);
    renderConfigs['G'] = new RenderConfig(-thirdVariableLength, thirdVariableColour);
    renderConfigs['H'] = new RenderConfig(-fourthVariableLength, fourthVariableColour);

    lSystem->GenerateSentence();

    turtle = new Turtle(lSystem->getLastSentence(), angle, renderConfigs);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' ' && turtle != NULL && lSystem != NULL){
        lSystem->GenerateSentence();
        turtle->SetSentence(lSystem->getLastSentence());
    }
    
    if(key == '+'){
        scaleFactor = scaleFactor*1.5;
    } else if(key == '-') {
        scaleFactor = scaleFactor/1.5;
    }
    
    if(key == ']'){
        lineWeight = lineWeight*1.2;
    } else if(key == '[') {
        lineWeight = lineWeight/1.2;
    }
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
