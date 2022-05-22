#include <iostream>
#include <string>
#include "alien.h"
#include "commands.h"
using namespace std;

int main(){
    //Game start


    string choice=prologue(); //Game description

    //User choice for difficulty level
    if (choice=="esc"){return 0;}
    else if (choice=="easy"){
        easy();
    }
    else if (choice=="medium"){
        medium();
    }
    else if (choice=="hard"){
        hard();
    }
    else{
        cout << "The AI detects a user input fault..." <<endl;
        cout << "Auto AI has set your default difficulty level to 'easy'" << endl;
        easy();
    }

    epilogue(); //Game end description

    return 0;
}

//Cheat Codes:



//End of game!