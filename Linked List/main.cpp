//REFERENCE FOR IMPLEMENTATION : https://www.codesdope.com/blog/article/inserting-a-new-node-to-a-linked-list-in-c/

#include <iostream>
#include "LinkedList.h"

template<typename T>
LinkedList<T> Concat( LinkedList<T>& a, LinkedList<T>& b){
  LinkedList<T> temp;
  if(a.GetHead() != nullptr && b.GetHead() != nullptr){
    temp = a;
    size_t sizea = a.Size();
    size_t sizeb = b.Size();
    size_t result = sizea + sizeb;

    temp.SetSize(result);
    temp.GetTail()->next = b.GetHead();
    temp.UniformIndexes();
    return temp;
  } else {
    std::cout << "either first args or second args is size is 0";
    return temp;
  }
}

int main(){
  LinkedList<int> list;
  LinkedList<int> list2;
  list.Add(4);
  list.Add(6);

  list.Insert(1, 5);
  list.Delete(1);
  //list.Print();

  list2.Add(7);
  list2.Add(8);
  //list2.Print();

  auto concat = Concat(list, list2);
  concat.Delete(0);
  concat.Print();

  std::cin.get();
}