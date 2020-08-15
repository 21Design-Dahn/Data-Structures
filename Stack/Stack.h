#include <iostream>

template<typename T>
class Node{
  public:
    Node(T value)
      :data(value)
    {
      next = nullptr;
    }
  public:
    T data;
    Node<T>* next;
};

template<typename T>
class Stack{
  public:
    Stack(){
      top = nullptr;
      size = 0;
    }

    void Push(T value){ 
      auto newNode = new Node<T>(value);

      if(top == nullptr){
        top = newNode;
        ptr = newNode;

        size = 1;
        newNode = nullptr;
        delete newNode;
      } else {
        ptr = newNode;
        ptr->next = top;
        top = ptr;

        size = size + 1;
        newNode = nullptr;
        delete newNode;
      }
    }

    void Pop(){
      if(top == nullptr){
        std:: cout << "cannot pop a stack that has no data in it" << std:: endl;
        return;
      }

      auto temp = top;
      top = temp->next;
      
      size = size - 1;
      temp = nullptr;
      delete temp;
    }

    void Peek(){ 
      if(top == nullptr){
        std:: cout << "cannot peek to stack that has not data in it" << std:: endl;
        return;
      }

      std:: cout << top->data << std:: endl;
    }

    bool Search(T value){
      if(top == nullptr){
        std:: cout << "cannot search to a empty stack" << std:: endl;
        return false;
      }

      auto temp = top;
      while(temp != nullptr){
        if(temp->data == value){
          return true;
          break;
        }
        temp = temp->next;
      }
      return false;
    }

    void Display() {
      auto temp = top;
      while(temp != nullptr){
        std:: cout << temp->data << std:: endl;
        temp = temp->next;
      }
    }

    size_t Size() { return size; }
  private:
    Node<T>* top;
    Node<T>* ptr;
    size_t size;
};