#include "poly.h"

using namespace std;

int main(){

coen70_lab::polynomial test(4,2),test2(5,0),test3(9,1),test4;
cout<<"test: "<<test<<endl;
cout<<"test2: "<<test2<<endl;
test3.assign_coef(5,3);


test2.add_to_coef(5,6);
cout<<"test2: "<<test2<<endl;
cout<<"test3: "<<test2<<endl;



cout<<"anti: "<<test2.antiderivative()<<endl;
cout<<"anti eval: "<<test2.antiderivative().eval(2)<<endl;
cout<<"degree: "<<test2.degree()<<endl;
cout<<"der: "<<test2.derivative()<<endl;
cout<<"der eval: "<<test2.derivative().eval(2)<<endl;
cout<<"coef 4: "<<test2.coefficient(9)<<endl;
cout<<"nextterm(3): "<<test2.next_term(3)<<endl;
cout<<"degree: "<<test2.degree()<<endl;
cout<<"def integral: "<<test2.definite_integral(0,5)<<endl;
cout<<"eval: "<<test2.eval(2)<<endl;
cout<<"prev: "<<test2.previous_term(4)<<endl;
cout<<"test2(2): "<<test2(2)<<endl;
cout<<"test3: "<<test3<<endl;
test4 = test2-test3;
test4 = test2+test3;
test4 = test2*test3;
cout<<"test4: "<<test4<<endl;




return 0;
}
