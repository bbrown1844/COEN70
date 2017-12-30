#include "keyed_bag.h"
using namespace coen70_lab;

// MODIFICATION MEMBER FUNCTIONS
bool keyed_bag::erase(const key_type& key){
  for(int i=0;i<used;i++){
    if(strcmp(keys[i],key)){
      for(int j=i;j<used;j++){
        strcpy(keys[i],keys[i+1]);
        data[i] = data[i+1];
      }
      used--;
      return true;
    }
    else{
      return false;
    }
  }
}
void keyed_bag::insert(const value_type& entry, const key_type& key){
  assert(this->size() < CAPACITY);
  if(this->has_key(key)){
    std::cout<<"Duplicate key!"<<std::endl;
    return;
  }
  else{
    strcpy(keys[used],key);
    data[used]=entry;
    used++;
  }
  return;
}
keyed_bag keyed_bag::operator+=(const keyed_bag& rhs){
  assert(size()+rhs.size()<CAPACITY);
  for(int i=0,j=used;i<rhs.size();i++,j++){
    data[j] = rhs.data[i];
    strcpy(keys[j],rhs.keys[i]);
  }
  used+=rhs.size();
  return *this;
}
// CONSTANT MEMBER FUNCTIONS
bool keyed_bag::has_key(const key_type& key) const{
  for(int i=0;i<used;i++){
    if(strcmp(keys[i],key))
      return true;
    else
      return false;
  }
}
value_type keyed_bag::get(const key_type& key) const{
  assert(this->has_key() == true);
  for(int i=0;i<used;i++){
    if(strcmp(keys[i],key)
      return data[i];
  }
}
bool keyed_bag::hasDuplicateKey(const keyed_bag& otherBag) const{
  assert(otherBag.size()>0);
  for(int i=0;i<used;i++){
    for(int j=0;j<otherBag.size();j++){
      if(strcmp(keys[i],otherBag.keys[j]))
        return true;
    }
    return false;
  }
}
size_type keyed_bag::count(const value_type& target) const{
  std::size_type count = 0;
  for(int i=0;i<used;i++){
    if(data[i]==target)
      count++
  }
  return count;
}
// NONMEMBER FUNCTIONS for the keyed_bag class
keyed_bag operator+(const keyed_bag& lhs,const keyed_bag& rhs){
  keyed_bag s3;
  for(int i=0;i<lhs.size();i++){
    s3.data[i]=lhs.data[i];
    strcpy(s3.keys[i],lhs.keys[i]);
    s3.data[i+lhs.size()] = rhs.data[i];
    strcpy(s3.keys[i+rhs.size()],rhs.keys[i]);
  }
  s3.used = lhs.size()+rhs.size();
  return s3;
}
