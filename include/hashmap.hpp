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





#endif
