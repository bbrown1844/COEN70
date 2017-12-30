#include "poly.h"

using namespace std;

int main(){

coen70_lab::polynomial test(4,2),test2(5,0),test3(9,1),test4;
cout<<"test: "<<test<<endl;
test.add_to_coef(5,4);
cout<<"test: "<<test<<endl;
test.assign_coef(5,3);
test.assign_coef(9,5);
test.assign_coef(12,0);
cout<<"test: "<<test<<endl;
cout<<"test: "<<test<<endl;

cout<<"test2: "<<test2<<endl;
cout<<"test2 degree: "<<test2.degree()<<endl;
test2.assign_coef(5,4);
test2.assign_coef(2,3);
test2.add_to_coef(5,4);
test2.add_to_coef(8,2);
test2.add_to_coef(3,1);
test2.add_to_coef(7,0);
test3.assign_coef(5,3);
test3.assign_coef(8,0);
cout<<"test2: "<<test2<<endl;
cout<<"test2 degree: "<<test2.degree()<<endl;
cout<<"test3: "<<test3<<endl;
cout<<"test3 degree: "<<test3.degree()<<endl;
cout<<"test2: "<<test2<<endl;
cout<<"test: "<<test<<endl;
cout<<"test degree: "<<test.degree()<<endl;


cout<<"test2 antiderivative:"<<test2.antiderivative()<<endl;
cout<<"test2 antiderivative eval"<<test2.antiderivative().eval(2)<<endl;
cout<<"test2 degree:"<<test2.degree()<<endl;
cout<<"test2 derivative:"<<test2.derivative()<<endl;
cout<<"test2 derivative eval:"<<test2.derivative().eval(2)<<endl;
cout<<"test2 derivative coef:"<<test2.coefficient(4)<<endl;
cout<<"test2 derivative next_term:"<<test2.next_term(3)<<endl;
cout<<test2.degree()<<endl;
cout<<test2.definite_integral(0,5)<<endl;
cout<<"test2 eval: "<<test2<<endl;
cout<<test2.eval(2)<<endl;
cout<<test2.previous_term(4)<<endl;
cout<<test2(2)<<endl;
test4 = test2*test3;
cout<<test4<<endl;




return 0;
}
