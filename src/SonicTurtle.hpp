//
//  SonicTurtle.hpp
//  LSystem
//
//  Created by thomas lawrence on 02/12/2023.
//

#ifndef SonicTurtle_hpp
#define SonicTurtle_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* SonicTurtle_hpp */

class Sentence;
class Note;

class SonicTurtle  {
    public:
        SonicTurtle(Sentence * sentence);
        Sentence * sentence;
        vector<Note *> score;
        void Play(float * output, int bufferSize, int nChannels);
        void GenerateScore();
};
