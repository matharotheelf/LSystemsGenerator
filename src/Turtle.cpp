//
//  Turtle.cpp
//  LSystem
//
//  Created by thomas lawrence on 28/11/2023.
//

#include "Turtle.hpp"
#include "Sentence.hpp"

Turtle::Turtle(Sentence * cSentence, float cLength, float cAngle){
    sentence = cSentence;
    length = cLength;
    angle = cAngle;
}

void Turtle::Render(){
    for(char character : sentence->sentence) {
        if (character == 'F') {
            ofLine(0,0,0,length);
            ofTranslate(0,length);
        } else if (character == 'G') {
            ofTranslate(0,length);
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
}
