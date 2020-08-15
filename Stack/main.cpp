//STACK REFERNCE : https://www.tutorialspoint.com/cplusplus-program-to-implement-stack-using-linked-list
//Push - This adds a data value to the top of the stack.
//Pop - This removes the data value on top of the stack.
//Peek - This returns the top data value of the stack.

#include <iostream>
#include "Stack.h"
#define LOG(x) std:: cout << x << std:: endl

int main(){
  Stack<int> stack;
  stack.Push(3);
  stack.Push(4);
  stack.Push(5);
  
  stack.Pop();
  stack.Push(5);
  stack.Push(6);
  stack.Peek();

  bool result = stack.Search(4);
  LOG(result);

  stack.Display();
  std:: cin.get();
}

