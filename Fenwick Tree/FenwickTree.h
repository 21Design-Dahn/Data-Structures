#include <iostream>

template<typename T>
class FenwickTree{
  public:
    FenwickTree(T* array, size_t count)
      : sum(0)
    {
      size = count + 1;
      collections = new T[count];

      for(unsigned int i = 0; i < count; i++){
        collections[i] = 0;
      }

      for(unsigned int i = 0; i < count; i++){
        collections[i] = array[i];
      }

      tree = new T[size];
      for(unsigned int i = 0; i < size; i++){
        tree[i] = 0;
      }

      for(unsigned int i = 0; i < count; i++){
        Update(collections, count, i, collections[i]);
      }
    }

    void Update(T* array, unsigned int n, unsigned int index, T value){
      index = index + 1;

      while(n >= index){
        tree[index - 1] += value;

        index += index & (-index);
      }
    }

    T GetSum(unsigned int index){
      index = index + 1;

      while(index > 0){
        sum += tree[index - 1];

        index -= index & (-index);
      }
      
      return sum;
    }

    void Print() const{
      for(unsigned int i = 0; i < size - 1; i++){
        std:: cout << tree[i] << std:: endl;
      }
    }

  private:
    T* collections;
    T* tree;
    size_t size;
    T sum;
};