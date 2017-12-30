#include "sequence.h"

using namespace std;

int main (void){

coen70::sequence test,test2,test3;
test.insert(5);
test.insert(7);
test2.insert(6);
test2+=test;
test3 = test2+test;
test2+=test;
cout<<test3[0]<<endl;
cout<<test3[1]<<endl;
cout<<test3[2]<<":"<<endl;
/*
cout<<test2[0]<<endl;
cout<<test2[1]<<endl;
cout<<test2[2]<<endl;
*/
test3.remove_front();
test2.remove_front();
//cout<<test3[0]<<endl;
//cout<<test3[1]<<endl;
test3.insert_front(9);
test2.insert_front(9);
cout<<test3[0]<<endl;
cout<<test3[1]<<endl;
cout<<test3[2]<<endl;
cout<<"2:"<<test2[0]<<endl;
cout<<"2:"<<test2[1]<<endl;
cout<<"2:"<<test2[2]<<endl;
test3.attach_back(2);
test2.attach_back(2);
cout<<test3[0]<<endl;
cout<<test3[1]<<endl;
cout<<test3[2]<<endl;
cout<<test3[3]<<endl;
cout<<"2:"<<test2[0]<<endl;
cout<<"2:"<<test2[1]<<endl;
cout<<"2:"<<test2[2]<<endl;
cout<<"2:"<<test2[3]<<endl;
test3.end();
test2.end();
cout<<test3.current()<<endl;
cout<<"2:"<<test2.current()<<endl;
}
