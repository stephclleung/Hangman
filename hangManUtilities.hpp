//
// Created by Sleung on 1/31/2019.
//

#ifndef HANGMAN_HANGMANUTILITIES_HPP
#define HANGMAN_HANGMANUTILITIES_HPP
#include <iostream>
#include <string>
#include <fstream>
#include "theMan.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;

string userPrompts();
bool userInputCheck(string input);
void getWordFromFile(vector<string>* word_choice );
void gameOverHandling(Man* currentMan, string guess, string choice);
void printWords(vector<string> word_choice);
void printVisual(Man* currentMan);


#endif //HANGMAN_HANGMANUTILITIES_HPP

