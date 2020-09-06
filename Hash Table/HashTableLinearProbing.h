#include <functional>
#include <iostream>
// TODO: Add Remove function

template<typename K, typename V>
class Entry_LP{
  public:
    Entry_LP(){
    
    }

    Entry_LP(K key, V value)
      : key(key), value(value){
        std::hash<K> hashK;
        hash = hashK(key);
      }

    K key;
    V value;
    size_t hash;
};

template<typename K, typename V>
class HashTableLinearProbing{
  public:
    HashTableLinearProbing(unsigned int capacity, unsigned int linear)
      : capacity(capacity), loadfactor(0.35), linear(linear)
      {
        treshold = (unsigned int) (capacity * loadfactor);
        table = new Entry_LP<K,V>*[capacity];
        size = 0;
        for(int i = 0; i < capacity; i++){
          table[i] = NULL;
        }
      }

    HashTableLinearProbing(unsigned int capacity, double loadfactor, unsigned int linear)
      : capacity(capacity), loadfactor(loadfactor), linear(linear)
      {
        treshold = (unsigned int) (capacity * loadfactor);
        table = new Entry_LP<K,V>*[capacity];
        size = 0;
        for(int i = 0; i < capacity; i++){
          table[i] = NULL;
        }
      }
    
    void Insert(K key, V value){
      Entry_LP<K,V>* newEntry = new Entry_LP<K,V>(key, value);

      if(treshold == size){
        // resize the table
        unsigned int prevCapacity = capacity;
        capacity = capacity * 2;
        treshold = capacity * loadfactor;
        Entry_LP<K,V>** newTable = new Entry_LP<K,V>*[capacity];
        // set the every index of new table to null
        for(int i = 0; i < capacity; i++){
          newTable[i] = NULL;
        }
        unsigned int x = 0;
        size_t index = hashIndex(newEntry->hash);

        for(int i = 0; i < prevCapacity; i++){
          if(table[i] == NULL){

          } else {
            while(newTable[index] != NULL){
              index = (newEntry->hash + Probing(x)) % capacity;
              x = x + 1;  
            }
            x = 0;
            newTable[index] = table[i];
          }
        }

        //set the table to the new table;
        table = newTable;

        //insert again
        while(table[index] != NULL){
          index = (newEntry->hash + Probing(x)) % capacity;
          x = x + 1;
        }

        table[index] = newEntry;
      } else {
        unsigned int x = 0;
        size_t index = hashIndex(newEntry->hash);

        while(table[index] != NULL){
          index = (newEntry->hash + Probing(x)) % capacity;
          x = x + 1;
        }
        table[index] = newEntry;
      }

      size = size + 1;
    }

    void Search(K key){
      std::hash<K> hashK;
      size_t hashkey = hashK(key);
      unsigned int index = hashIndex(hashkey);
      unsigned int x = 0;

      while(table[index] != NULL){
        if(table[index]->key == key){
          std:: cout << table[index]->key << " -- " << table[index]->value << std:: endl;
          return;
        } else if(x + 1 > capacity){
          std:: cout << "cannot found the index" << std:: endl;
          return;
        } else {
          index = (hashkey + Probing(x)) % capacity;
          x = x + 1;
        }
      }
      std:: cout << "cannot found the key" << std:: endl;
    }

    void Display(){
      for(int i = 0; i < capacity; i++){
        if(table[i] != NULL){
          std::cout << i << " : " << table[i]->key << " -- " << table[i]->value << std:: endl;
        } else{
        }
      }
    }

    unsigned int Capacity() const { return capacity; }
    size_t Size() const { return size; }
    unsigned int Treshold() const { return treshold; }
  private:
    size_t Probing(unsigned int x){
      return linear * x;
    }

    unsigned int hashIndex(size_t hash){
      return hash % capacity;
    }
  private:
    Entry_LP<K,V>** table;
    unsigned int capacity;
    double loadfactor;
    unsigned int linear;
    unsigned int treshold;
    size_t size;
};