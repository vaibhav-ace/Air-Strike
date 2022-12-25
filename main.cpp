#include <iostream>
#include <string>
#include "alien.h"
#include "commands.h"
#include "graphics.h"
using namespace std;

int main(){

    //Game start
    system("clear");
    string blank_key;
    graphics g;
    string choice=prologue(); //Game description

    //User choice for difficulty level
    if (choice=="esc"){
        system("clear");
        g.defeated();
        return 0;
    }
    else if (choice=="easy"){
        easy();
    }
    else if (choice=="medium"){
        medium();
    }
    else if (choice=="hard"){
        hard();
    }
    else if (choice=="airstrike"){
        cout << "AI hack successful...Humanity protected against alien invasion..." << endl;
    }
    else{
        cout << "The AI detects a user input fault..." <<endl;
        cout << "Auto AI has set your default difficulty level to 'easy'" << endl;
        easy();
    }

    cout << "Press any key to continue..." << endl;
    getline(cin,blank_key);
    system("clear");

    g.epilogue(); //Game end description

    return 0;
}

/*Cheat Codes:
- "airstrike" in user difficulty choice hacks the game and ends it
- "1967" in co-ordinate input for hard mode gives location of enemy since, 1967 was when the first plastic battleship board game was produced

End of game!
*/