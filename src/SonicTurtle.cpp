//
//  SonicTurtle.cpp
//  LSystem
//
//  Created by thomas lawrence on 02/12/2023.
//

#include "SonicTurtle.hpp"
#include "Sentence.hpp"
#include "RenderConfig.hpp"
#include "Note.hpp"

SonicTurtle::SonicTurtle(Sentence * cSentence){
    sentence = cSentence;
}

void SonicTurtle::Play(float * output, int bufferSize, int nChannels) {
//    float volumeValue = volume->cast<float>();
//
//    for(int i = 0; i < bufferSize * nChannels; i += 2) {
//      float sample = sin(currentPlayerPhase); // generating a sine wave sample
//      output[i] = sample; // writing to the left channel
//      output[i+1] = sample; // writing to the right channel
//      currentPlayerPhase += 0.05;
//    }
}

void SonicTurtle::GenerateScore() {
    score.clear();

    int pitch = 0;
    int noteDuration = 0;
    vector<int> poppedPitches;
    vector<int> poppedDurations;
    
    for(char character : sentence->sentence) {
        if (character == 'F') {
            noteDuration++;
        } else if (character == '+') {
            pitch++;
        } else if (character == '-') {
            pitch--;
        } else if (character == '[') {
            poppedPitches.push_back(pitch);
            poppedDurations.push_back(noteDuration);
            noteDuration = 0;
        } else if (character == ']') {
            Note* newNote = new Note(pitch, noteDuration);
            score.push_back(newNote);
            
            if (!poppedPitches.empty()){
                pitch = poppedPitches.back();
                poppedPitches.pop_back();
            }
            
            if (!poppedDurations.empty()){
                noteDuration = poppedDurations.back();
                poppedDurations.pop_back();
            }
        }
    }
}
