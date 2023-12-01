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
        map<char, RenderConfig *> variableRenderConfig;
        Sentence * sentence;
        float angle;
        void Render();
    void SetSentence(Sentence * sentence);
};
