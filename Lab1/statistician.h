//
//  Lab2.hpp
//  Lab2
//
//  Created by ben vahid squire brown on 1/19/17.
//  
//

#ifndef statistician_h
#define statistician_h

#include <stdio.h>

class statistician {               //class name
    
    //private class variables
    
    int length1;
    double sum1;
    double last1;
    double smallest1;
    double largest1;
    double mean1;
    
public:
        
    //constructor
    statistician();
    
    void next_number(double num);
    //precondition: Number entered has to be a double
    //O(1)

    //precondition for following functions: set cannot be empty 
    int length();
    //O(1)
    double last();
    //O(1)
    double sum();
    //O(1)
    double mean();
    //O(1)
    double smallest();
    //O(1)
    double largest();
    //O(1)
    void erase();
    //O(1)
    //override operators
    friend statistician operator+(const statistician&s1, const statistician&s2); //non member function so has to be made friend 
    statistician operator=(const statistician&s2); 
    
};

#endif /* Lab2_hpp */

