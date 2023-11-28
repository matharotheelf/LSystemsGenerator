//
//  Sentence.cpp
//  LSystem
//
//  Created by thomas lawrence on 28/11/2023.
//

#include "Sentence.hpp"
#include "Rule.hpp"

Sentence::Sentence(string cString){
    sentence = cString;
}

Sentence * Sentence::ApplyRules(vector<Rule *> rules){
    string newSentence;
    
    for(char character : sentence) {
        newSentence.append(ConvertCharacter(rules, character));
    }
    
    return new Sentence(newSentence);
}


string Sentence::ConvertCharacter(vector<Rule *> rules, char character){
    for(Rule* rule : rules) {
        if (rule->input == character) return rule->output;
    }
    
    string characterString;
    characterString.push_back(character);
    
    return characterString;
}
