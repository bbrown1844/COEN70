#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <cstdlib>
#include <iostream>
#include <assert.h>

namespace coen70{

    class sequence{
    public:
          typedef double value_type;
          typedef int size_type;
          static const size_type CAPACITY = 30;

          //CONSTRUCTOR
          sequence();
          // Postcondition: The sequence has been initialized as an empty sequence.

          //MODIFICATION MEMBER FUNCTIONS
          void start();
          // Postcondition: The first item on the sequence becomes the current
          // item(but if the sequence is empty, then there is no current item).\
          // O(1)
          void advance();
          // Postcondition: If the current item was already the last item in the
          // sequence, then there is no longer any current item. Otherwise, the
          // new current item is the item immediately after the original current
          // item.
          // O(1)
          void insert(const value_type& entry);
          // Precondition: size( ) < CAPACITY.
          // Postcondition: A new copy of entry has been inserted in the
          // sequence before the current item. If there was no current item,
          // then the new entry has been inserted at the front of the sequence.
          // In either case, the newly inserted item is now the current item of
          // the sequence.
          // O(n-current_index)
          void attach(const value_type& entry);
          // Precondition: size( ) < CAPACITY.
          // Postcondition: A new copy of entry has been inserted in the
          // sequence after the current item. If there was no current item, then
          // the new entry has been attached to the end of the sequence. In
          // either case, the newly inserted item is now the current item of the
          // sequence.
          // O(n-current_index)
          void remove_current();
          // Precondition: is_item returns true.
          // Postcondition: The current item has been removed from the sequence,
          // and the item after this (if there is one) is now the new current item.
          // O(n-current_index)
          void insert_front(const value_type& entry);
          // Precondition: size() < CAPACITY
          // Postcondition: current_index is now the item inserted at the front
          // O(n)
          void remove_front();
          // Precondition: is_item returns true
          // Postcondition: all items have been shifted up
          // O(n)
          void attach_back(const value_type& entry);
          // Precondition: size() < CAPACITY
          // Postcondition: used is >= 1
          // O(1)
          void end();
          // Precondition: Sequence is not empty
          // Postcondition: current_index is the last element in the sequence
          //O(1)

          //CONSTANT MEMBER FUNCTIONS
          size_type size() const;
          // size_type size( ) const
          // Postcondition: The return value is the number of items in the
          // sequence.
          // O(1)
          bool is_item() const;
          // Postcondition: A true return value indicates that there is a valid
          // "current" item that may be retrieved by activating the current
          // member function (listed below). A false return value indicates that
          // there is no valid current item.
          // O(1)
          value_type current() const;
          // Precondition: is_item( ) returns true.
          // Postcondition: The item returned is the current item in the
          // sequence.
          // O(1)

          //OPERATOR OVERLOADS
          sequence operator+(const sequence& s2);
          // Precondition: Operation must be set equal to another object
          sequence operator+=(const sequence& s2);
          value_type operator[](size_type index) const;
          //Precondition: index cannot be negative

    private:
          value_type data[CAPACITY];
          //sequence::value_type is the data type of the items in the sequence. It may be any of the C++ built-in types (int, char,
          // etc.), or a class with a default constructor, an assignment
          // operator, and a copy constructor.
          size_type used;
          // sequence::size_type is the data type of any variable that keeps
          // track of how many items are in a sequence.
          int current_index;
          // sequence::CAPACITY is the maximum number of items that a sequence
          // can hold.
    };

}
#endif
