#include "poly.h"
#include <climits>
#include <assert.h>
#include <cmath>


namespace coen70_lab
{

      // HELPER FUNCTION
      void polynomial::update_current_degree(){
        int degree = 0;
        for(int i = MAXIMUM_DEGREE;i>=0;--i){ //starts at MAXIMUM_DEGREE and goes through entire array
          if(coef[i]!=0){                     //if there is a term before the end of the array then current_degree gets set to that index
            current_degree = i;
            break;
          }
        }
      }

      //CONSTRUCTOR
      polynomial::polynomial(double c, unsigned int exponent){
        assert(exponent<=MAXIMUM_DEGREE);
        clear();    //sets array to zero's
        coef[exponent]=c;  //sets the parameters given
        update_current_degree();  //updates current degree
      }

    	// MODIFICATION MEMBER FUNCTIONS
    	void 	polynomial::assign_coef(double coefficient, unsigned int exponent){
          assert(exponent <= MAXIMUM_DEGREE);
          coef[exponent] = coefficient;  //assigns the coefficient at the index
          update_current_degree();   //updates current_degree
      }
      void 	polynomial::add_to_coef(double amount, unsigned int exponent){
          assert(exponent <= MAXIMUM_DEGREE);
          coef[exponent]+=amount;        //adds the coefficients at the index
          update_current_degree();
      }
    	void 	polynomial::clear( ){
        for(int i=0;i<=polynomial::MAXIMUM_DEGREE;i++){    //loops through and sets everything to zero
          coef[i]= 0;
        }
      }

    	// CONSTANT MEMBER FUNCTIONS
      polynomial 	polynomial::antiderivative( ) const{
          polynomial anti;                                //shifts all the elements over to new array and calculates the correct coefficient
          for(int i = MAXIMUM_DEGREE;i>0;--i){
            if(coef[i]!=0){
              anti.coef[i+1]=(double)(coef[i]/(i+1));
            }
            anti.coef[0]=0;
          }
          anti.update_current_degree();   //updates current_degree for new object
          return anti;
       }
    	double polynomial::coefficient(unsigned int exponent) const{
          if(exponent>MAXIMUM_DEGREE){
            return 0;                //not a valid exponent
          }
          else{
            return coef[exponent];
          }
      }

      double 	polynomial::definite_integral(double x0, double x1) const{
          double definite = antiderivative().eval(x1)-antiderivative().eval(x0);    //def of definite integral
          return definite;
      }

    	polynomial 	polynomial::derivative( ) const{
            polynomial derivative;
            for(int i=0;i<=MAXIMUM_DEGREE;i++){           //shifts the elements one to the right in a new array and calculates coefficient
              if(coef[i]!=0){
              derivative.coef[i-1]=coef[i]*i;
            }
          }
          derivative.update_current_degree();
          return derivative;
        }

    	double 	polynomial::eval(double x) const{
          double value = 0;
          for(int i = polynomial::MAXIMUM_DEGREE;i>=0;i--){
              if(coef[i]!=0)
              value+=(coef[i])*(std::pow(x,i));     //goes through the terms one by one calculates the exponetial value and then sums them
          }
          return value;
      }

      bool 	polynomial::is_zero( ) const{
          if(degree()==0&&coef[0]==0){   //checks to make sure not a constant other than 0
            return true;
          }
          else{
            return false;
          }
      }
    	unsigned int 	polynomial::next_term(unsigned int e) const{     //loops from e to the current degree looking for a valid term
          for(int i = e; i<=degree();i++){
            if(coef[i]!=0){
              return i;
            }
            else
              continue;
          }
          return 0;
      }
    	unsigned int polynomial::previous_term(unsigned int e) const{     //loops from e to the end of the array looking for a valid term
        if(e>0){
          for(int i=e-1;i>=0;i--){
            if(coef[i]!=0)
              return i;
            else
              continue;
          }
         }
          return UINT_MAX;
      }

    // NON-MEMBER BINARY OPERATORS
    polynomial operator +(const polynomial& p1, const polynomial& p2){
        polynomial s3;
        for(int i=0;i<=polynomial::MAXIMUM_DEGREE;i++){
          s3.add_to_coef(p1.coefficient(i),i);
        }
        for(int i=0;i<=polynomial::MAXIMUM_DEGREE;i++){
          s3.add_to_coef(p2.coefficient(i),i);
        }
        return s3;
    }
    polynomial operator -(const polynomial& p1, const polynomial& p2){
        polynomial s3;
        for(int i=0;i<=polynomial::MAXIMUM_DEGREE;i++){
          s3.add_to_coef(p1.coefficient(i)-p2.coefficient(i),i);
        }
        return s3;
    }
    polynomial operator *(const polynomial& p1, const polynomial& p2){

        polynomial s3;
        for(int i=0;i<=polynomial::MAXIMUM_DEGREE;i++){
          for(int j=0;j<=polynomial::MAXIMUM_DEGREE;j++){
            if(p1.coefficient(i)!=0 && p2.coefficient(j)!=0){
              s3.add_to_coef(p1.coefficient(i)*p2.coefficient(j),i+j);
            }
          }
        }
        return s3;
    }

    // NON-MEMBER OUTPUT FUNCTIONS

  std::ostream& operator<<(std::ostream& out, const polynomial& p) {
    // Input:  An ostream and a polynomial.
    // Output: Outputs that polynomial to the ostream, and returns the stream.

int pos = 0;

if (p.is_zero()){
  out<<0.00;
} else {
    if(p.previous_term(p.degree())==UINT_MAX){
      if(p.degree()==0){
        out<<p.coefficient(0);
      }
      else{
        out<<p.coefficient(p.degree())<<"x^"<<(p.degree());
      }
    }
    else{
        for(int i = p.degree();p.previous_term(i)!=UINT_MAX&&i!=1;i--){
          if(p.coefficient(i)!=0){
            out<<p.coefficient(i)<<"x^"<<i<<" + ";
          }
          pos=i;
        }
        if(pos == 2){
          if (p.coefficient(1)!=0&&p.coefficient(0)!=0){
            out<<p.coefficient(1)<<"x + ";
          }
          else if(p.coefficient(1)!=0&p.coefficient(0)==0){
            out<<p.coefficient(1)<<"x";
          }
          if(p.coefficient(0)!=0){
            out<<p.coefficient(0);
          }

        }
        else{
          out<<p.coefficient(pos-1)<<"x^"<<(pos-1);
        }
    }
}
return out;
}


}
