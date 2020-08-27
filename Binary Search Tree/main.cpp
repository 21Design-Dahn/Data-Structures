#include <iostream>
#include "BinarySearchTree.h"
#define LOG(x) std:: cout << x << std::endl

int main(){
  BinarySearchTree<int> bst;
  bst.Insert(5);
  bst.Insert(3);
  bst.Insert(1);
  bst.Insert(0);
  bst.Insert(2);
  bst.Insert(6);
  bst.Insert(8);
  bst.Insert(7);
  bst.Insert(10);
  bst.Insert(9);
  bst.Insert(11);

  //bst.Remove(3);

  bst.Postorder();
  
  bool result = bst.Search(0);
  //LOG(result);
  std::cin.get();
}