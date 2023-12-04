//
//  Note.hpp
//  LSystem
//
//  Created by thomas lawrence on 02/12/2023.
//

#ifndef Note_hpp
#define Note_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* SonicTurtle_hpp */

// Class to store parameters related to a musical note
class Note  {
    public:
        Note(int duration, int pitch);
        int duration;
        int pitch;
};
