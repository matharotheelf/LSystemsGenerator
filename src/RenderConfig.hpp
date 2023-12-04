//
//  RenderConfig.hpp
//  LSystem
//
//  Created by thomas lawrence on 30/11/2023.
//

#ifndef RenderConfig_hpp
#define RenderConfig_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* RenderConfig_hpp */

// Class to store the visual rendering configuration of a given variable
class RenderConfig {
    public:
        RenderConfig(float lineLength, ofColor lineColour);
        float lineLength;
        ofColor lineColour;
};
