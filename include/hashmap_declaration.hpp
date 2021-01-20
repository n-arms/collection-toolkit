#ifndef HASHMAP_DEC_H
#define HASHMAP_DEC_H
#include <string>
#include "linkedlist.hpp"

namespace toolkit{
  unsigned long long hash_string(const std::string& s) ;
  unsigned long long hash_char(const char& c) ;

  template<typename K, typename V>
  class pair{
  private:
    K key_;
    V value_;
  public:
    pair(const K& key, V value) ;
    bool matchKey(K key) const;
    V& value();
    bool operator==(const pair<K, V>& other) const;
  } ;

  template<typename K, typename V>
  class hashmap{
  private:
    linkedlist<pair<K, V>>* data_ = NULL;
    unsigned long long (*hash_)(const K&);
    unsigned long long size_;
  public:
    hashmap(unsigned long long (*hash)(const K&), unsigned long long size) ;
    ~hashmap() ;
    void put(const K& key, const V& value) ;
    V& get(const K& key) ;
    bool contains(const K& key) const ;
    bool remove(const K& key) ;
    bool replace(const K& key, const V& value) ;
  } ;
}



#endif
