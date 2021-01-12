#ifndef HASHMAP_DEC_H
#define HASHMAP_DEC_H
#include <string>
#include "linkedlist.hpp"

namespace toolkit{
  unsigned long long hash_string(const std::string& s) ;

  class hashmap{
  private:
    linkedlist<int>* first_ = NULL;
  } ;
}



#endif
