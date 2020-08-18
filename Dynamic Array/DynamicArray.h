#include <iostream>

template<typename T>
class DynamicArray{
  private:
    unsigned int size;
    size_t capacity;
    T* arr;
  public:
    DynamicArray(){ 
      capacity = 2;
      arr = new T[capacity];
      size = 0;
    }

    void PushBack(T value){

      if(size == capacity){
        //std:: cout << "increased capacity" << std::endl;
        capacity = capacity + capacity/2;
        T* newArr = new T[capacity];
        for(int i = 0; i < size; i++){
          newArr[i] = arr[i];
        }

        arr = newArr;
      }
      
      arr[size] = value;
      size++;
    } 

    void PopBack(){
      arr[size] = 0;
      size = size - 1;
      capacity = size;
    }

    void RemoveAt(unsigned int index){
      if(index > size){
        std:: cout << "cannot delete an index outside of range" << std:: endl;
        return; 
      }

      if(index == size){
        PopBack();
        return;
      }

      T* newArr = new T[size - 1];
      int j = 0;
      for(int i = 0; i < size; i++){
        if(i == index){
          j--;
        } else {
          newArr[j] = arr[i];
        }
        j++;
      }
      arr = newArr;
      size = size - 1;
      capacity = size;
    }

    void InsertAt(unsigned int index, T value){
      if(index > size){
        std::cout << "cannot insert to a not existing index" << std:: endl;
        return;
      }

      T* newArr = new T[size + 1];
      int i = 0;
      for(i; i < index; i++){
        newArr[i] = arr[i];
      }
      newArr[index] = value;
      i++;
      for(i; i < size + 1;i++){
        newArr[i] = arr[i - 1];
      }

      arr = newArr;
      size = size + 1;
      capacity = size;
    }

    void Display(){
      for(int i = 0; i < size; i++){
        std:: cout << arr[i] << std:: endl;
      }
    }

    unsigned int Size(){
      return size;
    }

    void Set(unsigned int index, T value){
      arr[index] = value;
    }

    bool isEmpty(){ 
      return size == 0;
    }

    size_t Capacity(){
      return capacity;
    }
};