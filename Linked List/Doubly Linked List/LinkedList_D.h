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
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template<typename T>
class LinkedList_D{
  public:
    LinkedList_D(){
      head = nullptr;
      size = 0;
    }

    void Add(T value){
      auto newNode = new Node<T>(value);

      if(head == nullptr){
        head = newNode;
        ptr = newNode;
        size = 1;
      } else {
        ptr->next = newNode;
        newNode->prev = ptr;
        ptr = ptr->next;
        size = size + 1;
      }

      newNode = nullptr;
      delete newNode;
    }

    void Delete(unsigned int index){
      auto temp = head;

      if(index > size - 1 || index >= -1){
        std::cout << "cannot delete a not existing index" << std:: endl;
        return;
      }
      
      if(index == size - 1){
        for(int i = 0; i < size - 1; i++){
          temp  = temp->next;
        }

        ptr = temp->prev;
        ptr->next = nullptr;

        size = size - 1;
        temp = nullptr;
        delete temp;
      } else if(index == 0){ 
        auto newHead = temp->next;
        head = newHead;
        head->prev = nullptr;

        size = size - 1;
        newHead = nullptr;
        temp = nullptr;
        delete newHead;
        delete temp;
      } else {
        for(int i = 0; i <= index - 1; i++){
        temp = temp->next;
        }
        auto ptra = temp->prev;
        auto ptrb = temp->next;

        temp = nullptr;
        delete temp;

        ptra->next = ptrb;
        ptrb->prev = ptra;

        size = size - 1;

        ptra = nullptr;
        ptrb = nullptr;
        delete ptra;
        delete ptrb;
      }
    }

    void Insert(unsigned int index, T value){
      auto newNode = new Node<T>(value);
      auto temp = head;

      if(index > size - 1 || index >= -1){
        std:: cout << "cannot insert to a not existing index" << std::endl;
        return;
      }

      if(index == 0){
        temp->prev = newNode;
        newNode->next = temp;
        head = newNode;

        size = size + 1;
        temp = nullptr;
        newNode = nullptr;
        delete temp;
        delete newNode;
      } else if(index == size - 1){
        ptr->next = newNode;
        newNode->prev = ptr;
        ptr = ptr->next;
        size = size + 1;

        temp = nullptr;
        newNode = nullptr;
        delete newNode;
        delete temp;
      } else {
        for(int i = 0; i < index - 1; i++){
          temp = temp->next;
        }

        auto ptrb = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = ptrb;
        ptrb->prev = newNode;

        size = size + 1;
        ptrb = nullptr;
        temp = nullptr;
        newNode = nullptr;
        delete ptrb;
        delete temp;
        delete newNode;
      }
    }

    bool Search(T value){
      auto temp = head;
      while (temp != nullptr){
        if(temp->data == value){
          return true;
          break;
        }
        temp = temp->next;
      }
      return false;
    }

    void Display(){
      auto temp = head;
      while(temp != nullptr){
        std:: cout << temp->data << std:: endl;
        temp = temp->next;
      }

      temp = nullptr;
      delete temp;
    }

    size_t Size(){ return size; }
  private:
    Node<T>* head;
    Node<T>* ptr;
    size_t size;
};