#include <iostream>

template<typename T>
class Node{
  public:
    Node(T value)
      : data(value)
    {
      next = nullptr;
      prev = nullptr;
    }
  public:
    Node<T>* next;
    Node<T>* prev;
    T data;
};

template<typename T>
class Queue{
  public:
    Queue(){
      front = nullptr;
      back = nullptr;
    }

    void Enqueue(T value){
      auto newNode = new Node<T>(value);

      if(front == nullptr && back == nullptr){
        front = newNode;
        back = newNode;
        
        size = 1;
        newNode = nullptr;
        delete newNode;
      } else {
        ptr = newNode;
        ptr->next = back;
        back->prev = ptr;
        back = ptr;

        size = size + 1;
        newNode = nullptr;
        delete newNode;
      }
    }

    void Dequeue(){
      if(front == nullptr && back == nullptr){
        std:: cout << "cannot dequeue an empty queue" << std:: endl;
        return;
      }

      auto temp = front;
      front = temp->prev;
      front->next = nullptr;

      size = size - 1;
      temp = nullptr;
      delete temp;
    }

    void Remove(unsigned int index){ 
      if( index > size - 1){
        std:: cout << "cannot remove an index that doesnt exist" << std:: endl;
        return;
      }

      if(index == 0){
        Dequeue();
      } else if(index == size - 1){
        auto temp = back;
        back = temp->next;
        back->prev = nullptr;

        size = size - 1;
        temp = nullptr;
        delete temp;
      } else {
        auto temp = front;
        for(int i = 0; i <= index - 1; i++){
          temp = temp->prev;
        }

        auto ptra = temp->next;
        auto ptrb = temp->prev;

        temp = nullptr;
        delete temp;

        ptra->prev = ptrb;
        ptrb->next = ptra;

        size = size - 1;
        ptra = nullptr;
        ptrb = nullptr;
        delete ptra;
        delete ptrb;
      }
    }

    bool Search(T value){
      auto temp = front;
      while(temp != nullptr){
        if(temp->data == value){
          return true;
          break;
        }
        temp = temp->prev;
      }
      return false;
    }

    void Peek(){
      if(front == nullptr && back == nullptr){
        std:: cout << "cannot peek to an empty queue" << std:: endl;
        return;
      }

      std:: cout << front->data << std:: endl;
    }

    bool IsEmpty(){
      if(size <= 0) {
        return true;
      } else {
        return false;
      }
    }

    void Display(){ 
      auto temp = back;
      while(temp != nullptr){
        std:: cout << temp->data << std:: endl;
        temp = temp->next;
      }
    }
  private:
    Node<T>* front;
    Node<T>* back;
    Node<T>* ptr;
    size_t size;
};