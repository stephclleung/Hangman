//
// Created by DehMoi on 1/31/2019.
//

#include "theMan.hpp"


void hangManSetup(){


    string firstManVisual = " |\n |\n |\n |\n |\n |\n |\n";
    string secondManVisual = " |--------------------------------\n |\n |\n |\n |\n |\n |\n";
    string thirdManVisual = " |--------------------------------\n |\n |\n |\n |\n |\n |\n_|_______\n";
    string fourthManVisual = " |--------------------------------|\n"
                             " |                                |\n |\n |\n |\n |\n |\n_|_______\n";
    string fifthManVisual = " |--------------------------------|\n"
                            " |                                |\n"
                            " |                                O\n |\n |\n |\n |\n_|_______\n";

    string sixthManVisual = " |--------------------------------|\n"
                            " |                                |\n"
                            " |                                O\n"
                            " |                               -|-\n |\n |\n |\n_|_______\n";

    string seventhVisual = " |--------------------------------|\n"
                           " |                                |\n"
                           " |                                O\n"
                           " |                               -|-\n"
                           " |                               /\\\n |\n |\n_|_______\n";

    vector <string> manAsciiArt = {firstManVisual, secondManVisual, thirdManVisual,
                                   fourthManVisual, fifthManVisual, sixthManVisual, seventhVisual};

    //Set the first ascii art
    Man* firstMan = new Man();
    firstMan->setVisual(firstManVisual);

    //Temp pointer for next linked list node
    Man* temp = firstMan;
    for (int x = 0; x < 7; x++){

        //Make all dem asciis
        temp->setNext_stage(new Man());
        temp = temp->getNext_stage();
        temp->setVisual(manAsciiArt[x]);
    }


//    temp = firstMan;
//    while(temp){
//
//        cout << temp->getVisual() << endl;
//
//        temp = temp->getNext_stage();
//
//    }
//
//    temp=firstMan->getNext_stage();
//
//    while(temp){
//
//        Man* toBeDel = temp;
//        temp = temp->getNext_stage();
//        free(toBeDel);
//
//    }

}



void hangManDestruct(){



}