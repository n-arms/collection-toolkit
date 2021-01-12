#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "linkedlist_declaration.hpp"
#include <iostream>
namespace toolkit{
    template<typename T>
    listnode<T>::listnode(const T& value){
        value_ = value;
    }

    template<typename T>
    void listnode<T>::setnext(listnode<T>* next){
        next_ = next;
    }

    template<typename T>
    listnode<T>* listnode<T>::next() const{
        return next_;
    }

    template<typename T>
    T& listnode<T>::get(unsigned long index){
        return ((index==0L) ? value_ : next_->get(index-1L));
    }

    template<typename T>
    const T& listnode<T>::value() const{
        return value_;
    }

    template<typename T>
    const long listnode<T>::find(const T& element, unsigned long index) const{
      if (element==value_){
        return index;
      }
      else if (next_ != NULL){
        return next_->find(element, index+1);
      }else{
        return -1;
      }
    }

    template<typename T>
    void listnode<T>::print() const{
      std::cout << value_;
      if (next_ != NULL){
        std::cout << ", ";
        next_->print();
      }
    }

    template<typename T>
    listnode<T>::~listnode(){
      if (next_ != NULL){
        delete next_;
      }
    }

    template<typename T>
    void listnode<T>::remove(unsigned long index){
      if (index == 1){
        listnode<T>* old_ptr = next_;
        next_ = old_ptr->next();
        old_ptr->setnext(NULL);
        delete old_ptr;
      }else{
        next_->remove(index-1);
      }
    }

    template<typename T>
    void linkedlist<T>::add(T element){
      listnode<T>* old_ptr = first_;
      first_ = new listnode<T>(element);
      first_->setnext(old_ptr);
      size_++;
    }

    template<typename T>
    T& linkedlist<T>::get(unsigned long index){
      return first_->get(index);
    }

    template<typename T>
    const unsigned long& linkedlist<T>::size() const {
      return size_;
    }

    template<typename T>
    long linkedlist<T>::find(const T& element) const{
      return first_->find(element, 0);
    }

    template<typename T>
    void linkedlist<T>::print() const{
      first_->print();
      std::cout << std::endl;
    }

    template<typename T>
    linkedlist<T>::~linkedlist(){
      if (first_ != NULL)
      delete first_;
    }

    template<typename T>
    listnode<T>* linkedlist<T>::first(){
      return first_;
    }

    template<typename T>
    void linkedlist<T>::remove(unsigned long index){
      size_--;
      first_->remove(index);
    }
}

#endif
