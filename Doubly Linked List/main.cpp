#include <iostream>
#include "LinkedList_D.h"
#define LOG(x) std:: cout << x << std::endl

int main(){ 
  LinkedList_D<int> list;
  list.Add(5);
  list.Add(6);
  list.Add(7);
  list.Add(8);

  list.Delete(0);
  list.Insert(1, 3);
  list.Insert(2, 9);

  list.Display();
  bool result = list.Search(3);
  LOG(list.Size());

  std:: cin.get();
}