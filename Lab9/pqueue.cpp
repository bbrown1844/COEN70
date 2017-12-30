//FILE: pqueue.cpp
//CLASS IMPLEMENTED: pqueue.cpp (see pqueue.cpp for documentation)
//INVARIANT for the PriorityQueue class:
//  1. The number of items in the queue is stored in the member varible count.
//  2. The items in the queue are stored in a linked list, with the front of the
//     queue stored at the head node, and the rear of the queue stored at the final node,
//     organized by priority from highest to lowest. 
//  3. The member variable front_ptr is the head pointer of the linked list of items.
//

#include <iostream>
#include <algorithm>//Provides copy function
#include <cassert>//For assert function
#include <fstream>//For files
#include "pqueue.h"


namespace coen70_lab9{

  //CONSTRUCTOR
  PriorityQueue::PriorityQueue(){
    head_ptr = NULL;
    many_nodes = 0;
  }

  //COPY CONSTRUCTOR
  PriorityQueue::PriorityQueue(const PriorityQueue& source){
    if(source.many_nodes == 0){
      head_ptr = NULL;
      many_nodes = 0;
      return;
    }
    //copy data
    node* temp = source.head_ptr->link();
    head_ptr = new node(source.head_ptr->data(),source.head_ptr->priority()); //creates a head node where head_ptr points to
    node *tp = head_ptr;
    while(temp!=NULL){   //goes through queue and copies over data
      node* current = new node(temp->data(),temp->priority());
      tp->set_link(current);
      temp = temp->link();
      tp = tp->link();
    }
    many_nodes = source.many_nodes;  //copies number of nodes
  }

  //DESTRUCTOR
  PriorityQueue::~PriorityQueue(){ //Reallocates the nodes in the pqueue back to the heap
    node* temp;
    while (head_ptr!=NULL){
      temp = head_ptr;
      head_ptr = head_ptr->link();
      delete temp;
    }
  }

  void PriorityQueue::operator=(const PriorityQueue& source){
    //checks for self assignment
    if(this == &source){
      return;
    }

    //clear the current pqueue
    node* temp;
    while (head_ptr!=NULL){
      temp = head_ptr;
      head_ptr = head_ptr->link();
      delete temp;
    }

    // if source is empty
    if(source.head_ptr == NULL){
      head_ptr = NULL;
      many_nodes = 0;
      return;
    }

    //copy data
    temp = source.head_ptr->link();
    head_ptr = new node(source.head_ptr->data(),source.head_ptr->priority());
    node *tp = head_ptr;
    while(temp!=NULL){
      node* current = new node(temp->data(),temp->priority());
      tp->set_link(current);
      temp = temp->link();
      tp = tp->link();
    }

    many_nodes = source.many_nodes;

  }


  // MODIFICATION MEMBER FUNCTIONS for the PriorityQueue class:
  void PriorityQueue::insert(const Item& entry, unsigned int priority){
    many_nodes++;
    node* insert = new node(entry,priority); //create new node with data and priority
    node* temp = head_ptr;  //temporary head pointer

    //handles empty list
    if(head_ptr == NULL){
        head_ptr = insert;
        return;
    }

    //insert at the beggining of the list
    if(priority > temp->priority()){
      insert->set_link(temp);
      head_ptr = insert;
      return;
    }

    //finds where to put the node if the location is not the beggining or end of the queue
    while(temp->link()!=NULL){
      if(priority > temp->link()->priority()){
        insert->set_link(temp->link());
        temp->set_link(insert);
        return;
      }
      temp = temp->link();
    }

    temp->set_link(insert);   //else insert at end
    return;
  }

  PriorityQueue::Item PriorityQueue::get_front( ){
    assert(!is_empty());
    node *temp = head_ptr;
    Item p = head_ptr->data();
    head_ptr = head_ptr->link();
    delete temp;
    many_nodes--;
    return p;
  }

  // CONSTANT MEMBER FUNCTIONS for the PriorityQueue class:
  size_t PriorityQueue::size( ) const{
    return many_nodes;
  }

  bool PriorityQueue::is_empty( ) const{
    if(many_nodes == 0)
      return true;
    return false;
  }

}
