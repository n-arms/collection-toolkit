#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "linkedlist_declaration.hpp"
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
    listnode<T>* listnode<T>::next(){
        return next_;
    }

    template<typename T>
    T& listnode<T>::get(unsigned long index){
        return ((index==0L) ? value_ : next_->get(index-1L));
    }

    template<typename T>
    T& listnode<T>::value(){
        return *value_;
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

}

#endif
