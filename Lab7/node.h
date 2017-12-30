//node class
#ifndef COEN_177_NODE_H
#define COEN_177_NODE_H
#include <cstdlib> // Provides size_t and NULL

namespace coen177_lab4
{
  class node 
  {
    public:
      typedef double value_type;

      	// CONSTRUCTOR
    	node(const value_type& init_data = value_type( ), node* init_link = NULL)
    	{
            data_field = init_data;
            link_field = init_link;
      }

      // Member functions to set the data and link fields:
    	void set_data(const value_type& new_data) { data_field = new_data; }
    	void set_link(node* new_link) { link_field = new_link; }

    	// Constant member function to retrieve the current data:
    	value_type data( ) const { return data_field; }

    	// Two slightly different member functions to retreive
    	// the current link:
    	const node* link( ) const { return link_field; }
      node* link( ) { return link_field; }
    
    
    private:
      value_type data_field;
    	node* link_field;
  };

  void list_insert(node* previous_ptr, const node::value_type& entry);
  void list_remove(node* previous_ptr);
}

#endif
