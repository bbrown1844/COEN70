//
//  random.cpp
//  Lab2
//
//  Created by ben vahid squire brown on 1/19/17.
//
//
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>
#include "random.h"

using namespace std;


void RandGen::setSeed(int seed1){        //sets seed equal to the value passed in 
    seed = seed1;
}

double RandGen::next(){                         
    int next = (multiplier*seed+increment)%modulus;       //generates a new number
    return next;
}

RandGen::RandGen(int multiplier,int seed,int increment,int modulus){       //constructor that sets values for initial object
    this->seed = seed;
    this->multiplier = multiplier;
    this->increment = increment;
    this->modulus = modulus;
}


