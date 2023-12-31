#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxDropdown.h"
#include "LSystem.hpp"
#include "Sentence.hpp"
#include "Rule.hpp"
#include "Turtle.hpp"
#include "SonicTurtle.hpp"
#include "Note.hpp"
#include "RenderConfig.hpp"
#include "ofxXmlSettings.h"

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void draw() override;
		void keyPressed(int key) override;
        void audioOut( float * output, int bufferSize, int nChannels ) override;
        
        void generateLSystemButtonPressed();
        void DefinePresetsGui();
        void LoadPresetConfiguration(string configurationName);
        void FRuleFieldAddition(string rule);
        void XRuleFieldAddition(string rule);
        void GRuleFieldAddition(string rule);
        void HRuleFieldAddition(string rule);
        void RenderRulesFields(string axiom);
        void RenderVisualFields(int angle);
        void RenderConstantsKey();
        void SetConfigAlphabet();
        void RenderInteractionKey();
        void FVisualFieldsAddition();
        void XVisualFieldsAddition();
        void GVisualFieldsAddition();
        void HVisualFieldsAddition();
        void FConfigureVariable();
        void XConfigureVariable();
        void GConfigureVariable();
        void HConfigureVariable();
    
        void SelectPreset1();
        void SelectPreset2();
        void SelectPreset3();
        void SelectPreset4();
        void SelectPreset5();
        void SelectPreset6();
        void SelectPreset7();
        void SelectPreset8();
        void SelectPreset9();
        void SelectPreset10();
        void SelectPreset11();
    
        void CreateSoundGui();
        void PlaySound();
        void AudioSetup();
    
        ofxPanel soundGui;
        ofParameter<float> soundVolume;
        ofParameter<float> soundDuration;
        ofxButton playSoundButton;
        float currentPlayerPhase = 0;
        int currentPlayerNote = 0;
        vector<Note *> currentScore;
        const float pitchRatio = 1.06;
        const float phaseIncrement = 0.05;
        const float audioSpeedConstant = 1000;

        LSystem* lSystem;
        Turtle* turtle;
        SonicTurtle* sonicTurtle;

        ofxPanel configurationGui;
        ofxButton generateLSystemButton;
    
        ofxGuiGroup lsystemGuiGroup;
        ofxLabel presetLabel;

        ofxButton presetButton1;
        ofxButton presetButton2;
        ofxButton presetButton3;
        ofxButton presetButton4;
        ofxButton presetButton5;
        ofxButton presetButton6;
        ofxButton presetButton7;
        ofxButton presetButton8;
        ofxButton presetButton9;
        ofxButton presetButton10;
        ofxButton presetButton11;

        ofxLabel iterationsLabel;
        ofxIntField iterationsField;
    
        ofxGuiGroup rulesGuiGroup;
        ofxTextField FRuleField;
        ofxTextField XRuleField;
        ofxTextField GRuleField;
        ofxTextField HRuleField;
        ofxLabel axiomlabel;
        ofxTextField axiomField;
    
        ofxGuiGroup visualGuiGroup;
        ofxLabel angleLabel;
        ofxIntField angleField;
        
        ofxLabel variablesLabel;
        ofxLabel FVariableLabel;
        ofxIntField FVariableLengthField;
        ofxLabel FVariableColourFieldLabel;
        ofParameter<ofColor> FVariableColourField;
        ofxLabel XVariableLabel;
        ofxIntField XVariableLengthField;
        ofxLabel XVariableColourFieldLabel;
        ofParameter<ofColor> XVariableColourField;
        ofxLabel GVariableLabel;
        ofxIntField GVariableLengthField;
        ofxLabel GVariableColourFieldLabel;
        ofParameter<ofColor> GVariableColourField;
        ofxLabel HVariableLabel;
        ofxIntField HVariableLengthField;
        ofxLabel HVariableColourFieldLabel;
        ofParameter<ofColor> HVariableColourField;
    
        ofxGuiGroup ConstantsKey;
        ofxLabel ConstantLabel1;
        ofxLabel ConstantLabel2;
        ofxLabel ConstantLabel3;
        ofxLabel ConstantLabel4;
    
        ofxGuiGroup InteractionKey;
        ofxLabel ZoomLabel;
        ofxLabel BranchWidthLabel;
        ofxLabel iterateLabel;

        ofParameterGroup configurationGroup;
    
        float scaleFactor = 1;
        float lineWeight = 1;

        ofxXmlSettings presetSettings;
        vector<char> configAlphabet;
        const char possibleAlphabet[4] = {'F', 'X', 'G', 'H'};
    
        map<char, RenderConfig *> renderConfigs;
    
        const string presets[11] = {
            "edgeRewriting1", "edgeRewriting2", "edgeRewriting3",
            "nodeRewriting1", "nodeRewriting2", "nodeRewriting3",
            "quadraticGosper", "weed", "bush", "peanoCurve",
            "quadraticSnowflake"
        };
    
        const string defaultPreset = "edgeRewriting1";
};
