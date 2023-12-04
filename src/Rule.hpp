//
//  Rule.hpp
//  LSystem
//
//  Created by thomas lawrence on 28/11/2023.
//

#ifndef Rule_hpp
#define Rule_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Rule_hpp */

// Store the inputs and outputs of a rule
class Rule  {
    public:
        Rule(char cInput, string cOutput);
        char input;
        string output;
};
