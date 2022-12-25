#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "graphics.h"
using namespace std;

//Drawing the art line by line from text files
void draw(string input){
    fstream newfile;
    newfile.open("ASCII_Art/"+input,ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string tp;
        while(getline(newfile, tp)){ //read data from file object and put it into string.
            cout << tp << "\n"; //print the data of the string
        }
      newfile.close(); //close the file object.
    }
}


//Welcome message with basic terminal graphics
void graphics::prologue(){
    draw("prologue.txt");
    cout << "Press any key to start... esc to Escape..." << endl;
    return;
}

//Honor Art
void graphics::honor(){
    draw("honor.txt");
    return;
}

//World Text Art
void graphics::world_art(){
    draw("world_art.txt");
    return;
}

//Player lost the game
void graphics::defeated(){
    draw("defeated.txt");
    return;
}

//Epilogue
void graphics::epilogue(){
    draw("epilogue.txt");
    return;
}