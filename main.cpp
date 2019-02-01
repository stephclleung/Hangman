#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>


#include "theMan.hpp"
#include "hangManUtilities.hpp"


using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::getline;
using std::endl;


int main() {

    //Container for words. Read from file and save to container
    vector<string> word_choice;
    getWordFromFile(&word_choice);

    //Set up the first visual and link up the rest.
    Man* currentMan = hangManSetup();

    printVisual(currentMan);

    //Generate a word
    srand(time(NULL));
    string choice = word_choice[rand()%(word_choice.size())];

    // Create spaces for the guess word.
    string guess;
    //for (int i = 0; i < choice.size(); i++){
    for (auto chars : choice){

        guess.append("_ ");

    }

    //Variables for users to input
    string input;
    bool completed = false;

    cout << "Hangman! Your word has " << choice.size() << " characters. " << endl;

    while(currentMan && !completed){

        input = userPrompts();
        bool valid = false;

        while(!valid){

            cout << "You entered: " << input << endl;
            valid = userInputCheck(input);
            if(!valid){

                cout << "Empty inputs not accepted. At least TRY not to kill the man yo...." << endl;
                input = userPrompts();
                valid = userInputCheck(input);
            }
        }

        // process in put HERE
        // needs to differentiate between single char
        // and
        // whole ass strings

        long found = choice.find(input);
        if (found != string::npos){ //until end of the string, as a return vale means "no matches"

            //cout << "Yup! Letter " << input << " is at " << found << endl;
            //Reveal all guesses
//
//            for (int i = 0; i < choice.size(); i++){
//
//                if ( input[i] == choice[i]){
//
//                    guess[2 * i] = choice[i];
//                }
//            }
//
//            cout << guess << endl;
            if (input.size() == 1) {

                for (int i = found; i < choice.size(); i++) {

                    if( input[0] == choice[i]){

                        cout << guess[2*i] << " <---- before" << endl;
                        guess[2 * i] = choice[i];
                    }
                }
                cout << guess << " <---- after" << endl;

            }
            else if (input.size() == choice.size()){

                //whole word matches
                for (int i = 0; i < choice.size(); i++) {

                    guess[2 * i] = choice[i];
                }
            }

            cout << "Good guess! Updating your guess to : " << guess << endl;

            found = guess.find("_");
            if ( found == string::npos ){

                //Cannot find any more _, word is completed.
                completed = true;
            }



        }
        else{

            cout << "Nope! Better luck next guess.\n";
            //Insert one more hangman slot.
            printHangManAsciiArt(currentMan);
            currentMan = currentMan->getNext_stage();
            cout << 7 - (currentMan->getStage()) << " chances left!" << endl;
        }

    }

    cout << "Before end game" << endl;
    cout << choice << endl;
    gameOverHandling(currentMan, guess, choice);
    hangManDestruct();


    return 0;
}