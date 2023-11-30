#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxDropdown.h"
#include "LSystem.hpp"
#include "Sentence.hpp"
#include "Rule.hpp"
#include "Turtle.hpp"

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
        LSystem lSystem = LSystem("F");

        ofxPanel configurationGui;
    
        ofxGuiGroup lsystemGuiGroup;
        ofxLabel lSystemLabel;
        ofxLabel presetLabel;
        ofxDropdown_<string> presetDropdown;
        ofxLabel iterationsLabel;
        ofxDropdown_<int> iterationsDropdown;
        ofxLabel stochaticLabel;
        ofxToggle stochasticToggle;
    
        ofxGuiGroup rulesGuiGroup;
        ofxLabel rulesLabel;
        ofxLabel firstRulelabel;
        ofxTextField firstRuleField;
        ofxLabel secondRulelabel;
        ofxTextField secondRuleField;
        ofxLabel thirdRulelabel;
        ofxTextField thirdRuleField;
        ofxLabel fourthRulelabel;
        ofxTextField fourthRuleField;
    
        ofxGuiGroup visualGuiGroup;
        ofxLabel visualLabel;
        ofxLabel angleLabel;
        ofxFloatField angleField;
        
        ofxLabel variablesLabel;
        ofxLabel firstVariablelabel;
        ofxIntField firstVariableLengthField;
        ofxColorSlider firstVariableColourField;
        ofxLabel secondVariablelabel;
        ofxIntField secondVariableLengthField;
        ofxColorSlider secondVariableColourField;
        ofxLabel thirdVariablelabel;
        ofxIntField thirdVariableLengthField;
        ofxColorSlider thirdVariableColourField;
        ofxLabel fourthVariablelabel;
        ofxIntField fourthVariableLengthField;
        ofxColorSlider fourthVariableColourField;
};
