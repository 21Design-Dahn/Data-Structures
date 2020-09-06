#include <iostream>
#include "BinaryHeap.h"

int main(){
  std:: cout << "henlo" << std:: endl;

  BinaryHeap<int> bh;
  bh.Insert(10);
  bh.Insert(9);
  bh.Insert(5);
  bh.Insert(7);
  bh.Insert(8);
  bh.Insert(2);
  bh.Insert(3);
  bh.Insert(6);
  bh.Insert(2);


  bh.Delete(9);

  std:: cin.get();
}