#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "linkedlist_declaration.hpp"
#include <iostream>


namespace toolkit{
    template<typename T>
    toolkit::listnode<T>::listnode(const T& value){
        value_ = new T(value);
    }

    template<typename T>
    void toolkit::listnode<T>::setnext(listnode<T>* next){
        next_ = next;
    }

    template<typename T>
    listnode<T>* toolkit::listnode<T>::next() const{
        return next_;
    }

    template<typename T>
    T& toolkit::listnode<T>::get(unsigned long index){
        return ((index==0L) ? *value_ : next_->get(index-1L));
    }

    template<typename T>
    const T& toolkit::listnode<T>::value() const{
        return *value_;
    }

    template<typename T>
    const long toolkit::listnode<T>::find(const T& element, unsigned long index) const{
      if (element==*value_){
        return index;
      }
      else if (next_ != NULL){
        return next_->find(element, index+1);
      }else{
        return -1;
      }
    }

    template<typename T>
    void toolkit::listnode<T>::print() const{
      std::cout << *value_;
      if (next_ != NULL){
        std::cout << ", ";
        next_->print();
      }
    }

    template<typename T>
    toolkit::listnode<T>::~listnode(){
      if (next_ != NULL){
        delete next_;
      }
      delete value_;
    }

    template<typename T>
    void toolkit::listnode<T>::remove(unsigned long index){
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
    void toolkit::linkedlist<T>::add(T element){
      listnode<T>* old_ptr = first_;
      first_ = new listnode<T>(element);
      first_->setnext(old_ptr);
      size_++;
    }

    template<typename T>
    T& toolkit::linkedlist<T>::get(unsigned long index){
      return first_->get(index);
    }

    template<typename T>
    const unsigned long& toolkit::linkedlist<T>::size() const {
      return size_;
    }

    template<typename T>
    long toolkit::linkedlist<T>::find(const T& element) const{
      return first_->find(element, 0);
    }

    template<typename T>
    void toolkit::linkedlist<T>::print() const{
      if (first_!=NULL)
      first_->print();
      std::cout << std::endl;
    }

    template<typename T>
    toolkit::linkedlist<T>::~linkedlist(){
      if (first_ != NULL)
      delete first_;
    }

    template<typename T>
    listnode<T>* toolkit::linkedlist<T>::first(){
      return first_;
    }

    template<typename T>
    void toolkit::linkedlist<T>::remove(unsigned long index){
      size_--;
      if (index==0){
        if (size_<=0){
          listnode<T>* old_ptr = first_;
          first_ = NULL;
          delete first_;
        }else{
          listnode<T>* old_ptr = first_;
          first_ = first_->next();
        }
      }else{
        first_->remove(index);
      }
    }
}

#endif
