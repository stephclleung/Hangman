//
// Created by DehMoi on 1/31/2019.
//

#include "hangManUtilities.hpp"

string userPrompts(){

    string input;
    cout << "Start guessing! What's your guess? " << endl;
    getline(cin, input);

    return input;
}

bool userInputCheck(string input){

   return !input.empty();
}

void getWordFromFile(vector<string>* word_choice){

    std::ifstream word_file;
    word_file.open("C:\\Users\\DehMoi\\CLionProjects\\HangMan\\hangman.txt");

    if(word_file.is_open()){
        string line;
        while(word_file >> line){

            (*word_choice).push_back(line);
        }
        word_file.close();
    }

    else{

        cout << "Error. Cannot open file. Exiting";
    }

}

void printWords(vector<string> word_choice){

    for (auto word : word_choice){
        cout << word << endl;
    }

}

void printVisual(Man* currentMan){

    while(currentMan){

        cout << "Stage " << currentMan->getStage() << endl;
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" <<endl;
        printHangManAsciiArt(currentMan);
        cout << "||||||||||||||||||||||||||||||||||||||||||||||||" <<endl;

        currentMan = currentMan->getNext_stage();
    }

}

void gameOverHandling(Man* currentMan, string guess, string choice){
    if(currentMan){

        cout << "Well done! You guessed it right." << endl
             << "The answer is " << guess << " , " <<  choice << "!" << endl;
    }
    else{

        cout << "You used up all your chances! The answer was " << choice << endl;
    }
}