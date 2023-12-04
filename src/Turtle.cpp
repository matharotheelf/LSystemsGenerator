//
//  Turtle.cpp
//  LSystem
//
//  Created by thomas lawrence on 28/11/2023.
//

#include "Turtle.hpp"
#include "Sentence.hpp"
#include "RenderConfig.hpp"

Turtle::Turtle(Sentence * cSentence, float cAngle, map<char, RenderConfig *> cVariableRenderConfig){
    sentence = cSentence;
    angle = cAngle;
    variableRenderConfig = cVariableRenderConfig;
}

void Turtle::Render(float scaleFactor, float lineWeight){
    // Save current transformation state
    ofPushMatrix();
    // Translate to screen bottom
    ofTranslate(512, 768);
    
    // Scale depending on zoom settings
    ofScale(scaleFactor);
    
    // Set line with depending on branch width settings

    ofSetLineWidth(lineWeight);
    for(char character : sentence->sentence) {
        // Find if character matches key in the variable render config
        map<char, RenderConfig *>::iterator matchingConfig = variableRenderConfig.find(character);
        
        // If matching key render a line
        if(matchingConfig != variableRenderConfig.end()) {
            RenderConfig * config = matchingConfig->second;
            ofSetColor(config->lineColour);
            ofDrawLine(0,0,0,config->lineLength);
            ofTranslate(0,config->lineLength);
        // Follow operations for constant values
        } else if (character == '+') {
            ofRotate(angle);
        } else if (character == '-') {
            ofRotate(-angle);
        } else if (character == '[') {
            ofPushMatrix();
        } else if (character == ']') {
            ofPopMatrix();
        }
    }
    // Return screen back to orignal transformation state
    ofPopMatrix();
}

void Turtle::SetSentence(Sentence * cSentence) {
    sentence = cSentence;
}
