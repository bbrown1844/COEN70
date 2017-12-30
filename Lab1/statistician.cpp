//
//  Lab2.cpp
//  Lab2
//
//  
//
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>
#include <cassert>


#include "statistician.h"
using namespace std;


void statistician::next_number(double num){
    sum1 = sum1 + num;                          //calculates sum
    last1 = num;                    
    mean1 = (sum1)/(double)(length1+1);         //calculates the mean, length is +1 because length hasnt been incremented yet 
   
    if(num < smallest1 && length1>0){           //checks to see if the number entered is smaller than the current smallest number
       smallest1 = num;
    }
    else if (length1 == 0){                     //if the set is empty
	smallest1 = num;
    }
    if(num >largest1 && length1>0){             //same implementation as above
        largest1 = num;
    }
    else if(length1 == 0){
	largest1 = num;
    }
    length1++;                                  //increments length
}

int statistician::length(){                     //insures that length is not negative and returns length
    assert(length1>=0);
    return length1;
}
  
//the following functions insure that the set is not empty and return their respected values
double statistician::last(){    
    assert(length1>0);
    return last1;
}

double statistician::sum(){
    assert(length1>0);
    return sum1;
}

double statistician::mean(){
    assert(length1>0);
    return mean1;
}

double statistician::smallest(){
    assert(length1>0);
    return smallest1;
}

double statistician::largest(){
    assert(length1>0);
    return largest1;
}

void statistician::erase(){     //erases the set and sets everything to 0
    sum1 = 0;
    length1 = 0;
    largest1 = 0;
    smallest1 = 0;
    mean1 = 0;
}

//constructor
statistician::statistician(){       //creates an empty set
    length1 = 0;
    last1 = 0;
    sum1 = 0;
    smallest1 = 0;
    largest1 = 0;
}

//member function
statistician statistician::operator=(const statistician&s2){    //overrides = operator by setting all the member variables equal to s2
    length1 = s2.length1;
    sum1 = s2.sum1;
    largest1 = s2.largest1;
    smallest1 = s2.smallest1;
    mean1 = s2.mean1;
    return *this;                   //returns a pointer of type statistician
}

//non member function
statistician operator+(const statistician&s1, const statistician&s2){     //takes in two arguments the two objects to be added together
    statistician newStat;  //creates new object 
    //adds all the member variables together
    newStat.length1 = s1.length1 + s2.length1;
    newStat.sum1 = s1.sum1 + s2.sum1;
    newStat.largest1 = s1.largest1 + s2.largest1;
    newStat.smallest1 = s1.smallest1 + s2.smallest1;
    newStat.mean1 = s1.mean1 + s2.mean1;
    return newStat;   //returns a statistician object
}
