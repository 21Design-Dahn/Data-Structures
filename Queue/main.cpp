// https://www.techiedelight.com/queue-implementation-cpp/
// Enqueue
// Peeking
// Contains
// Removal
// IsEmpty
#include <iostream>
#include "Queue.h"

int main(){
  Queue<int> queue;
  queue.Enqueue(3);
  queue.Enqueue(4);
  queue.Enqueue(5);

  queue.Peek();
  queue.Dequeue();
  queue.Dequeue();

  queue.Enqueue(6);
  queue.Enqueue(7);

  queue.Remove(1);
  queue.Enqueue(8);
  queue.Search(6);

  queue.Display();
  std::cin.get();
}