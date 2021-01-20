#ifndef HASHMAP_H
#define HASHMAP_H
#include "hashmap_declaration.hpp"
#include "linkedlist.hpp"
#include <string>
#include <cmath>

namespace toolkit{

  unsigned long long hash_string(const std::string& s){
    unsigned long long total = 0;
    short p = 31;
    unsigned long long m = 0x3B9ACA09;
    for (int i = 0; i<s.size(); i++){
      total += int(s[i])*std::pow(p, i);
    }
    return total%m;
  }

  unsigned long long hash_char(const char& c){
    return int(c);
  }

  template<typename K, typename V>
  toolkit::pair<K, V>::pair(const K& key, const V& value){
    key_ = key;
    value_ = value;
  }

  template<typename K, typename V>
  bool toolkit::pair<K, V>::matchKey(const K& key) const{
    return key = key_;
  }

  template<typename K, typename V>
  V& toolkit::pair<K, V>::value() const{
    return value_;
  }

  template<typename K, typename V>
  bool toolkit::pair<K, V>::operator==(const pair<K, V>& other) const{
    return (value_==other.value()) && other.matchKey(key_);
  }

  template<typename K, typename V>
  toolkit::hashmap<K, V>::hashmap(unsigned long long (*hash)(const K&), unsigned long long size){
      hash_ = hash;
      size_ = size;
      data_ = new toolkit::linkedlist<toolkit::pair<K, V>>[size_];
  }

  template<typename K, typename V>
  void toolkit::hashmap<K, V>::put(const K& key, const V& value){
    data_[(hash_)(key)%size_].add(pair<K, V>(key, value));
  }

}

#endif
