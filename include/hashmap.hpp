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
  toolkit::pair<K, V>::pair(const K& key, V value){
    key_ = key;
    value_ = value;
  }

  template<typename K, typename V>
  bool toolkit::pair<K, V>::matchKey(K key) const{
    return key == key_;
  }

  template<typename K, typename V>
  V& toolkit::pair<K, V>::value(){
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
      numKeys_ = 0;
  }

  template<typename K, typename V>
  void toolkit::hashmap<K, V>::put(const K& key, const V& value){
    data_[(hash_)(key)%size_].add(pair<K, V>(key, value));
    numKeys_++;
  }

  template<typename K, typename V>
  V& toolkit::hashmap<K, V>::get(const K& key){
    for (int i = 0; i<data_[(hash_)(key)%size_].size(); i++){
      if (data_[(hash_)(key)%size_].get(i).matchKey(key)){
        return data_[(hash_)(key)%size_].get(i).value();
      }

    }
    throw 0;
  }

  template<typename K, typename V>
  bool toolkit::hashmap<K, V>::contains(const K& key) const{
    for (int i = 0; i<data_[(hash_)(key)%size_].size(); i++){
      if (data_[(hash_)(key)%size_].get(i).matchKey(key)){
        return true;
      }
    }
    return false;
  }

  template<typename K, typename V>
  toolkit::hashmap<K, V>::~hashmap(){
    delete[] data_;
  }

  template<typename K, typename V>
  bool toolkit::hashmap<K, V>::remove(const K& key){
    unsigned long long index = (hash_)(key)%size_;
    for (int i = 0; i<data_[index].size(); i++){
      if (data_[index].get(i).matchKey(key)){
        data_[index].remove(i);
        numKeys_--;
        return true;
      }
    }
    return false;
  }

  template<typename K, typename V>
  bool toolkit::hashmap<K, V>::replace(const K& key, const V& value){
    unsigned long index = (hash_)(key)%size_;
    for (int i = 0; i<data_[index].size(); i++){
      if (data_[index].get(i).matchKey(key)){
        data_[index].get(i) = pair<K, V>(key, value);
        return true;
      }
    }
    return false;
  }

  template<typename K, typename V>
  unsigned long long toolkit::hashmap<K, V>::size(){
    return numKeys_;
  }

  template<typename K, typename V>
  bool toolkit::hashmap<K, V>::isEmpty(){
    return numKeys_>0;
  }

}

#endif
