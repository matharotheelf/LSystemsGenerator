#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Loads xml document defining L-System presets
    presetSettings.loadFile("presetSettings.xml");
    
    configurationGui.setup("Configuration");
    
    // Button which generates the L-System setup with callback function
    configurationGui.add(generateLSystemButton.setup("Generate L-System"));
    generateLSystemButton.addListener(this, &ofApp::generateLSystemButtonPressed);

    // Settings GUI
    configurationGui.add(lsystemGuiGroup.setup("L-System Settings"));
    DefinePresetsGui();
    lsystemGuiGroup.add(iterationsLabel.setup("Max Iterations", ""));
    lsystemGuiGroup.add(iterationsField.setup(5));
    iterationsField.setMax(15);
    iterationsField.setMin(1);
    
    // Rules GUI
    configurationGui.add(rulesGuiGroup.setup("Rules"));

    // Visual GUI
    configurationGui.add(visualGuiGroup.setup("Visual Settings"));
    
    // Populates GUI with presets based on the default preset
    LoadPresetConfiguration(defaultPreset);
    
    RenderConstantsKey();
    
    // GUI for audio which is hidden until L-System is generated
    CreateSoundGui();
}

void ofApp::draw(){
    if(turtle != NULL) {
        turtle->Render(scaleFactor, lineWeight);
        soundGui.draw();
    }
    
    configurationGui.draw();
}

void ofApp::generateLSystemButtonPressed(){
    configurationGui.minimize();

    // Ger L-System parameters from GUI settings
    string axiom = axiomField.getParameter().cast<string>();
    float angle = angleField.getParameter().cast<int>();
    int iterations = iterationsField.getParameter().cast<int>();
    
    lSystem = new LSystem(axiom, iterations);
   
    // Clear existing render configs this object stores the rendering values related to variables
    renderConfigs.clear();
    
    // Create configs based on each variable this needs to be dried up to remove repitition
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

    // Generates the first sentence of L-System
    lSystem->GenerateSentence();

    // Creates turtle to render L-System
    turtle = new Turtle(lSystem->getLastSentence(), angle, renderConfigs);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // This kay generates a new setence for the L-System
    // and updates the renderer with the new sentence
    // does not run if L-System not initialised
    if(key == ' ' && turtle != NULL && lSystem != NULL){
        lSystem->GenerateSentence();
        turtle->SetSentence(lSystem->getLastSentence());
    }
    
    // Keys for zooming in and out
    if(key == '+'){
        scaleFactor = scaleFactor*1.5;
    } else if(key == '-') {
        scaleFactor = scaleFactor/1.5;
    }
    
    // Keys for incrementing line weight
    if(key == ']'){
        lineWeight = lineWeight*1.2;
    } else if(key == '[') {
        lineWeight = lineWeight/1.2;
    }
}

// Repetition of these function needed to be removed currently present because listener
// not compatible with passing arguments to function

void ofApp::SelectPreset1(){
    LoadPresetConfiguration(presets[0]);
}

void ofApp::SelectPreset2(){
    LoadPresetConfiguration(presets[1]);
}

void ofApp::SelectPreset3(){
    LoadPresetConfiguration(presets[2]);
}

void ofApp::SelectPreset4(){
    LoadPresetConfiguration(presets[3]);
}

void ofApp::SelectPreset5(){
    LoadPresetConfiguration(presets[4]);
}

void ofApp::SelectPreset6(){
    LoadPresetConfiguration(presets[5]);
}


void ofApp::SelectPreset7(){
    LoadPresetConfiguration(presets[6]);
}

void ofApp::SelectPreset8(){
    LoadPresetConfiguration(presets[7]);
}

void ofApp::SelectPreset9(){
    LoadPresetConfiguration(presets[8]);
}

void ofApp::SelectPreset10(){
    LoadPresetConfiguration(presets[9]);
}

void ofApp::SelectPreset11(){
    LoadPresetConfiguration(presets[10]);
}

void ofApp::LoadPresetConfiguration(string configurationName){
    // Move to name space of selected configuration
    presetSettings.pushTag("root");
    presetSettings.pushTag(configurationName);
    
    // Get angle and axiom values
    string configAxiom = presetSettings.getValue("axiom", "F");
    float angleValue  = presetSettings.getValue("angle", 30);
    
    // Enter Rules namespace
    presetSettings.pushTag("rules");

    // Set the total alphabet used by hte preset
    SetConfigAlphabet();
    
    // Update the GUI fields
    RenderRulesFields(configAxiom);
    RenderVisualFields(angleValue);

    // After values are read leave the namespace of the configuration
    presetSettings.popTag();
    presetSettings.popTag();
    presetSettings.popTag();
}

void ofApp::RenderRulesFields(string axiom){
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
    rulesGuiGroup.add(axiomField.setup("Axiom", axiom));
}

void ofApp::RenderVisualFields(int angle){
    // Clear existing gui fields
    visualGuiGroup.clear();
    
    // Set up angle field with preset value
    visualGuiGroup.add(angleLabel.setup("Angle", ""));
    
    visualGuiGroup.add(angleField.setup(angle));
    
    visualGuiGroup.add(variablesLabel.setup("Variables", ""));
    
    // For all presets in alphabet set up their visual fields
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

void ofApp::RenderConstantsKey(){
    // Keys related to operations of constants
    configurationGui.add(ConstantsKey.setup("Constants Key"));
    ConstantsKey.add(ConstantLabel1.setup("+", "Positive rotation"));
    ConstantsKey.add(ConstantLabel2.setup("-", "Negative rotation"));
    ConstantsKey.add(ConstantLabel3.setup("[", "Store Positon"));
    ConstantsKey.add(ConstantLabel4.setup("]", "Go stored position"));
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

// Need to remove repitition here
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

// Need to remove repitition here
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

// Need to remove repitition here
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
    // Generates gui with sound fields
    soundGui.setup("Sound Config");
    soundGui.add(soundVolume.set("volume", 0.5));
    soundVolume.setMax(1);
    soundVolume.setMin(0);

    soundGui.add(soundDuration.set("note length", 0.5));
    soundDuration.setMax(1);
    soundDuration.setMin(0);
    
    soundGui.add(playSoundButton.setup("Play"));
    // Binds function to play sound to play button
    playSoundButton.addListener(this, &ofApp::PlaySound);
    RenderInteractionKey();
}

void ofApp::RenderInteractionKey(){
    // Key which shows hotkeys
    soundGui.add(ZoomLabel.setup("+ -", "Zoom in/out"));
    soundGui.add(BranchWidthLabel.setup("[ ]", "Vary branch width"));
}

void ofApp::DefinePresetsGui(){
    // Shows the list of preset buttons
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
    
    lsystemGuiGroup.add(presetButton11.setup(presets[10]));
    presetButton11.addListener(this, &ofApp::SelectPreset11);
}

void ofApp::PlaySound(){
    // Creates sonic turtle to create musical score
    SonicTurtle* sonicTurtle = new SonicTurtle(lSystem->getLastSentence());
    sonicTurtle->GenerateScore();
    // saves the generated score to the current one
    currentScore = sonicTurtle->score;
    // Resets player variables to zero to start from the top
    currentPlayerPhase = 0;
    currentPlayerNote = 0;
    // Sets up audio stream with two channels
    ofSoundStreamSetup(2, 0);
}

void ofApp::audioOut( float * output, int bufferSize, int nChannels ) {
    // Get the current note of score
    Note * note = currentScore.at(currentPlayerNote);
    // The pitch multiple is related to the chromatic scale 2^-12
    float pitchMultiple = powf(pitchRatio, note->pitch);
    
    for(int i = 0; i < bufferSize * nChannels; i += 2) {
        float sample = soundVolume*sin(currentPlayerPhase*pitchMultiple); // generating a sine wave sample
        output[i] = sample; // writing to the left channel
        output[i+1] = sample; // writing to the right channel
        currentPlayerPhase += phaseIncrement;
     }
    
    // If phase has reached a sufficent value move to the next note
    if((currentPlayerPhase/soundDuration) > (audioSpeedConstant * note->duration)) {
        currentPlayerPhase = 0;
        currentPlayerNote++;
    }
    
    // When reach final note close audio steam
    if(currentPlayerNote == currentScore.size()){
        ofSoundStreamClose();
    }
}
