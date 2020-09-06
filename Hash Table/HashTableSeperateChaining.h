#include <functional>
#include <iostream>
#include <typeinfo>
#include <list>
#include <String>

template<typename K, typename V>
class Entry{
  public:
    Entry(){

    }
    Entry(K key, V value)
      : key(key),
        value(value)
      {
        std::hash<K> hashK;
        hash = hashK(key);
      }
    
    bool operator==(const Entry& other){
      if(this->hash == other.hash){
        return true;
      } else {
        return false;
      }
    }

    void Display(){
      std::cout << key << " -- " << value << std::endl;
    }
    
    void Remove(){
      key = NULL;
      value = NULL;
    }
  public:
    K key;
    V value;
    size_t hash;
};

template<typename K, typename V>
class HashTableSeperateChaining{
  public:
    HashTableSeperateChaining(){
      size = 0;
      capacity = 4;
      collections = new std::list<Entry<K,V>>[capacity];
    }

    HashTableSeperateChaining(unsigned int capacity)
      : capacity(capacity)
    {
      collections = new std::list<Entry<K,V>>[capacity];
      size = 0;
    }
    
    void Insert(K key, V value){
      std::list<Entry<K,V>> newList;
      Entry<K,V> newEntry(key, value);
      unsigned int index = HashMod(newEntry.hash);

      if(collections[index].empty()){
        newList.push_back(newEntry);
        collections[index] = newList;
      } else {
        collections[index].push_back(newEntry);
      }
      size = size + 1;
    }

    void Lookup(K key){
      std::hash<K> hashK;
      size_t hash = hashK(key);
      unsigned int index = HashMod(hash);

      for(auto e : collections[index]){
        if(e.key == key){
          std:: cout << e.key << " -- " << e.value << std:: endl;
        }
      }
    }

    void Remove(K key){
      std::hash<K> hashK;
      size_t hash = hashK(key);
      unsigned int index = HashMod(hash);

      auto i = collections[index].begin();
      for(; i != collections[index].end(); i++){
        if(i->key == key){
          std::cout << "break" << std:: endl;
          break;
        }
      }

      if(i != collections[index].end())
        collections[index].erase(i);
    }

    void Display(){
      for(unsigned int i = 0; i < capacity; i++){
        std:: cout << "Index : " << i << std:: endl;
        for(auto e : collections[i]){
          e.Display();
        }
      }
    }
  private:
    unsigned int HashMod(size_t hash){
      return hash % capacity;
    }
  private:
    std::list<Entry<K,V>>* collections;
    unsigned int capacity;
    size_t size;
};