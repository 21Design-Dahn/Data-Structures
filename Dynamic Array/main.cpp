#include <iostream>
#include "DynamicArray.h"
#define LOG(x) std:: cout << x << std::endl

int main(){
  DynamicArray<int> arr;
  arr.PushBack(22);
  arr.PushBack(1);
  arr.PushBack(32);
  arr.PopBack();
  arr.PushBack(12);
  arr.PushBack(42);
  arr.RemoveAt(1);
  arr.PushBack(43);
  arr.PushBack(421);
  arr.PushBack(432);
  arr.PushBack(1241);
  arr.InsertAt(1, 1);
  arr.PopBack();
  arr.InsertAt(1, 6);
  arr.RemoveAt(0);
  arr.InsertAt(1,3);

  LOG(arr.Capacity());
  LOG(arr.Size());
  arr.Display();
  std:: cin.get();
}