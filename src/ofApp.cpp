#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    presetSettings.loadFile("presetSettings.xml");
    
    configurationGui.setup("Configuration");
    
    configurationGui.add(generateLSystemButton.setup("Generate L-System"));
    generateLSystemButton.addListener(this, &ofApp::generateLSystemButtonPressed);

    configurationGui.add(lsystemGuiGroup.setup("L-System Settings"));

    lsystemGuiGroup.add(presetLabel.setup("Preset", ""));
    lsystemGuiGroup.add(presetButton1.setup(presets[0]));
    
    presetButton1.addListener(this, &ofApp::SelectPreset1);
    
    lsystemGuiGroup.add(presetButton2.setup(presets[1]));
    presetButton2.addListener(this, &ofApp::SelectPreset2);
    
    lsystemGuiGroup.add(presetButton3.setup(presets[2]));
    presetButton3.addListener(this, &ofApp::SelectPreset3);
    
    lsystemGuiGroup.add(presetButton4.setup(presets[3]));
    presetButton4.addListener(this, &ofApp::SelectPreset4);
    
    lsystemGuiGroup.add(presetButton5.setup(presets[4]));
    presetButton5.addListener(this, &ofApp::SelectPreset5);
    
    lsystemGuiGroup.add(presetButton6.setup(presets[5]));
    presetButton6.addListener(this, &ofApp::SelectPreset6);
    
    lsystemGuiGroup.add(presetButton7.setup(presets[6]));
    presetButton7.addListener(this, &ofApp::SelectPreset7);
    
    lsystemGuiGroup.add(presetButton8.setup(presets[7]));
    presetButton8.addListener(this, &ofApp::SelectPreset8);
    
    lsystemGuiGroup.add(presetButton9.setup(presets[8]));
    presetButton9.addListener(this, &ofApp::SelectPreset9);
    
    lsystemGuiGroup.add(presetButton10.setup(presets[9]));
    presetButton10.addListener(this, &ofApp::SelectPreset10);
    
    lsystemGuiGroup.add(iterationsLabel.setup("Max Iterations", ""));
    lsystemGuiGroup.add(iterationsField.setup(5));
    iterationsField.setMax(15);
    iterationsField.setMin(1);

    lsystemGuiGroup.add(stochaticLabel.setup("Stochastic", ""));
    lsystemGuiGroup.add(stochasticToggle.setup(false));
    
    configurationGui.add(rulesGuiGroup.setup("Rules"));

    configurationGui.add(visualGuiGroup.setup("Visual Settings"));
    
    CreateSoundGui();
    
    loadPresetConfiguration(defaultPreset);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(turtle != NULL) {
        turtle->Render(scaleFactor, lineWeight);
        soundGui.draw();
    }
    
    configurationGui.draw();
}

void ofApp::generateLSystemButtonPressed(){
    configurationGui.minimize();
    
    string axiom = axiomField.getParameter().cast<string>();
    float angle = angleField.getParameter().cast<int>();
    int iterations = iterationsField.getParameter().cast<int>();
    
    lSystem = new LSystem(axiom, iterations);
    
    renderConfigs.clear();
    
    if(find(configAlphabet.begin(), configAlphabet.end(), 'F') != configAlphabet.end()) {
        FConfigureVariable();
    }
    
    if(find(configAlphabet.begin(), configAlphabet.end(), 'X') != configAlphabet.end()) {
        XConfigureVariable();
    }
    
    if(find(configAlphabet.begin(), configAlphabet.end(), 'G') != configAlphabet.end()) {
        GConfigureVariable();
    }
    
    if(find(configAlphabet.begin(), configAlphabet.end(), 'H') != configAlphabet.end()) {
        HConfigureVariable();
    }

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

void ofApp::SelectPreset1(){
    loadPresetConfiguration(presets[0]);
}

void ofApp::SelectPreset2(){
    loadPresetConfiguration(presets[1]);
}

void ofApp::SelectPreset3(){
    loadPresetConfiguration(presets[2]);
}

void ofApp::SelectPreset4(){
    loadPresetConfiguration(presets[3]);
}

void ofApp::SelectPreset5(){
    loadPresetConfiguration(presets[4]);
}

void ofApp::SelectPreset6(){
    loadPresetConfiguration(presets[5]);
}


void ofApp::SelectPreset7(){
    loadPresetConfiguration(presets[6]);
}

void ofApp::SelectPreset8(){
    loadPresetConfiguration(presets[7]);
}

void ofApp::SelectPreset9(){
    loadPresetConfiguration(presets[8]);
}

void ofApp::SelectPreset10(){
    loadPresetConfiguration(presets[9]);
}

void ofApp::loadPresetConfiguration(string configurationName){
    presetSettings.pushTag(configurationName);
    
    configAxiom = presetSettings.getValue("axiom", "F");
    presetSettings.pushTag("rules");

    SetConfigAlphabet();
    
    ofLog() << configAlphabet.size();
    RenderRulesFields();
    RenderVisualFields();

    presetSettings.popTag();
    presetSettings.popTag();
}

void ofApp::RenderRulesFields(){
    rulesGuiGroup.clear();

    if(find(configAlphabet.begin(), configAlphabet.end(), 'F') != configAlphabet.end()) {
        string rule = presetSettings.getValue("F", "F");
        FRuleFieldAddition(rule);
    }
    
    if(find(configAlphabet.begin(), configAlphabet.end(), 'X') != configAlphabet.end()) {
        string rule = presetSettings.getValue("X", "X");
        XRuleFieldAddition(rule);
    }
    
    if(find(configAlphabet.begin(), configAlphabet.end(), 'G') != configAlphabet.end()) {
        string rule = presetSettings.getValue("G", "G");
        GRuleFieldAddition(rule);
    }
    
    if(find(configAlphabet.begin(), configAlphabet.end(), 'H') != configAlphabet.end()) {
        string rule = presetSettings.getValue("H", "H");
        HRuleFieldAddition(rule);
    }
    
    rulesGuiGroup.add(axiomlabel.setup("Axiom", ""));
    rulesGuiGroup.add(axiomField.setup("Axiom", configAxiom));
}

void ofApp::RenderVisualFields(){
    visualGuiGroup.clear();
    
    visualGuiGroup.add(angleLabel.setup("Angle", ""));
    visualGuiGroup.add(angleField.setup(30));
    
    visualGuiGroup.add(variablesLabel.setup("Variables", ""));

    if(find(configAlphabet.begin(), configAlphabet.end(), 'F') != configAlphabet.end()) {
        FVisualFieldsAddition();
    }
    
    if(find(configAlphabet.begin(), configAlphabet.end(), 'X') != configAlphabet.end()) {
        XVisualFieldsAddition();
    }
    
    if(find(configAlphabet.begin(), configAlphabet.end(), 'G') != configAlphabet.end()) {
        GVisualFieldsAddition();
    }
    
    if(find(configAlphabet.begin(), configAlphabet.end(), 'H') != configAlphabet.end()) {
        HVisualFieldsAddition();
    }
}

void ofApp::SetConfigAlphabet(){
    configAlphabet.clear();
    
    for (char character: possibleAlphabet) {
        string letter(1, character);
        if(presetSettings.tagExists(letter)) {
            configAlphabet.push_back(character);
        };
    }
}

void ofApp::FRuleFieldAddition(string rule){
    rulesGuiGroup.add(FRuleField.setup("F=>", rule));
}

void ofApp::XRuleFieldAddition(string rule){
    rulesGuiGroup.add(XRuleField.setup("X=>", rule));
}

void ofApp::GRuleFieldAddition(string rule){
    rulesGuiGroup.add(GRuleField.setup("G=>", rule));
}

void ofApp::HRuleFieldAddition(string rule){
    rulesGuiGroup.add(HRuleField.setup("H=>", rule));
}

void ofApp::FVisualFieldsAddition(){
    visualGuiGroup.add(FVariableLabel.setup("F", ""));
    visualGuiGroup.add(FVariableLengthField.setup("Line Length", 100));
    visualGuiGroup.add(FVariableColourFieldLabel.setup("Line Colour", ""));
    visualGuiGroup.add(FVariableColourField.set(ofColor(0, 0, 0)));

}

void ofApp::XVisualFieldsAddition(){
    visualGuiGroup.add(XVariableLabel.setup("X", ""));
    visualGuiGroup.add(XVariableLengthField.setup("Line Length", 100));
    visualGuiGroup.add(XVariableColourFieldLabel.setup("Line Colour", ""));
    visualGuiGroup.add(XVariableColourField.set(ofColor(0, 0, 0)));

}

void ofApp::GVisualFieldsAddition(){
    visualGuiGroup.add(GVariableLabel.setup("G", ""));
    visualGuiGroup.add(GVariableLengthField.setup("Line Length", 100));
    visualGuiGroup.add(GVariableColourFieldLabel.setup("Line Colour", ""));
    visualGuiGroup.add(GVariableColourField.set(ofColor(0, 0, 0)));

}

void ofApp::HVisualFieldsAddition(){
    visualGuiGroup.add(HVariableLabel.setup("H", ""));
    visualGuiGroup.add(HVariableLengthField.setup("Line Length", 100));
    visualGuiGroup.add(HVariableColourFieldLabel.setup("Line Colour", ""));
    visualGuiGroup.add(HVariableColourField.set(ofColor(0, 0, 0)));
}

void ofApp::FConfigureVariable(){
    string rule = FRuleField.getParameter().cast<string>();
    
    lSystem->DefineRule('F', rule);
    
    int length = FVariableLengthField.getParameter().cast<int>();
    ofColor colour = FVariableColourField.cast<ofColor>();
    
    renderConfigs['F'] = new RenderConfig(-length, colour);
}

void ofApp::XConfigureVariable(){
    string rule = XRuleField.getParameter().cast<string>();
    
    lSystem->DefineRule('X', rule);
    
    int length = XVariableLengthField.getParameter().cast<int>();
    ofColor colour = XVariableColourField.cast<ofColor>();
    
    renderConfigs['X'] = new RenderConfig(-length, colour);
}

void ofApp::GConfigureVariable(){
    string rule = GRuleField.getParameter().cast<string>();
    
    lSystem->DefineRule('G', rule);
    
    int length = GVariableLengthField.getParameter().cast<int>();
    ofColor colour = GVariableColourField.cast<ofColor>();
    
    renderConfigs['G'] = new RenderConfig(-length, colour);
}

void ofApp::HConfigureVariable(){
    string rule = HRuleField.getParameter().cast<string>();
    
    lSystem->DefineRule('H', rule);
    
    int length = HVariableLengthField.getParameter().cast<int>();
    ofColor colour = HVariableColourField.cast<ofColor>();
    
    renderConfigs['H'] = new RenderConfig(-length, colour);
}

void ofApp::CreateSoundGui(){
    soundGui.setup("Sound Config");

    soundGui.add(soundVolume.set("volume", 0.5));
    soundVolume.setMax(1);
    soundVolume.setMin(0);

    soundGui.add(soundDuration.set("note length", 0.5));
    soundDuration.setMax(1);
    soundDuration.setMin(0);
    
    soundGui.add(playSoundButton.setup("Play"));
    playSoundButton.addListener(this, &ofApp::PlaySound);
}

void ofApp::PlaySound(){
    SonicTurtle* sonicTurtle = new SonicTurtle(lSystem->getLastSentence());
    sonicTurtle->GenerateScore();
    currentScore = sonicTurtle->score;
    currentPlayerPhase = 0;
    currentPlayerNote = 0;
    ofSoundStreamSetup(2, 0);
}

void ofApp::audioOut( float * output, int bufferSize, int nChannels ) {
    Note * note = currentScore.at(currentPlayerNote);
    float pitchMultiple = powf(pitchRatio, note->pitch);
    
    for(int i = 0; i < bufferSize * nChannels; i += 2) {
        float sample = soundVolume*sin(currentPlayerPhase*pitchMultiple); // generating a sine wave sample
        output[i] = sample; // writing to the left channel
        output[i+1] = sample; // writing to the right channel
        currentPlayerPhase += 0.05;
     }
    
    if((currentPlayerPhase/soundDuration) > (1000 * note->duration)) {
        currentPlayerPhase = 0;
        currentPlayerNote++;
    }
    
    if(currentPlayerNote == currentScore.size()){
        ofSoundStreamClose();
    }
}
