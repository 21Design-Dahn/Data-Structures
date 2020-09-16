#include <iostream>
#include "AvlTree.h"

int main(){
  AVLTree<unsigned int> tree;
  tree.Insert(5);
  tree.Insert(6);
  tree.Insert(3);
  tree.Insert(2);
  tree.Insert(1);

  std:: cin.get();
}