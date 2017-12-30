#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <climits>
#include "poly.h"


using namespace std;

namespace coen70_lab
{
    	// CONSTANTS
    //const unsigned int polynomial::MAXIMUM_DEGREE;

    // HELPER FUNCTIONS
    void polynomial::update_current_degree() {
        current_degree = 0;

        for (int i = coef_size; i > 0; i--){     //loops backwords through the array checking for the highest exponent
            if (coef[i] != 0.0)
            {
                current_degree = i;
                break;
            }
        }
    }

    void polynomial::reallocateForExponent(unsigned int exponent){
        if(exponent>=coef_size){       //otherwise no need to allocate
          double * temp = coef;        //temp points to where coef points
          coef_size = exponent+1;
          coef = new double[coef_size]();  //create new array and initialize all values as 0's
          assert(coef!=NULL);
          if(temp!=NULL){
              for(int i=0;i<=current_degree;i++){    //copy over the values from temp
                  coef[i]=temp[i];
              }
          }
          delete []temp;      //delete temp
          current_degree=exponent; //update current_degree to the exponent that was inputted
        }
        return;
    }

    // CONSTRUCTOR
	polynomial::polynomial(double c, unsigned int exponent){
        coef_size = 0;                      //sets everything to zero or null
        current_degree = 0;
        coef = NULL;
        reallocateForExponent(exponent);    //reallocates for the value entered
        coef[exponent] = c;                 //sets the coefficient at the new exponent
    }
    //COPY CONSTRUCTOR
  polynomial::polynomial(const polynomial& other){
      coef_size = other.coef_size;           //set all the private member variables equal to each other
      coef = new double[coef_size]();        //create a new array
      if(coef!=NULL){
          for(int i=0;i<coef_size;i++){      //copy over values
              coef[i]=other.coef[i];
          }
      }
      current_degree = other.current_degree;        //update current_degree
  }

  polynomial::~polynomial(){
    delete []coef;
  }

	// MODIFICATION MEMBER FUNCTIONS
	void polynomial::assign_coef(double coefficient, unsigned int exponent) {

        if(exponent>=coef_size){
          reallocateForExponent(exponent);      //reallocates if the exponent is bigger than the current array can hold
        }

        coef[exponent] = coefficient;          //update coefficient and current_degree
        update_current_degree();
    }

    void polynomial::add_to_coef(double amount, unsigned int exponent){
        if(exponent>=coef_size){                  //if the exponenent is bigger than the current capacity of the array then reallocate
          reallocateForExponent(exponent);        //and call assign_coef and just enter in amount
          assign_coef(amount, exponent);
        }
        // Access, add, and assign.
        else{
          assign_coef(coefficient(exponent) + amount, exponent);    //otherwise add the coefficient alreay at the exponent value
        }
    }

	void polynomial::clear( ) {
        // Zero out all the coeficients.
        for (size_t i = 0; i < coef_size; i++) {      //sets all the values in array to 0.0
            coef[i] = 0.0;
        }

        current_degree = 0;
    }

   polynomial& polynomial::operator=(const polynomial& other){
     coef_size = other.coef_size;
     coef = new double[coef_size]();          //create a new array and copy the values over from other.coef
     if(coef!=NULL){
         for(int i=0;i<coef_size;i++){
             coef[i]=other.coef[i];
         }
     }
     current_degree = other.current_degree;

     return *this;                           //return the object
   }


	// // CONSTANT MEMBER FUNCTIONS
    polynomial polynomial::antiderivative( ) const {
        //if(this->degree() == coef_size-1){
            polynomial p(0.0,coef_size);    //creates new object

        // Calculate anti-derivative.
        for (size_t i = 1; i <= this->degree()+1; i++) {        //loops through and calculates anti-derivative
            p.assign_coef(this->coefficient(i-1) / i , i);
        }

        return p;
    }

	double polynomial::coefficient(unsigned int exponent) const {
        if (exponent > coef_size-1)
            return 0.0;

        return coef[exponent];    //returns coefficient at index exponent
    }

    double polynomial::definite_integral(double x0, double x1) const {
        polynomial anti = this->antiderivative();

        return anti.eval(x1) - anti.eval(x0);
    }

	polynomial polynomial::derivative( ) const {
        polynomial p;                              //same implementation as static bag class

        // Calculate derivative.
        for (size_t i = 0; i < this->degree(); i++) {
            p.assign_coef( this->coefficient(i+1) * (i+1) , i);
        }

        return p;
    }

	double polynomial::eval(double x) const {
        double sum = 0;
        // Evaluation loop.
        for (size_t i = 0; i <= current_degree; i++) {
            double cur_coef = coefficient(i);
            if (cur_coef != 0) {
                sum += cur_coef * pow(x, i);
            }
        }

        return sum;
    }

    bool polynomial::is_zero( ) const {
        if (current_degree == 0 && coef[0] == 0.0)           //checks to see if the polynomial is the zero polynomial
            return true;
        else
            return false;
    }

	unsigned int polynomial::next_term(unsigned int e) const {
        // Search for next term.
        for (size_t i = e+1; i <= current_degree; i++) {
            if (coef[i] != 0)
                return i;
        }
        return 0;
    }

    // Search for previous term.
	unsigned int polynomial::previous_term(unsigned int e) const {
        for (int i = e-1; i >= 0; i--) {
            if (coef[i] != 0)
                return i;
        }
        return UINT_MAX;
    }

    // // NON-MEMBER BINARY OPERATORS
    polynomial operator +(const polynomial& p1, const polynomial& p2)  //same implementation as static bag class
    {
        polynomial p3 = p1;
        for (size_t i = 0; i <= p2.degree(); i++) {
            p3.add_to_coef(p2.coefficient(i), i);
        }

        return p3;
    }

    polynomial operator -(const polynomial& p1, const polynomial& p2) {
        polynomial p3 = p1;
        for (size_t i = 0; i <= p2.degree(); i++) {
            p3.add_to_coef(-p2.coefficient(i), i);
        }

        return p3;
    }

    polynomial operator *(const polynomial& p1, const polynomial& p2) {
        //assert(p1.degree( ) + p2.degree( ) <= polynomial::MAXIMUM_DEGREE);
          polynomial p3(0.0, p1.degree( ) + p2.degree( ));           //creates a new polynomial with a max size of the highest exponents of te two different polynomials

          for (size_t i = 0; i <= p1.degree(); i++) {
              for (size_t j = 0; j <= p2.degree(); j++) {
                  p3.add_to_coef(p1.coefficient(i) * p2.coefficient(j), i+j);
              }
          }


        return p3;
    }

    // NON-MEMBER OUTPUT FUNCTIONS
    std::ostream& operator << (std::ostream& out, const polynomial& p)
    {
        // Save output settings.
        long savedFlags = out.ios::flags();
        int pres = out.precision();
        out << std::fixed;
        out << std::setprecision(1);

        if (p.is_zero())
            out << 0.00;
        else
        {
            bool firstPrint = true;
            //  Loop through array.
            for (int i = p.degree(); i >= 0; i--) {
                double theCoef = p.coefficient(i);
                if (theCoef != 0) {
                    // Don't print a plus for first coefficient.
                    if (!firstPrint) {
                        out << ((theCoef < 0) ? " - " : " + ");
                    }

                    out << ((firstPrint) ? theCoef : abs(theCoef));

                    if (i > 0)
                    {
                        out << "x";

                        if (i > 1)
                            out << "^" << i;
                    }

                    if (firstPrint)
                        firstPrint = false;
                }
            }
        }

        // Restore output settings.
        out << setprecision(pres);
        out.flags(savedFlags);
        return out;
    }
}
