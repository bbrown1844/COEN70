//
//  lunarlander.h
//  Lab3
//
//  Created by Ben Brown on 1/26/17.
//
//

#ifndef lunarlander_h
#define lunarlander_h

#include <stdio.h>


class lunarlander{

    double flowRate;
    double velocity;
    double altitude;
    double fuel;
    static const int mass = 900;
    static const int maxFuelRate = 10;
    static const int maxThrust = 5000;
    
public:

    //constructor
    lunarlander();
    
    //Precondition: none
    //Postcondition: Must return a double between 0.0 and 1.0
    //Big O: O(1)
    double getFlowRate() const{return flowRate;};
    //Precondition: none
    //Postcondition: Must return a double 
    //Big O: O(1)
    double getVelocity() const{return velocity;};
    //Precondition: none
    //Postcondition: Must return a double less than or equal to 1000 
    //Big O: O(1)
    double getAltitude() const{return altitude;};
    //Precondition: none
    //Postcondition: Must return a double less than or equal to 1700 
    //Big O: O(1)
    double getFuel() const{return fuel;};
    //Precondition: none
    //Postcondition: Must return a double less than or equal to 2600
    //Big O: O(1)
    double getMass() const{return mass+fuel;};
    //Precondition: none
    //Postcondition: Must return the value set for MaxFuelRate
    //Big O: O(1)
    double getMaxFuelRate() const{return maxFuelRate;};
    //Precondition: none
    //Postcondition: Must return the value set for maxThrust 
    //Big O: O(1)
    double getMaxThrust() const{return maxThrust;};


    //Modifying member functions

    //Preconditions: Input should be between 0.0 and 1.0
    //Postcondition: flowRate is equal to the rate input 
    //Big O: O(1)
    void setFlowRate(double newRate);

    //Precondition: seconds is greater than 0
    //Postconditions: altitude and fuel cannot be negative and flowrate must be 0 if fuel equals 0
    //Big O: O(1)
    void timePassage(double seconds);
    
    
};

#endif
