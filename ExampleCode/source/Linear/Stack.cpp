#include "Stack.hpp"

Stack::Stack()
{
    list = new LinkedList();
}

Stack::~Stack()
{
    delete list;
}

  /** size()
   * Returns the size of the stack
   */
  unsigned int Stack::size()
  {
      return list->length();
  }

  /** push(int data)
   * Pushes a node containing the given data to the top of the stack
   */
  void Stack::push(int data)
  {
      list->push_front(data);
      return;
  }

  /** pop()
   * Removes and returns the data at the top of the stack
   */
  int Stack::pop()
  {
      return list->pop_front();
  }

  /** top()
   * Returns the data at the top of the stack without changing the stack
   */
  int Stack::top()
  {
     return list->at(0);
  }

  /** empty()
   * Returns whether or not the stack is empty
   */
  bool Stack::empty()
  {
      return list->length()==0;
  }

  /** clear()
   * Clears the entire stack
   */
  void Stack::clear()
  {
  return list->clear();
  }
