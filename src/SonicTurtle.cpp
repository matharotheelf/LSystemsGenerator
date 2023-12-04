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

void SonicTurtle::GenerateScore() {
    score.clear();

    // Stores pitch and durations for notes
    int pitch = 0;
    int noteDuration = 0;
    
    // Stores the saved values of pitch and duration for when to return to previous values
    vector<int> poppedPitches;
    vector<int> poppedDurations;
    
    for(char character : sentence->sentence) {
        // F increases note length
        if (character == 'F') {
            noteDuration++;
        // increment pitch
        } else if (character == '+') {
            pitch++;
        // decrement pitch
        } else if (character == '-') {
            pitch--;
        // Store current pitch and duration and return duration to 0
        } else if (character == '[') {
            poppedPitches.push_back(pitch);
            poppedDurations.push_back(noteDuration);
            noteDuration = 0;
        // Save the note and return to saved pitch value
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
