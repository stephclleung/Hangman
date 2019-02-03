#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <algorithm> //std::transform
#include <cctype>

#include "theMan.hpp"
#include "hangManUtilities.hpp"


using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::getline;
using std::endl;
using std::tolower;
using std::transform;


int main() {

    //Container for words. Read from file and save to container
    vector<string> word_choice;
    getWordFromFile(&word_choice);

    bool gameOn = true;

    while (gameOn){

        //Set up the first visual and link up the rest.
        Man* currentMan = hangManSetup();

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

            cout << "You entered: " << input << endl;
            userInputProcess(&input, "Empty inputs not accepted. At least TRY not to kill the man yo....");


            long found = choice.find(input);
            if (found != string::npos){ //until end of the string, as a return vale means "no matches"

                if (input.size() == 1) {

                    for (int i = found; i < choice.size(); i++) {

                        if( input[0] == choice[i]){

                            guess[2 * i] = choice[i];
                        }
                    }
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
                if(currentMan){
                    //If still have a number of guesses:
                    cout << 7 - (currentMan->getStage()) << " chances left! " << guess <<  endl;
                }

            }

        }


        gameOverHandling(currentMan, guess, choice);
        hangManDestruct();

        string again;
        cout << "Play again? " << endl;
        getline(cin, again);
        userInputProcess(&again, "Empty input not accepted. Please try again.");

        if(again.compare("yes") != 0){

            gameOn = false;

        }


    }

    return 0;

}