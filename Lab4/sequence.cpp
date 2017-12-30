#include "sequence.h"
using namespace coen70;

//CONSTRUCTOR
sequence::sequence(){
    used = 0;
    current_index = -1;
}

//MODIFICATION MEMBER FUNCTIONS
void sequence::start(){
    current_index = 0;
}

void sequence::advance(){
    if(this->is_item()){       //checks to see if there is a valid item to advance to
      current_index++;
    }
    else{
      current_index = -1;      //else the current_index is -1 indicating invalid value
    }
}

void sequence::insert(const value_type& entry){
    assert(this->size() < CAPACITY);

    if(current_index!=-1){                             //indicating an item is in the list
      for(int i = used-1; i>=current_index; i--){      //starts at the last element and moves up
        data[i+1] = data[i];
      }
      data[current_index] = entry;    //insert the element given to the function
    }
    else{
      current_index = 0;            //no item is in the list
      data[0] = entry;
    }
    used++;
}

void sequence::attach(const value_type& entry){
  assert(this->size() < CAPACITY);

  if(current_index!=-1){                            //indicating an item is in the list
    for(int i = used-1;i>=current_index+1; i--){
      data[i+1] = data[i];
    }
    data[current_index+1] = entry;
  }
  else{                               //no item in the list
    current_index = 0;
    data[0] = entry;
  }
  used++;
}

void sequence::remove_current(){                 //shifts all elements up
  if(this->is_item()){
    for(int i = current_index; i < used-1; i++){
      data[i] = data[i+1];
    }
    used--;
  }
}

void sequence::insert_front(const value_type& entry){
  assert(this->size() < CAPACITY);
  for(int i = used-1;i>=0;i--){               //works backwards from end of the list
    data[i+1] = data[i];                      //shifts everything down
  }
  data[0] = entry;
  current_index = 0;
  used++;
}

void sequence::remove_front(){             //shifts everything down
  if(this->is_item()){
    for(int i = 0; i < used-1; i++){
      data[i] = data[i+1];
    }
    used--;
    current_index = 0;
  }
}

void sequence::attach_back(const value_type& entry){
  assert(this->size() < CAPACITY);
  data[used]=entry;                      //used is first unused value
  used++;
}

void sequence::end(){
    current_index = used-1;
}

//CONSTANT MEMBER FUNCTIONS
sequence::size_type sequence::size() const{
    return used;
}

bool sequence::is_item() const{
    if(used >0 && current_index<used && current_index!= -1)  //checks the list isn't empty and current index < used and
      return true;                                           //current index doesn't equal -1
    else{
      return false;
    }
}

sequence::value_type sequence::current() const{
    assert(this->is_item());
    return data[current_index];                 //returns current index
}

//OPERATOR OVERLOADS

sequence sequence::operator+(const sequence& s2){
  assert(size()+s2.size() <= CAPACITY);

  sequence s3;
  for (int i = 0;i<used;i++){
    s3.data[i] = data[i];
  }
  for (int j = used, k = 0;k<(s2.used);j++,k++){
    s3.data[j] = s2.data[k];
  }
  s3.used = used+s2.used;
  s3.current_index = 0;
  return s3;
}

sequence sequence::operator+=(const sequence& s2){
  assert(size()+s2.size() <= CAPACITY);

  for (int i = 0,j = used;i<(s2.used); i++,j++){
    data[j] = s2.data[i];
  }
  used+=s2.used;
  return *this;
}

sequence::value_type sequence::operator[](size_type index) const{
  assert(index<used);
  return data[index];
}
