#include <iostream>

template<typename T>
class FenwickTree_WF{
  public:

    FenwickTree_WF(T* array, size_t s)
    {
      size = s + 1;
      tree = new T[size];

      for(unsigned int i = 1; i < size; i++){
        tree[i] = array[i - 1];
      }

      for(unsigned int i = 1; i < size; i++){
        int j = i + LSB(i);
        if(j < size){
          tree[j] = tree[j] + tree[i];
        }
      }
    }

    T PrefixSum(unsigned int index){
      T sum = 0;

      while(index != 0){
        sum += tree[index];
        index = index - LSB(index);
      }

      return sum;
    }

    T RangeQuery(unsigned int i, unsigned int j){
      return PrefixSum(i) - PrefixSum(j);
    }

    void PointUpdate(unsigned int index, T value){
      while(index < size){
        tree[index] = tree[index] + value;
        index = index + LSB(index);
      }
    }

    void PrintTree() const {
      for(unsigned int i = 1; i < size; i++){
        std:: cout << tree[i] << std:: endl;
      }
    }

  private:
    unsigned int LSB(unsigned int i){ return i & (-i); }
  private:
    T* tree;
    size_t size;
};