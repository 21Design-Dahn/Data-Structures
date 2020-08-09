#include <iostream>

#include "Array.h"

int main(){
  Array<int, 4> array;
  
  for (size_t i = 0; i < array.Size(); i++)
  {
    array[i] = 0;
    std::cout << array[i] << std::endl;
  }
  
  std::cin.get();
}