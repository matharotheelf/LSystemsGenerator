//
//  Sentence.hpp
//  LSystem
//
//  Created by thomas lawrence on 28/11/2023.
//

#ifndef Sentence_hpp
#define Sentence_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Sentence_hpp */

class Rule;

// Class to store a sentence and generate next sentence from it
class Sentence  {
    public:
        Sentence(string cString);
        string sentence;
        Sentence * ApplyRules(vector<Rule *>);
    private:
        string ConvertCharacter(vector<Rule *>, char character);
};
