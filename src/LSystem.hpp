//
//  LSystem.hpp
//  LSystem
//
//  Created by thomas lawrence on 28/11/2023.
//

#ifndef LSystem_hpp
#define LSystem_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* LSystem_hpp */

class Rule;
class Sentence;

class LSystem {
    public:
        LSystem(string cAxiom, int cMaxIterations);
        vector<Rule *> rules;
        void GenerateSentence();
        void DefineRule(char input, string output);
        Sentence * getLastSentence();
    private:
        vector<Sentence *> sentences;
        int maxIterations;
        Sentence * axiom;
};
