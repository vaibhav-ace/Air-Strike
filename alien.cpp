#include "alien.h"
#include <iostream>
#include <string>
using namespace std;

    alien::alien(){
        //constructor variables
    }

    int alien::get_health(){
        return health;
    }

    void alien::set_health(int hp){
        health=hp;
    }

    alien::~alien(){
        //free dynamic memory
    }