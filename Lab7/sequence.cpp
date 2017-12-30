#include "sequence.h"
#include <cassert>
#include <iostream>

namespace coen70_lab7{

// CONSTRUCTORS and DESTRUCTOR
sequence::sequence( ){
  head_ptr = NULL;
  tail_ptr = NULL;
  cursor = NULL;
  precursor = NULL;
  many_nodes = 0;
}
sequence::sequence(const sequence& source){
  list_copy(source.head_ptr,head_ptr,tail_ptr);
  cursor = head_ptr;
  many_nodes = source.many_nodes;
}

sequence::~sequence( ){
  list_clear(head_ptr);
}

// MODIFICATION MEMBER FUNCTIONS
void sequence::start( ){
  if(head_ptr == NULL){
    return;
  }
  cursor = head_ptr;
  precursor = NULL;
}

void sequence::end(){
  cursor = tail_ptr;
  node * next;
  next = head_ptr;
  while(next->link()!=tail_ptr){
    next = next->link();
  }
  precursor = next;
}

void sequence::advance( ){
  assert(is_item());
  precursor = cursor;
  cursor = cursor->link();
}

void sequence::insert(const value_type& entry){
  if (precursor == NULL){
    list_head_insert(head_ptr,entry);
    cursor = head_ptr;
    precursor = NULL;
  }
  else{
    list_insert(precursor,entry);
    cursor = precursor->link();
  }
    many_nodes++;
}

void sequence::attach(const value_type& entry){
  if (head_ptr == NULL){
    list_head_insert(head_ptr,entry);
    cursor = head_ptr;
    precursor = NULL;
  }
  else{
    list_insert(cursor,entry);
    precursor = cursor;
    cursor = cursor->link();
  }
    many_nodes++;
}

void sequence::operator =(const sequence& source){
  list_copy(source.head_ptr,head_ptr,tail_ptr);
  cursor = head_ptr;
  many_nodes = source.many_nodes;
}

void sequence::remove_current( ){
  assert(is_item());
  if(precursor == NULL){
    cursor = cursor->link();
    list_head_remove(head_ptr);
  }
  else{
    cursor = cursor->link();
    list_remove(precursor);
  }
  --many_nodes;
}

// CONSTANT MEMBER FUNCTIONS
sequence::size_type sequence::size( ) const{
  return many_nodes;
}

bool sequence::is_item( ) const{
  if(cursor == NULL)
    return false;
  return true;
}

sequence::value_type sequence::current( ) const{
  assert(is_item());
  return cursor->data();
}

}
