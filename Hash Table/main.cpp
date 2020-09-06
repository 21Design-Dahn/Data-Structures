#include <iostream>
#include <String>
#include <typeinfo>
#include "HashTableSeperateChaining.h"
#include "HashTableLinearProbing.h"
#include "HashTableQuadraticProbing.h"
#define LOG(x) std:: cout << x << std::endl

int main(){
  HashTableLinearProbing<std::string, std::string> table(12, 0.35, 5);
  
  table.Insert("fatty", "sdfas");
  table.Insert("jumbo", "asdfasaa");
  table.Insert("jumbo", "asdfasaa");
  table.Insert("jumbo", "aaa");
  table.Display();

  table.Insert("mumbo", "saaaa");
  table.Search("mumbo");

  LOG(table.Treshold());
  LOG(table.Capacity());
  LOG(table.Size());
  table.Display();
  // HashTableSeperateChaining<std::string, std::string> table;
  // table.Insert("dumbo", "dsdgsd");
  // table.Insert("fatty", "asdfa");
  
  // table.Lookup("fatty");
  // table.Display();
  // table.Remove("fatty");
  // table.Display();

  // std::string str = "asdfasfda";
  // std::string str1 = "asdfasfda";

  // const char* char1 = "asdfasdfa";
  // const char* char2 = "dfafa";
  // auto type = typeid(std::string).name();
  // LOG(type);

  // if(typeid(str).name() == type){
  //   LOG("true");
  // }

  std:: cin.get();
}