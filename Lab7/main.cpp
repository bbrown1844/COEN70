#include "node.h"
#include "sequence.h"
#include <iostream>

using namespace coen70_lab7;

int main(){
  sequence s1;
  sequence s2;


  s1.insert(5);
  s1.attach(1);
  s1.insert(7);
  s1.insert(8);
  s1.attach(3);
  s1.start();
  std::cout<<s1.current()<<std::endl;
  s1.advance();
  std::cout<<s1.current()<<std::endl;
  s1.advance();
  std::cout<<s1.current()<<std::endl;
  s1.advance();
  std::cout<<s1.current()<<std::endl;
  std::cout<<"size1:"<<s1.size()<<std::endl;


  s2 = s1;

  s2.start();
  std::cout<<s2.current()<<std::endl;
  s2.advance();
  std::cout<<s2.current()<<std::endl;
  s2.advance();
  std::cout<<s2.current()<<std::endl;
  s2.advance();
  std::cout<<s2.current()<<std::endl;
  std::cout<<"size2:"<<s2.size()<<std::endl;



  sequence s3(s2);

  s3.start();
  std::cout<<"s3:"<<s3.current()<<std::endl;
  s3.advance();
  std::cout<<"s3:"<<s3.current()<<std::endl;
  s3.advance();
  std::cout<<"s3:"<<s3.current()<<std::endl;
  s3.advance();
  std::cout<<s3.current()<<std::endl;
  std::cout<<"s3 size:"<<s3.size()<<std::endl;

  s3.start();
  s3.remove_current();
  std::cout<<"s3:"<<s3.current()<<std::endl;
  std::cout<<"s3:"<<s3.size()<<std::endl;
  s3.advance();

  sequence s4;




  node * head_ptr;
  const node * head_ptrcon = head_ptr;
  node::value_type value = 0;
  list_head_insert(head_ptr,value);
  node * p = head_ptr;
  node::value_type i = 0;
  while(i<5){
    list_insert(p,i+1);
    std::cout<<p->data()<<std::endl;
    p = p->link();
    i++;
  }
  p = head_ptr;

  for (int j = 0; j<3; j++){
    p = p->link();
  }

  node * head_ptr1;
  node * head_ptr2;
  node * tail_ptr1;

  list_piece(head_ptr,p,head_ptr1,tail_ptr1);
  p = head_ptr1;
  list_insert_at(p,5,2);
  list_remove_at(p,2);
  while(p!= NULL){
    std::cout<<"data:"<<p->data()<<std::endl;
    p = p->link();
  }
  head_ptr2 = list_copy_segment(head_ptr,1,4);
  while(head_ptr2!= NULL){
    std::cout<<"data1:"<<head_ptr2->data()<<std::endl;
    head_ptr2 = head_ptr2->link();
  }












return 0;
}
