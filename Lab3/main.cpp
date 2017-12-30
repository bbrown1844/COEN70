#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <cassert>
#include "lunarlander1.h"

using namespace std;

void display(lunarlander lander) {
  //initial
  /*  flowRate=0;
    velocity=0;
    altitude=1000;
    fuel=1700;
    mass=900;
    maxFuelRate=10; */
  cout<<"Flow rate: "<< lander.flowRate<<endl;
  cout<<"Velocity: "<<lander.velocity<<endl;
  cout<<"Altitude: "<<lander.altitude<<endl;
  cout<<"Fuel: "<<lander.fuel<<endl;
  cout<<"Mass: "<<lander.mass<<endl;
  cout<<"Max Fuel Rate: "<<lander.maxFuelRate<<endl;
  cout<<"Max Thrust: "<<lander.maxThrust<<endl;

  lander.setFlowRate(.5);
  cout<<"new flow: "<<lander.flowRate<<endl;

  lander.timePassage(.1);
  cout<<"New Velocity: "<<lander.velocity<<endl;
  cout<<"New Altitude: "<<lander.altitude<<endl;
  cout<<"New Fuel Amount: "<<lander.fuel<<endl;


}


int main(){
lunarlander lander1;
display(lander1);
}
