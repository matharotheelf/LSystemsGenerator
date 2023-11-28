//
//  LSystem.cpp
//  LSystem
//
//  Created by thomas lawrence on 28/11/2023.
//

#include "LSystem.hpp"
#include "Sentence.hpp"
#include "Rule.hpp"

LSystem::LSystem(string cAxiom) {
    axiom = new Sentence(cAxiom);
}

void LSystem::GenerateSentence(){
    Sentence * lastSentence = getLastSentence();
    Sentence * newSentence = lastSentence->ApplyRules(rules);
    
    sentences.push_back(newSentence);
}

void LSystem::DefineRule(char input, string output){
    Rule * rule = new Rule(input, output);
    
    rules.push_back(rule);
}

Sentence * LSystem::getLastSentence() {
    if(sentences.empty()) return axiom;
    
    return sentences.back();
}
