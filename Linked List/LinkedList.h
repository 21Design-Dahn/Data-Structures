#include <iostream>

template<typename T>
class Node {
  public:
    Node* next = nullptr;
    T data;
    unsigned int index;
  public:
    Node(){

    }
    Node(T value)
      : data(value),
        index(0)
    {
      
    }

    void SetIndex(unsigned int i){ index = i; }
    unsigned int GetIndex() { return index; }
};

template<typename T>
class LinkedList{
  public:
    LinkedList(){ 
      head = nullptr;
      tail = nullptr;

      size = 0;
    }
    
    void Add(T value){
      Node<T>* temp = new Node<T>(value);
      temp->next = nullptr;
      
      if(head == nullptr){
        head = temp;
        tail = temp;
        size = 1;
        head->SetIndex(size - 1);
      } else {
        tail->next = temp;
        tail = tail->next;
        size = size + 1;
        head->SetIndex(size - 1);
      }

      temp = nullptr;
      delete temp;
    }

    void AddFront(T value){
      Node<T>* newHead = new Node<T>(value);
      
      if(head != nullptr || tail == nullptr){
        newHead->next = head;
        head = newHead;
        size = size + 1;

        if(tail == nullptr){
          tail = newHead;
        }

        UniformIndexes();
        newHead = nullptr;
        delete newHead;
      } else {
        std:: cout<< "you cant add to the front of the list" << std:: endl;
      }
    }

    void Insert(unsigned int index, T value){
      Node<T>* node = new Node<T>(value);
      auto first = head;
      
      while(first->GetIndex() != index){
        first = first->next;
      }

      auto second = first->next;
      first->next = node;
      node->next = second;
      
      unsigned int newIndex = 0;
      while(first != nullptr){
        first->SetIndex(newIndex);
        newIndex = newIndex + 1;
        first = first->next;
      }

      size = size + 1;

      first = nullptr;
      second = nullptr;
      delete first;
      delete second;
    }

    void Delete(int index){
      if(index == 0){
        auto deleteHead = head;
        head = head->next;

        deleteHead = nullptr;
        delete deleteHead;

        size = size - 1;
        UniformIndexes();
      } else {
        auto a = head;
        a->SetIndex(0);
        while(a->GetIndex() < index - 1){
          a = a->next;
        }

        auto deleteNode = a->next;
        auto b = deleteNode->next;

        deleteNode = nullptr;
        delete deleteNode;

        a->next = b;

        size = size - 1;
        UniformIndexes();

        a = nullptr;
        b = nullptr;
        delete a;
        delete b;
      }
    }

    void Print(){
      Node<T>* temp = head;
      while(temp != nullptr){
        std:: cout << temp->data << std:: endl;
        temp = temp->next;
      }
    }

    void PrintSize(){
      std:: cout << size << " is the size of the linked list" << std::endl;
    }

    void UniformIndexes(){
      auto temp = head;
      unsigned int newIndex = 0;

      while(temp != nullptr){
        temp->SetIndex(newIndex);
        newIndex = newIndex + 1;
        temp = temp->next;
      }

      temp = nullptr;
      delete temp;
    }
    size_t Size() { return size; }
    void SetSize(size_t s) { size = s; }
    Node<T>* GetHead(){ return head; }
    Node<T>* GetTail(){ return tail; }
  protected:
    
  private:
    Node<T>* head;
    Node<T>* tail;

    size_t size;
};
