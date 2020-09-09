#include <iostream>
#include "FenwickTree.h"
#include "FenwickTree_WF.h"

int main(){
  unsigned int array[] = {1, 2, 3, 4};
  FenwickTree<unsigned int> tree(array, 4);
  tree.Print();
  std:: cout << tree.GetSum(0) << std:: endl;

  FenwickTree_WF<unsigned int> tree2(array, 4);
  
  tree2.PrintTree();

  std:: cin.get();
}