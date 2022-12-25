#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "commands.h"
#include "graphics.h"
using namespace std;



//All functions, except for classes used in the game are given below



//----------------------------------------------------------------------------------------------------------------------------------
string prologue(){

    //declaring variables
    string start="";
    string choice="";
    string instructions="";
    graphics g;
    string blank_key;
    g.prologue();

    getline(cin,start);
    system("clear");
    if (start=="esc"){
        return start;
    }

    //Game description
    cout << "----------------------------------------------------------------------------------------------------------------------------------" <<endl;
    g.world_art();
    cout << "Welcome to Air Strike!" << endl;
    cout << "This game is like the classic game of Battleship..." << endl;
    cout << "Aliens will try to invade your home planet and destroy humankind forever..." << endl;
    cout << "As the hero of the multiplanetary civilization of humanity, it falls upon your shoulders to protect";
    cout << "your kind from the attack of ruthless aliens..." << endl;
    cout << "Press 'i' for instructions, any other key to continue" << endl;

    //Instructions

    getline(cin,instructions);
    system("clear");

    if (instructions=="i"){
        cout << "Aliens will try and invade you home planet. To save them you must detect the alien spaceships ";
        cout << "before they reach the firing fort of humanity..." << endl;
        cout << "Your job involves correctly firing a light beam at the next enemy position...";
        cout << "Autolock AI will help you to narrow enemy locations in the next iteration..." << endl;
        cout << "Guess the correct co-ordinates of the enemy's move...Pick a row and column upon AI requests..." << endl;
    }
    cout << "Please pick a difficulty level from:\t'easy'...'medium'...'hard'..." << endl;
    getline(cin,choice);
    cout << "Good Luck...Game Starts..." << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------" <<endl;
    cout << "Press any key to continue..." << endl;
    getline(cin,blank_key);
    system("clear");


    return choice;
}


//----------------------------------------------------------------------------------------------------------------------------------
//random number generator
int random_numberx(){
    srand(time(0));
    int random = 0 + rand() % 10;
    return random;
}