#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "arraylist_declaration.hpp"
#include <iostream>

namespace toolkit{
  template<typename T>
  void arraylist<T>::add(const T& element){
    if (capacity_==0){
      data_ = new T[1];
      capacity_=1;
      data_[0] = element;
      size_++;
      return;
    }else if (capacity_==size_){
      T* old_ptr = data_;
      capacity_*=2;
      data_ = new T[capacity_];
      for (int i = 0; i<size_; i++){
        data_[i] = old_ptr[i];
      }
      data_[size_] = element;
      size_++;
      return;
    }else{
      data_[size_] = element;
      size_++;
    }
  }

  template<typename T>
  const T& arraylist<T>::operator[](unsigned long index) const{
    if (index < size_){
      return data_[index];
    }
    throw 0;
  }


}

#endif
