#include "pqueue.h"
#include <iostream>

using namespace coen70_lab9;

int main(){

PriorityQueue test,test2;
test.insert(5,7);
test.insert(3,8);
test.insert(8,3);
test.insert(2,4);
test.insert(6,8);
test.insert(7,4);
/*
std::cout<<test.get_front()<<std::endl;
std::cout<<test.get_front()<<std::endl;
std::cout<<test.get_front()<<std::endl;
*/
test2 = test;
PriorityQueue test3(test2);
std::cout<<test3.size()<<std::endl;
std::cout<<test3.get_front()<<std::endl;
std::cout<<test3.get_front()<<std::endl;
std::cout<<test3.get_front()<<std::endl;
std::cout<<test3.get_front()<<std::endl;
std::cout<<test3.get_front()<<std::endl;
std::cout<<test3.get_front()<<std::endl;


return 0;
}
