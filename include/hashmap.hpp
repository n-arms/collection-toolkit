#ifndef HASHMAP_H
#define HASHMAP_H
#include "hashmap_declaration.hpp"
#include "linkedlist.hpp"
#include <string>
#include <cmath>

unsigned long long toolkit::hash_string(const std::string& s){
  unsigned long long total = 0;
  short p = 31;
  unsigned long long m = 0x3B9ACA09;
  for (int i = 0; i<s.size(); i++){
    total += int(s[i])*std::pow(p, i);
  }
  return total%m;
}

template<typename K, typename V>
hashmap<K, V>::hashmap(unsigned long long (*hash)(K), unsigned long long size){
    hash_ = hash;
    size_ = size;
}

template<typename K, typename V>




#endif
