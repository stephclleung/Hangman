//
// Created by Sleung on 1/31/2019.
//

#ifndef HANGMAN_SYSTEMMESSAGES_HPP
#define HANGMAN_SYSTEMMESSAGES_HPP

#endif //HANGMAN_SYSTEMMESSAGES_HPP

#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::string;

class Man {

public:

    const string &getVisual() const {
        return visual;
    }

    void setVisual(const string &visual) {
        Man::visual = visual;
    }

    Man *getNext_stage() const {
        return next_man;
    }

    void setNext_stage(Man *next_man) {
        Man::next_man = next_man;
    }


    int getStage() const {
        return stage;
    }

    void setStage(int stage) {
        Man::stage = stage;
    }

private:
    int stage;
    string visual = "";
    Man* next_man = NULL;

};

Man* hangManSetup();
void hangManDestruct();
void printHangManAsciiArt(Man* thisMan);
