//
//  random.hpp
//  Lab2
//
//  Created by ben vahid squire brown on 1/19/17.
//

#ifndef random_h
#define random_h

#include <stdio.h>

class RandGen{
    //private variables
    int seed;
    int multiplier;
    int increment;
    int modulus;

public:
    //constructor
    RandGen(int seed,int multiplier,int increment,int modulus);
    //preconditon: values entered have to be ints
    //Big O:O(1) 
    void setSeed(int seed);
    //precondition: values entered have to be an int
    //Big O: O(1)
    double next();
    //postcondition: value returned has to be an int
    //Big O: O(1)
};

#endif /* random_hpp */
