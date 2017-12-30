#include "sequence4.h"
#include <iostream>

using namespace coen70_lab6B;

int main(){
  sequence<int> s1;
  sequence<int> s2;


  s1.insert(5);
  s1.insert(7);
  s1.insert(8);
  s1.attach(3);

  s1.start();
  std::cout<<s1.current()<<std::endl;
  s1.advance();
  std::cout<<s1.current()<<std::endl;
  s1.advance();
  std::cout<<s1.current()<<std::endl;
  s1.advance();
  std::cout<<s1.current()<<std::endl;
  std::cout<<"size1:"<<s1.size()<<std::endl;
  s2.attach(9);
  std::cout<<s2.size()<<std::endl;

  s2 = s1;

  s2.start();
  std::cout<<s2.current()<<std::endl;
  s2.advance();
  std::cout<<s2.current()<<std::endl;
  s2.advance();
  std::cout<<s2.current()<<std::endl;
  s2.advance();
  std::cout<<s2.current()<<std::endl;
  std::cout<<"size2:"<<s2.size()<<std::endl;


return 0;
}
