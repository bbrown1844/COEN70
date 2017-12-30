#include "keyed_bag.h"

using namespace std;

int main(){
string key = "key";

coen70_lab::keyed_bag test,test2,test3;
test.insert(5,key);
test.insert(7,"car");
test2.insert(8,"mouse");
cout<<test.get(key)<<endl;
cout<<test.get("car")<<endl;
cout<<test.size()<<endl;
test.erase("car");
cout<<test.size()<<endl;
test+=test2;
cout<<test.size()<<endl;
cout<<test.get("mouse")<<endl;
test3 = test2+test;
cout<<test3.size()<<endl;
cout<<test3.get("mouse")<<endl;
test3.erase("mouse");
test3.insert(9,"mouse");
cout<<test3.size()<<endl;
cout<<test3.get("mouse")<<endl;





return 0;
}
