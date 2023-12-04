//
//  Turtle.hpp
//  LSystem
//
//  Created by thomas lawrence on 28/11/2023.
//

#ifndef Turtle_hpp
#define Turtle_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Turtle_hpp */

class Sentence;
class RenderConfig;

class Turtle  {
    public:
        Turtle(Sentence * sentence, float angle, map<char, RenderConfig *> variableRenderConfig);
        void Render(float scaleFactor, float lineWeight);
        void SetSentence(Sentence * sentence);
    private:
        map<char, RenderConfig *> variableRenderConfig;
        Sentence * sentence;
        float angle;
};
