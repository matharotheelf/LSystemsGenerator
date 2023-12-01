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
    ofPushMatrix();
    ofTranslate(512, 768);
    ofScale(scaleFactor);
    ofSetLineWidth(lineWeight);
    for(char character : sentence->sentence) {
        map<char, RenderConfig *>::iterator matchingConfig = variableRenderConfig.find(character);
        
        if(matchingConfig != variableRenderConfig.end()) {
            RenderConfig * config = matchingConfig->second;
            ofSetColor(config->lineColour);
            ofDrawLine(0,0,0,config->lineLength);
            ofTranslate(0,config->lineLength);
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
    ofPopMatrix();
}

void Turtle::SetSentence(Sentence * cSentence) {
    sentence = cSentence;
}
