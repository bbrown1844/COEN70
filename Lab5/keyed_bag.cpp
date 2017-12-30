#include "keyed_bag.h"
namespace coen70_lab{

// MODIFICATION MEMBER FUNCTIONS
bool keyed_bag::erase(const key_type& key){
  for(int i=0;i<used;i++){                   //goes through bag from current key and shifts everything up
    if(keys[i] == key){
      for(int j=i;j<used;j++){
        keys[i]=keys[i+1];
        data[i] = data[i+1];
      }
      used--;
      return true;
    }
  }
    return false;
}

void keyed_bag::insert(const value_type& entry, const key_type& key){   //inserts the key and value in parrallel arrays assuming there is not a duplicate key
  assert(this->size() < CAPACITY);
  if(this->has_key(key)){
    cout<<"Duplicate key!"<<endl;
    return;
  }
  else{
    keys[used]=key;
    data[used]=entry;
    used++;
  }
  return;
}

keyed_bag keyed_bag::operator+=(const keyed_bag& rhs){              //adds together the elements of the data and the keys array seperately
  assert(size()+rhs.size()<CAPACITY);
  for(int i=0,j=used;i<rhs.size();i++,j++){
    data[j] = rhs.data[i];
    keys[j] = rhs.keys[i];
  }
  used+=rhs.size();
  return *this;
}
// CONSTANT MEMBER FUNCTIONS
bool keyed_bag::has_key(const key_type& key) const{     //checks to see if key exists or not by looping through array and comparing
  for(int i=0;i<used;i++){
    if(keys[i]==key)
      return true;
  }
      return false;
}
keyed_bag::value_type keyed_bag::get(const key_type& key) const{       //makes aure the key exists loops through array until the key has been found
  assert(this->has_key(key));
  for(int i=0;i<used;i++){
    if(keys[i]==key)
      return data[i];
  }
  return false;
}
bool keyed_bag::hasDuplicateKey(const keyed_bag& otherBag) const{       //checks to sees if two bags have the same key using nested for loops comparing each elemnt with each other
  assert(otherBag.size()>0);
  for(int i=0;i<used;i++){
    for(int j=0;j<otherBag.size();j++){
      if(keys[i]==otherBag.keys[j])
        return true;
    }
  }
  return false;
}
keyed_bag::size_type keyed_bag::count(const value_type& target) const{      //loops through data and if the data equals the target it increments count
  size_type count = 0;
  for(int i=0;i<used;i++){
    if(data[i]==target)
      count++;
  }
  return count;
}
// NONMEMBER FUNCTIONS for the keyed_bag class
keyed_bag operator+(const keyed_bag& lhs,const keyed_bag& rhs){      //uses the += functions to add the two objects arrays to s3
  keyed_bag s3;
    s3+=lhs;
    s3+=rhs;
  return s3;
}

}
