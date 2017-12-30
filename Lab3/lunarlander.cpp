//
//  lunarlander.cpp
//  Lab3
//
//  Created by Ben Brown on 1/26/17.
//
//
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>
#include <cassert>

#include "lunarlander.h"

using namespace std;


void lunarlander::setFlowRate(double newRate){
    assert(newRate>0.0 && newRate<1.0);
    flowRate = newRate;                     //sets the new flow rate
}

void lunarlander::timePassage(double seconds){
    double t = seconds;                          //initializes local variable t that is equal to seconds
    
    if (flowRate>0&&fuel==0){                    //if there is no fuel then there is no flow rate  
        flowRate = 0;
    }
    velocity += (t*(((flowRate*maxThrust)/getMass())-1.62));     //calculates the change in velocity and adds the value to the current velocity
    altitude += (velocity*t);                                    //calculates the change in altitude which is negative and adds it to the current altitude
    fuel -= t*flowRate*maxFuelRate;                              //subtracts fuel as the rocket uses it up

    if(altitude < 0){                                           //condition where the rocket has reached the moon
	altitude = 0;
	velocity = 0;
    }

    if(fuel<0){                                               //condition where the rocket has run out of fuel
	fuel = 0;
    }

}

//constructor that sets variables
lunarlander::lunarlander(){
    flowRate = 0;
    velocity = 0;
    altitude = 1000;
    fuel = 1700;
}
