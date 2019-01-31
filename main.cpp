#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "theMan.hpp"

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::getline;
using std::endl;


int main() {

    vector<string> word_choice = {"apples", "bananas"};


    hangManSetup();

    //process one word
    string choice = word_choice[1];

    // Create spaces for the guess word.
    string guess = "";
    for (int i = 0; i < choice.size(); i++){

        guess.append("_ ");

    }

    //Variables for users to input
    string input;
    bool valid = true;

    cout << "Hangman! Your word has " << choice.size() << " characters. " << endl
        << guess << endl
        << "Start guessing! What's your guess? " << endl;

    getline(cin, input);

    cout << "You entered: " << input << endl;

    int found = choice.find(input);
    if (found != string::npos){ //until end of the string, as a return vale means "no matches"

        cout << "Yup! Letter " << input << " is at " << found << endl;
        //Reveal all guesses

        for (int i = 0; i < choice.size(); i++){

            if ( input[0] == choice[i]){

                guess[2 * i] = choice[i];
            }
        }

        cout << guess << endl;

    }
    else{

        cout << "Nope! Better luck next guess.\n";
        //Insert one more hangman slot.
    }

    return 0;
}