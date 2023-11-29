//
//  Turtle.hpp
//  LSystem
//
//  Created by thomas lawrence on 28/11/2023.
//

#ifndef Turtle_hpp
#define Turtle_hpp

#include <stdio.h>

#endif /* Turtle_hpp */

class Sentence;

class Turtle  {
    public:
        Turtle(Sentence * sentence, float length, float angle);
        Sentence * sentence;
        float length;
        float angle;
        void Render();
};
