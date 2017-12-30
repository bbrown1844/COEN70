#include "mystring.h"
#include <iostream>
#include <string.h>
#include <assert.h>

//Invariant:
//1. sequence must always be NULL terminated
//2. allocated must be the maximum length of the string + 1 to accomodate for the NULL character
//3. The current_length must match how many characters are currently in the sequence array

namespace coen70_lab{


        // CONSTRUCTOR, COPY CONSTRUCTOR, and DESTRUCTOR
        string::string(const char str[ ]){
            sequence = new char[strlen(str)+1];    //dynamically creates a new array
            strcpy(sequence,str);                  //copies over data
            current_length = strlen(str);          //copies the current length
            allocated = current_length+1;          //allocated to included the terminating character
        }
        string::string(char c){
            sequence = new char[2];                 //creates a new array 1 size greater and appends the character
            sequence[1]= c;
            sequence[0]= '\0';
            current_length = 1;
            allocated = 2;
        }
        string::string(const string& source){
          current_length = source.current_length;   //copies over private member variables
          allocated = source.allocated;
          sequence = new char[allocated];
          strcpy(sequence,source.sequence);         //copy over the data from the array
        }
        string::~string( ){
          delete [] sequence;
        }

        // MODIFICATION MEMBER FUNCTIONS
        void string::operator +=(const string& addend){
            char *temp;                                           //temp points to sequence array
            temp = sequence;
            sequence = new char[current_length+addend.allocated];         //sequence gets allocated a bigger array
            strcpy(sequence,temp);
            strncat(sequence,addend.sequence,addend.current_length);     //add addend onto the end
            current_length+= addend.current_length;
            allocated+= addend.current_length;
            delete []temp;                                              //Delete temp pointer
        }

        void string::operator +=(const char addend[ ]){
          char *temp;                                             //same as above but uses a char array
          temp = sequence;
          sequence = new char[current_length+strlen(addend)+1];
          strcpy(sequence,temp);
          strncat(sequence,addend,strlen(addend));
          current_length+= strlen(addend);
          allocated+= (strlen(addend)+1);
          delete []temp;
        }

        void string::operator +=(char addend){
          char *temp;
          temp = sequence;
          sequence = new char[allocated+1];             //creates array 1 size bigger
          strcpy(sequence,temp);                        //copies data and adds the character
          sequence[allocated] = addend;
          current_length+=1;
          allocated+=1;
          delete []temp;
        }

        void string::reserve(size_t n){
          if(allocated == n){                                  //no need to reallocate
            return;
          }
          else if(n>current_length){
            char *temp;
            temp = sequence;
            sequence = new char[n];                           //new array size for sequence
            strcpy(sequence,temp);                            //copy data and delete temp
            delete []temp;
          }
          else{                                        //creates a smaller dynamic array and only copies over n value from sequence
            char *temp;
            temp = sequence;
            sequence = new char[n];
            strncpy(sequence,temp,n);
            delete []temp;
          }
        }

        string& string::operator =(const string& source){

            if (&source == this)       //checks to see if the objects are the same
            {
              return *this;
            }
            current_length = source.length();
            reserve(current_length+1);                      //create a new array
            std::cout<<source.current_length<<std::endl;
            strncpy(sequence, source.sequence, source.current_length);  //copy over values
            sequence[source.current_length] = '\0';
            return *this;                                   //return the object

        }
        void string::insert(const string& source, unsigned int position){
              assert(position <= current_length);

             reserve(source.length() + current_length);       //creates a an array with a size that can accomodate the inserted string
             current_length += source.length();               //update current length

             //makes a copy of the current string
             string temp = *this;

             for(int i = 0; i < source.length(); ++i)
                 sequence[i + position] = source[i];       //inserts source into the new array and overwrites current data

             for(int i = position; i < temp.length(); ++i)
                 sequence[i + source.length()] = temp[i];   //at the end of sequence add the missing part from sequence

             sequence[current_length] = '\0';        //add null character

        }
        void string::dlt(unsigned int position, unsigned int num){
          assert(position + num <= current_length);

		      for(int i = 0; i < current_length; ++i)
			       sequence[position + i] = sequence[position + num + i];   //writes over sequence starting at position and assigns the values from the position plus num plus
                                                                      //until i is the last index
		      sequence[current_length] = '\0';

          current_length -= num;          //update current_length
        }

        void string::replace(char c, unsigned int position){
          assert(position <= current_length);
          sequence[position] = c;         //writes over data in array
        }

        void string::replace(const string& source, unsigned int position){
          assert(position + source.length() <= current_length);

          char *temp = sequence;
          for(int i = 0; i < position; ++i)
            ++temp;

          strncpy(temp, source.sequence, source.length());  //writes over array and copies in values to temp which points to sequence
        }
        // CONSTANT MEMBER FUNCTIONS
        //size_t length( ) const { return current_length; }

        char string::operator [ ](size_t position) const{
              assert(position < length());
              return sequence[position];
        }

        int string::search(char c) const{
          int i = 0;
          while(sequence[i]!='\0'){                //looks for
            if(sequence[i]== c){
              return i;
            }
            i++;
          }
          return -1;
        }

        int string::search(const string& substring) const{
          //function counts the length of the substring. If it finds the first character of the substring in the string it
          //compares everyother character afterwords to substring until count is equal to the length of the substring
          //indicating the substring is in the string
          int count = 1;
          int i = 0;
          while(sequence[i]!='\0'){
            if(sequence[i]==substring.sequence[0]){
              for(int j=i,k=0;j<strlen(sequence)&&k<strlen(substring.sequence);j++,k++){
                if(count == strlen(substring.sequence))
                  return i;
                else if(sequence[j]!=substring.sequence[k]){
                  break;
                }
                else{
                  count++;
                }
              }
            }
            i++;
          }
          return -1;
        }

        unsigned int string::count(char c) const{
            unsigned int count = 0;
            int i = 0;
            while(sequence[i]!='\0'){
              if(sequence[i]==c){            //if the value in array is equal to the character count increments
                count++;
              }
              i++;
            }
            return count;
        }

        // FRIEND FUNCTIONS
        std::ostream& operator <<(std::ostream& outs, const string& source){
            return outs << source.sequence;
        }
        bool operator ==(const string& s1, const string& s2){
            if(strcmp(s1.sequence, s2.sequence) == 0){                //compares the strins using strcmp
              return true;
            }
            else{
              return false;
            }
        }
        bool operator !=(const string& s1, const string& s2){
          return !(s1 == s2);    //if the strings are equal return false and of there not return true
        }
        bool operator > (const string& s1, const string& s2){
          if(strcmp(s1.sequence, s2.sequence) > 0){             //uses strcmp
            return true;
          }
          else{
            return false;
          }
        }
        bool operator < (const string& s1, const string& s2){
          if(strcmp(s1.sequence, s2.sequence) < 0){            //uses strcmp
            return true;
          }
          else{
            return false;
          }
        }
        bool operator >=(const string& s1, const string& s2){
          return (s1 > s2 || s1 == s2);          //if one is true the argument evaluates to true
        }
        bool operator <=(const string& s1, const string& s2){
          return (s1 < s2 || s1 == s2);
        }

        //NON-MEMBER FUNCTIONS

        string operator +(const string& s1, const string& s2){
		        string temp;

		        temp+=s1;     //copies first string to temp
		        temp+=s2;     //copies second string to temp

		        return temp;    //returns temp
        }

        string operator +(const string& s1, const char addend[ ]){
          return s1 + string(addend);
        }

        std::istream& operator >> (std::istream& ins, string& target){
          while (ins && isspace(ins.peek()))
      			ins.ignore();
      		char temp;
      		target = "";
          //read in characters
      		while (ins && !isspace(ins.peek()))
      		{
      			ins >> temp;
      			target += temp;
      		}

      		return ins;

        }

}
