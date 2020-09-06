#include <vector>

template<typename T>
class Node{
  public:
  
  Node(T value)
    : value(value){

    }

  Node& operator!=(const Node<T>& other){
    return *this != other;
  }
  T value;
};

template<typename T>
class BinaryHeap{
  public:
    BinaryHeap()
    {}

    void Insert(T value){
      Node<T> newNode(value);
      unsigned int index = collections.size();
      collections.push_back(newNode);


      while(index != 0 && newNode.value < collections[parent(index)].value){
        // if the parent node is bigger than the input swap them
        // set the indexing to parent in case of swimming again to the top
        swap(collections, index, parent(index));
        index = parent(index);
      }
    }

    void Poll(){
      // swap to the last to the root and delete the last element(root)
      // then sink the root element
      swap(collections, 0, collections.size() - 1);
      collections.pop_back();

      unsigned int index = 0;
      auto smallest = smallestN(collections[left(index)], collections[right(index)]);
      
      while(collections[index].value > smallest.value && smallest.value > 1){
        if(smallest.value == collections[left(index)].value){
          swap(collections, index, left(index));
          index = left(index);
        } else if (smallest.value == collections[right(index)].value){
          swap(collections, index, right(index));
          index = right(index);
        }

        smallest = smallestN(collections[left(index)], collections[right(index)]);
      }
    }

    void Delete(T value){
      // search for the index position of value
      unsigned int searchIndex = 0;
      for(; searchIndex < collections.size(); searchIndex++){
        if(collections[searchIndex].value == value){
          break;
        }
        if(searchIndex == collections.size() - 1){
          std:: cout << "cannot find the number you input" << std:: endl;
          return;
        }
      }

      //swap the index position to last index
      swap(collections, searchIndex, collections.size() - 1);
      collections.pop_back();
      // swim or sink
      sinkorswim(searchIndex);
    }
  private:
    void sinkorswim(unsigned int index){

      if(collections[index].value < collections[parent(index)].value){
        // this is swim

        while(index != 0 && collections[index].value > collections[parent(index)].value){
          swap(collections, index, parent(index));
          index = parent(index);
        }
        
      } else if(collections[index].value > collections[parent(index)].value){
        // this is sink
        // check for left and right
        auto smallest = smallestN(collections[left(index)], collections[right(index)]);

        while(collections[index].value > smallest.value && smallest.value > 1){
          if(smallest.value == collections[left(index)].value){
            swap(collections, index, left(index));
            index = left(index);
          } else if (smallest.value == collections[right(index)].value){
            swap(collections, index, right(index));
            index = right(index);
          }

          smallest = smallestN(collections[left(index)], collections[right(index)]);
        }
      }
    }
    void swap(std::vector<Node<T>>& v, int i, int j){
      auto temp = v[i];
      v[i] = v[j];
      v[j] = temp;
    }
    unsigned int smallest(unsigned int a, unsigned int b){
      if(a > b){
        return b;
      } else if (a < b){
        return a;
      } else {
        return NULL;
      }
    }
    Node<T> smallestN(Node<T> a , Node<T> b){
      if(a.value > b.value){
        return b;
      } else if( b.value < a.value){
        return a;
      }
    }
    unsigned int parent(unsigned int index){
      return (index - 1) / 2;
    }
    unsigned int left(unsigned int index){
      return (2 * index) + 1;
    }
    unsigned int right(unsigned int index){
      return (2 * index) + 2;
    }
    size_t Size() const { return collections.size(); }
  private:
    std::vector<Node<T>> collections;
};