#ifndef HASHMAP_DEC_H
#define HASHMAP_DEC_H
#include <string>
#include "linkedlist.hpp"

namespace toolkit{
  unsigned long long hash_string(const std::string& s) ;

  template<typename K, typename V>
  class pair{
  private:
    K key_;
    V value_;
  public:
    pair() ;
    bool matchKey(const K& key) const;
    V& value() const;
  } ;

  template<typename K, typename V>
  class hashmap{
  private:
    linkedlist<pair<K, V>>* data_ = NULL;
    unsigned long long (*hash_)(K);
    unsigned long long size_;
  public:
    hashmap(unsigned long long (*hash)(K), unsigned long long size) ;
    void put(const K& key, const V& value) ;
    V& get(const K& key) ;
  } ;
}



#endif
