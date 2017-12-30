#include "mystring.h"

using namespace coen70_lab;

int main(){
 char array[6] = "hello";
 char array2[6] = "anima";
 char reserve[8] = "he";
 char sub[4] = "he";
 char c = 'h';
 string mystringout,mystringout2,mystring(sub),mystring2(array2),mystringcheck(sub);

 mystring2 = mystringcheck;
 mystringcheck = mystring2;
 std::cout<<mystring2<<std::endl;


  mystringout+=mystring;
  mystringout+=mystring2;
  mystringout2=mystring+mystring2;
  std::cout<<mystringout<<std::endl;
  std::cout<<mystringout2<<std::endl;
  if(mystring == mystringcheck){
    std::cout<<"true"<<std::endl;
  }
  else
    std::cout<<"false"<<std::endl;







  return 0;
}
