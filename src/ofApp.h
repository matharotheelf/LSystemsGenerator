#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxDropdown.h"
#include "LSystem.hpp"
#include "Sentence.hpp"
#include "Rule.hpp"
#include "Turtle.hpp"
#include "RenderConfig.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;
    
        void generateLSystemButtonPressed();

        LSystem* lSystem;
        Turtle* turtle;

        ofxPanel configurationGui;
        ofxButton generateLSystemButton;
    
        ofxGuiGroup lsystemGuiGroup;
        ofxLabel presetLabel;
        ofxDropdown_<string> presetDropdown;
        ofxLabel iterationsLabel;
        ofxIntField iterationsField;
        ofxLabel stochaticLabel;
        ofxToggle stochasticToggle;
    
        ofxGuiGroup rulesGuiGroup;
        ofxTextField firstRuleField;
        ofxTextField secondRuleField;
        ofxTextField thirdRuleField;
        ofxTextField fourthRuleField;
        ofxLabel axiomlabel;
        ofxTextField axiomField;
    
        ofxGuiGroup visualGuiGroup;
        ofxLabel angleLabel;
        ofxIntField angleField;
        
        ofxLabel variablesLabel;
        ofxLabel firstVariableLabel;
        ofxIntField firstVariableLengthField;
        ofxLabel firstVariableColourFieldLabel;
        ofParameter<ofColor> firstVariableColourField;
        ofxLabel secondVariableLabel;
        ofxIntField secondVariableLengthField;
        ofxLabel secondVariableColourFieldLabel;
        ofParameter<ofColor> secondVariableColourField;
        ofxLabel thirdVariableLabel;
        ofxIntField thirdVariableLengthField;
        ofxLabel thirdVariableColourFieldLabel;
        ofParameter<ofColor> thirdVariableColourField;
        ofxLabel fourthVariableLabel;
        ofxIntField fourthVariableLengthField;
        ofxLabel fourthVariableColourFieldLabel;
        ofParameter<ofColor> fourthVariableColourField;
    
        ofParameterGroup configurationGroup;
    
        float scaleFactor = 1;
        float lineWeight = 1;
};
